
LIBC ?= /opt/diet/lib-x86_64/libc.a
obj  = $(patsubst src/%.c,%.o,$(wildcard src/*.c))
headers = src/scalp.h config.h
mobj = scalp.o itoa.o $(obj)
tobj = test/test.o itoa.o $(obj)

CFLAGS += -Wall
LDFLAGS ?= -static
LDFLAGS += -s -z norelro -z noseparate-code
LD ?= ld

build: scalp

check: test/test
	@cd test/ ; ./test

config.h: config.def.h
	cp -i config.def.h config.h
	@echo "To change the configuration, edit config.h"

config: config.h

itoa.o: src/Itoa
	make -C src/Itoa
	ln -f src/Itoa/itoa.o itoa.o

scalp.o test/test.o $(obj): %.o: src/%.c $(headers)
	$(CC) -c -o $@ $<

scalp: $(mobj) $(LIBC)
	@echo $(obj)
	$(LD) $(LDFLAGS) -o $@ $^

test/test: $(tobj) $(LIBC)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f scalp test/test *.o test/*.o Itoa/itoa.o
	rm -i config.h

install: scalp
	install scalp /usr/bin/
	install scalp.1 /usr/share/man/man1/

.PHONY: config build check install clean

all: build check install clean
