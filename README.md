# scalp

**scalp** is a simple calendar program that actually only notifies you on certain events. Some people will not call this a calendar program, but a reminder / agenda / todo-list program.

Currently in early development.

## But why?

All the other calendar programs are too complicated.

## What about the name?

**S**imple **CAL**endar **P**rogram.

## Dependencies

- libc, preferrably statically linked (I tested against the [dietlibc](https://www.fefe.de/dietlibc))
- C compiler
- `notify-send` (may be included in the package `libnotify`)

The program is known to work on Artix Linux. Make sure to put your `libc.a` in `/usr/lib` or change the Makefile.

## Build

Type `make`.

## Usage

Run `./scalp`. Make sure to have a file `foo` in the current working directory.

The program will read from a file `foo` that has the same format as the file `foo` in the repository. The first line contains the number of entries to be read (but I intend to remove this line in future versions). After that, each line contains a number, representing the number of seconds since Unix Epoch (1st Jan 1970 1am), a separating character (usually a tab, never a digit) and a string of maximally 512 characters, representing the message to be displayed. The program will notify the user with the message once the specified time arrives.

Adding a date in the required format should be easy with something like `date -d "17 May 2023 4:32pm" "+%s"`.

