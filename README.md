# scalp

**scalp** is a simple calendar program that actually only notifies you on certain events. Some people will not call this a calendar program, but a reminder / agenda / todo-list program.

Currently still in development.

## But why?

All the other calendar programs are too complicated.

## What about the name?

**S**imple **CAL**endar **P**rogram.

## Dependencies

- libc, preferrably statically linked (I tested against the [dietlibc](https://www.fefe.de/dietlibc))
- [Itoa](https://github.com/nmke-de/Itoa), which comes included as a git submodule in this repository.
- `notify-send` (may be included in the package `libnotify`)
- `date`, a utility which usually comes with GNU coreutils, busybox, sbase or whatever userspace you fancy.
- **Build dependencies**:
  - C compiler
  - make (I recommend GNU make)

The program is known to work on Artix Linux. Make sure to put your `libc.a` in `/usr/lib` or change the Makefile.

## Build

In order to fetch Itoa, type `git submodule update --init --remote` first. If you want to update this submodule, you need to type `git submodule update --remote` instead.

Type `make`. To install, type `make install`.

## Usage

Run `scalp [filename]` to receive notifications. Other than that,

- `scalp add [filename]` will start a prompt to add a new entry.
- `scalp change [filename]` will start a prompt to change the message of an existing entry.
- `scalp copy [filename]` will start a prompt to copy an existing entry to a new time.
- `scalp del [filename]` will start a prompt to delete an existing entry.
- `scalp help` will show a help message.
- `scalp list [filename]` will provide a list of known entries.
- `scalp move [filename]` will start a prompt to change the time of an existing entry.
- `scalp prune [filename]` will remove all entries older than now.
- `scalp update` will triger an update on all running instances of scalp, if any.

If no filename is provided, the program will assume `foo`.

The program will read from the given file that has the same format as the file `foo` in the repository.

## Format specification

Each line contains a number, representing the number of seconds since Unix Epoch (1st Jan 1970 12am UTC), a separating character (usually a tab, never a digit or a newline) and a string of maximally 512 characters, representing the message to be displayed.
The program will notify the user with the message once the specified time arrives.

For example, the following line is a valid entry for scalp:

``1660035600	Something happens!``

A formal grammar specifying the file format can be found [here](GRAMMAR).

Adding a date in the required format should be easy with a shell command like `echo -e "$(date -d "17 May 2023 4:32pm" "+%s")\tSend birthday regards!" >> foo`, or whatever your desired file is.

## Contributing

Take a look at [the contributing guidelines](CONTRIBUTING.md). If you have a question, feel free to ask in [the issues tab](https://github.com/nmke-de/scalp/issues).

## Acknowledgement

[CPtPoesn](https://github.com/CPtPoesn) for taking a look at the man page and making a suggestion for improvement.
