OBJS_PACK = out/plreadln.obj out/plreadln_intellisense.obj out/plreadln_wordmk.obj

default : $(OBJS_PACK)
	ar rv ../libo/libplr.a $(OBJS_PACK)
out/%.obj : %.c Makefile
	gcc -m32 -I../include -nostdlib -fno-builtin -ffreestanding -fno-stack-protector -Qn -fno-pic -fno-pie -fno-asynchronous-unwind-tables -fomit-frame-pointer -march=pentium -O0 -w -c $*.c -o out/$*.obj
out/%.obj : %.cpp Makefile
	gcc -m32 -I../include -nostdinc -nostdlib -fno-builtin -ffreestanding -fno-stack-protector -Qn -fno-pic -fno-pie -fno-asynchronous-unwind-tables -fomit-frame-pointer -march=pentium -O0 -w -c $*.cpp -o out/$*.obj
out/%.obj : %.asm Makefile
	nasm -f elf $*.asm -o out/$*.obj
clean:
	rm out/*
	rm ../libo/libplr.a