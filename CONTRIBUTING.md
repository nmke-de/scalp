# A Guide to contributions

**CONTRIBUTIONS ARE WELCOME!**

## Where do I ask questions?

Open an issue on Github. Check whether your question has been asked before.

## How do I report a bug?

Open an issue on Github. Check whether your bug has been reported before.

## How do I request a feature?

Open an issue on Github. Check whether your feature has been requested before. Also, keep in mind that your feature does not complicate the program significantly, or could be solved by an external program.

## How do I contribute to the codebase?

1. Fork this repository.
2. Make changes to your fork.
3. Create a pull request.

Here are a few (soft) guidelines for the code structure:

### General

Use Unix linefeeds (`\n`) instead of Windows linefeeds (`\n\r`).

End a file with a trailing newline.

Don't create new dependencies, unless it is unavoidable.

As long as there is no coding style, try to immitate the style of existing files.

### C

Create a new file for each function, and leave a signature in [scalp.h](scalp.h).

Indent using tabs.

Avoid `*printf` and `*scanf`. To convert from string to number, use `atoi` or similar. To convert from number to string, use [Itoa](https://github.com/nmke-de/Itoa).

[WIP]

### Markdown

Use English. [WIP]

### Shell scripts

Avoid bash-specific syntax ("bashisms") and stick to POSIX standards.

Indent using tabs.
