# Monty Interpreter

[![Sponsor][sponsor-badge]][sponsor]

***
Monty byte codes, just like Python byte code, consist of a series of operations
which come about after a compilation process. The Monty Language relies on a
unique stack, with specific instructions that act as directives.
***
## Monty byte code
Below are some general rules for writing Monty byte code;
* Files could have an optional `.m` suffix.
* There can only be one instruction per line, subsequent instructions are ignored.
* There can be any number of spaces before or after the opcode (and its argument).
* If the first non-space character on a line is `#`, the line is treated as a comment.

## Getting Started
#### Installation
Clone this repository and change directory into it:
```sh
git clone https://github.com/chee-zaram/monty.git
cd monty
```
You should have `gcc` installed. To install the Monty Interpreter and use it
in the current directory, run:
```sh
make install
```
Otherwise, install and move it to a standard location, run the following instead:
```sh
make install
make monty
```
To uninstall `monty`, run:
```sh
make clean
```
#### Usage
The interpreter is invoked by running
```sh
monty filename[.m]
```
where `filename` is the file containing Monty bytecodes with an optional `.m` suffix.

## Contributors
[Chee-zaram Okeke](https://github.com/chee-zaram).
***
For bugs and suggestions, consider
[opening an issue](https://github.com/chee-zaram/monty/issues).
For collaborations, email \<ecokeke21@gmail.com\>.
***

[sponsor-badge]: https://img.shields.io/badge/♥-Sponsor-fc0fb5.svg
[sponsor]: https://github.com/sponsors/jsynowiec
