text_to_code by fd (buffers)''
## 🚀 Overview


Each call to `get_next_line()` returns **the next line** from the given file descriptor, including the newline character `\n` (if present).  
When the end of the file is reached or an error occurs, it returns `NULL`.

---

## ⚙️ Features

- 📂 Reads files **line by line**
- 🔁 Maintains **static buffer** between function calls
- 🧵 Supports **multiple file descriptors** simultaneously
- 💾 Manages **dynamic memory allocation** safely
- 🚫 No memory leaks, even with small buffer sizes

---

## 🧠 Concepts Covered

- Low-level file reading with `read()`
- Buffering and persistent data between function calls
- Memory allocation with `malloc()` and `free()`
- String manipulation (`ft_strjoin`, `ft_strlen`, etc.)
- Handling edge cases (EOF, empty files, large lines)

---

## 🧩 Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── main.c
└── Makefile
```

---

## 🔧 Usage

### 🔨 Compilation

Use the provided Makefile:

```bash
make
```

Or compile manually with a chosen buffer size:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42
```

> 💡 You can modify `BUFFER_SIZE` to test performance with different read chunk sizes.

---

### ▶️ Example

#### **file.txt**
```
Hello world
This is a test
42 Network
```

#### **main.c**
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

#### **Output**
```
Hello world
This is a test
42 Network
```

Each line is read and printed one by one until the end of the file.

---

## 🧰 Functions Implemented

- `get_next_line()` — reads and returns the next line from a file descriptor  
- Utility functions:
  - `ft_strlen`
  - `ft_strchr`
  - `ft_strjoin`
  - `ft_substr`
  - `ft_strdup`

---

## 🏁 Objectives

By completing **get_next_line**, you will:
- Master **file descriptor handling**
- Understand **static variables** and **state persistence**
- Improve **memory management** and **string manipulation**
- Write **efficient and clean C code**

---

## 🏆 Grade
✅ Project successfully completed at **42 Network**

---

## 📜 License
This project is released under the [MIT License](LICENSE).

---

### 👨‍💻 Author
**Ahmed Bahja (h3nix)**  
📧 [h3nix.42@gmail.com](mailto:h3nix.42@gmail.com)  
🐙 [GitHub: h3nix](https://github.com/h3nix)
