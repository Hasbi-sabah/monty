# 0x19. C - Stacks, Queues - LIFO, FIFO

This project is a Monty Bytecode Interpreter is a project that allows you to interpret files
written in Monty Bytecode.
Monty is a simple programming language that utilizes a stack data structure for its operations.
This interpreter allows you to interpret the Monty bytecode file by specifying it as an argument.

## Usage
First you need to compile the project use this command to acheive that:
```
gcc *.c -o monty
```
To run the interpreter, execute the compiled binary and specify a Monty bytecode file as argument:
```
./monty [filename]
```

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
It relies on a unique stack, with specific instructions to manipulate it.
The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses
this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before
or after the opcode and its argument:
```
root@ubuntu:[~/monty]$ cat bytecodes/000.m
push 1
push 2
push 3
pall
```
```
output:
3
2
1
```

### Monty Bytecode Instructions
* **push <int>**: Pushes an integer onto the stack.
* **pall**: Prints all the values on the stack, starting from the top.
* **pint**: Prints the value at the top of the stack.
* **pop**: Removes the top element of the stack.
* **swap**: Swaps the top two elements of the stack.
* **add**: Adds the top two elements of the stack.
* **nop**: Does nothing.
* **sub**: Subtracts the top element of the stack from the second element.
* **div**: Divides the second element of the stack by the top element.
* **mul**: Multiplies the top two elements of the stack.
* **mod**: Computes the modulo of the second element of the stack by the top element.
* **pchar**: Prints the ASCII character represented by the top element of the stack.
* **pstr**: Prints the string contained in the stack.
* **rotl**: Rotates the stack to the top.
* **rotr**: Rotates the stack to the bottom.
* **stack**: Sets the format of the data to a stack (default behavior).
* **queue**: Sets the format of the data to a queue.

## AUTHORS
[Sabah HASBI](https://github.com/Hasbi-sabah "Sabah")
[Abdessamad EL FADILI](https://github.com/elfadili-ae "[^_^]")