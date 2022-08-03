
LIBC = /usr/lib/libc.a
obj  = read_file.o notify_send.o
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

clean: scalp test/test
	rm scalp
	rm test/test
	rm *.o
	rm test/*.o

all: build check clean
