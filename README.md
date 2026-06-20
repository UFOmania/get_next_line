# get_next_line

A function that reads a file descriptor line by line.

## About

The purpose of this project is to implement a function capable of reading and returning one line at a time from a file descriptor, regardless of the size of the file.

This project introduces static variables, buffer management, memory allocation, and efficient file reading in C.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Features

* Reads from any valid file descriptor
* Returns one line per call
* Handles files of any size
* Preserves unread data between calls
* Stops at EOF
* Returns `NULL` on error or end of file

## Build

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove generated files:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

## Usage

Include the header:

```c
#include "get_next_line.h"
```

Example:

```c
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile with:

```bash
cc main.c get_next_line.c get_next_line_utils.c
```

## Project Structure

```text
get_next_line/
├── bonus/
    ├── get_next_line_utils_bonus.c
    ├── get_next_line_bonus.c
    ├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

## Learning Objectives

* Static variables
* File descriptors
* Dynamic memory allocation
* Buffer management
* String manipulation
* Memory leak prevention

