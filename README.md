# Primitive Recursive Functions

This repository contains the implementation of Primitive Recursive Functions in C++20. The project includes basic functions (Zero, Successor, Projection) and composite operators (Composition, Recursion) with an interactive shell for function execution.

The program provides predefined functions: addition, subtraction, multiplication, power, and predecessor.

## Project Structure
- `include/` - Header files organized in subdirectories
  - `functions/` - Core primitive recursive function classes
  - `interactive/` - Interactive menu and function registry
- `src/` - Implementation files
  - `functions/` - Function implementations
  - `interactive/` - Menu system implementation
- `build/` - Compiled files

## Compilation and Execution
To compile and run the program, follow these steps:

1. Ensure you have a C++ compiler installed (g++ or clang with C++20 support).
2. Navigate to the project directory.
3. Move to the `build` directory:
   ```bash
   cd build
   ```
4. Compile the project using CMake:
   ```bash
   cmake ..
   make
   ```
5. Run the interactive shell:
   ```bash
   ./prf
   ```

## Usage
Once the program is running, you can:
- Type `list` to see available functions
- Type `help` to see available commands
- Type a function name (e.g., `add`, `mult`) to execute it
- Type `quit` to exit

## Repository
https://github.com/EricRios-commits/PrimitiveRecursiveFunction.git
