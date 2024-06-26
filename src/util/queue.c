#include "../include/queue.h"
#include "../include/memory.h"
#include "../include/graphics.h"
#include "../include/io.h"

Queue *create_queue() {
    Queue *queue = (Queue *) kmalloc(sizeof(Queue));
    queue->phead = NULL;
    queue->ptail = NULL;
    queue->size = 0;
    return queue;
}

void free_queue(Queue *queue) {
    QNode *cur = queue->phead;
    while (cur) {
        QNode *next = cur->next;
        kfree(cur);
        cur = next;
    }
    queue->phead = queue->ptail = NULL;
    kfree(queue);
}

void queue_push(Queue *pq, char x) {
    QNode *newnode = (QNode *) kmalloc(sizeof(QNode));//为新节点申请内存空间
    if (newnode == NULL) {
        printf("OUT_OF_MEMORY: The kernel memory out of.");
        io_cli();
        for (;;)io_hlt();
    }
    newnode->data = x;   //新节点储存数据
    newnode->next = NULL;//新节点的下一个指向NULL，即新节点作为队尾
    if (pq->phead == NULL)//将新节点入队
    {
        pq->phead = pq->ptail = newnode;
        pq->phead->next = newnode;
    } else {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
    pq->size++;
}

char queue_pop(Queue *pq) {
    if (pq->size == 0)return NULL;
    QNode *next = pq->phead->next;
    kfree(pq->phead);
    pq->phead = next;
    if (pq->phead == NULL) {
        pq->ptail = NULL;
    }
    pq->size -= 1;
    return next->data;
}



