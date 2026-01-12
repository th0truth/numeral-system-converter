# Numeral System Converter

A lightweight Numeral System Converter written in C that converts numbers from any base to any base.
The project is designed to be simple, portable, and educational, demonstrating base conversion logic and modular C project structure.

## Features

- Convert numbers between arbitrary numeral bases
- Supports common bases:
  - Binary (base 2)
  - Octal (base 8)
  - Decimal (base 10)
  - Hexadecimal (base 16)

- Written in pure C
- Modular project structure (Src, Inc, Build)
- Simple Makefile-based build system


## Project Structure

```bash
  .
  ├── Build /   # Build output (generated) 
  ├── Inc /     # Header files
  ├── Src /     # Source files
  ├── main.c
  ├── Makefile
  └── README.md
```


## Build Requirements

- GCC (or compatible C compiler)
- GNU Make

# Build Instructions

To compile the project, run:

```bash
make
```

This will:

- Create the Build/ directory (if it does not exist)
- Compile all .c source files
- Generate the executable:


```bash
Build/main.o
```

# Running the Program

After building, run the program with:

```bash
./Build/main.o
```

# Clean

To remove build files:

```bash
make clean
```

# License

This project is provided for educational and personal use.
You may modify and distribute it freely.