
LIBC = /usr/lib/libc.a
obj  = read_file.o notify_send.o scalpd.o list.o timecompare.o add.o trigger_update.o
mobj = scalp.o $(obj)
tobj = test/test.o $(obj)

LDFLAGS += -static -s -z norelro -z noseparate-code

build: scalp

check: test/test
	@cd test/ ; ./test

scalp: $(mobj) $(LIBC)
	ld $(LDFLAGS) -o $@ $^

test/test: $(tobj) $(LIBC)
	ld $(LDFLAGS) -o $@ $^

clean:
	rm -f scalp test/test *.o test/*.o

install: scalp
	install scalp /usr/bin/

.PHONY: build check install clean

all: build check install clean
