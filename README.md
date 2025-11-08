text_file_to_memory aka (buffers)


get_next_line is a project from the 42 curriculum that focuses on creating a function capable of reading a file or standard input line by line, no matter the file size or line length.
It’s a fundamental exercise in file I/O, memory management, and buffer handling in C.

🚀 Overview

The goal of get_next_line is to implement the following function:

char *get_next_line(int fd);


This function reads from a file descriptor (fd) and returns the next line each time it’s called, including the newline character \n (except for the last line, if there’s no newline at the end).

Each call to get_next_line() should:

Remember its reading position between calls (persistent buffer),

Handle multiple file descriptors at the same time,

Efficiently manage memory allocation and freeing, and

Avoid leaks or undefined behavior.

⚙️ Key Concepts
🧠 Core Skills Learned

File descriptor operations (read())

Static variables and buffer persistence

Dynamic memory allocation with malloc() and free()

String manipulation (joining, slicing, copying)

Efficient memory handling and performance optimization

📦 Important Files

get_next_line.c → Main logic of reading and returning lines

get_next_line_utils.c → Helper functions (string join, length, etc.)

get_next_line.h → Function prototypes and BUFFER_SIZE definition

🔧 Function Behavior
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);

✅ Expected Behavior

Each call returns exactly one line until EOF is reached.

Returns NULL when the end of file is reached or on error.

Works even with very large files or tiny buffer sizes.

🧩 Project Structure
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── main.c
└── Makefile

⚙️ Compilation

Use the provided Makefile to compile:

make


Or compile manually:

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42


You can change BUFFER_SIZE to test different reading chunk sizes.

💡 Example Output

Given a file:

Hello world
This is a test
42 Network


Output:

Hello world
This is a test
42 Network


Each line is returned one by one per function call.

🏁 Objectives

By completing get_next_line, you learn to:

Understand low-level file reading,

Manage persistent data between function calls,

Avoid memory leaks, and

Write robust and efficient C code.
