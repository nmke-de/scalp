
LIBC = /usr/lib/libc.a

build: scalp

scalp: scalp.o read_file.o notify_send.o $(LIBC)
	ld -static -s -z norelro -z noseparate-code -o $@ $^

clean:
	rm scalp
	rm *.o

