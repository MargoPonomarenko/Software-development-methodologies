# Quadratic Equation Solver

Application for solving quadratic equations of the form ax2+bx +c = 0.

## How to build and run a project

To compile your program, execute:

```bash
cl /EHsc <file-name>.cpp
```
The cl.exe compiler generates an .obj file that contains the compiled code, and then runs the linker to create an executable program named <file-name>.exe.

To run the hello.exe program, at the command prompt, enter:
```bash
<file-name>
```

## Instructions to run in Visual Studio

1. Clone repository;
2. Do Terminal > Run Build Task > C/C++: g++.exe build active file;
3. Write in terminal ".\<file-name>"

## File format description

File example:
```
12 45 1 0
```
There must be a `\n` character at the end of each line.

## Revert commit
SHA of a revert commit: `26ef05f`.