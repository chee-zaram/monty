# Monty Interpreter

[![Sponsor][sponsor-badge]][sponsor]
[![License][license-badge]][license]
[![Contributors][contributors-badge]][contributors]

---

Monty byte codes, just like Python byte codes, consist of a series of operations
which come about after a compilation process. The Monty Language relies on a
unique stack, with specific instructions that act as directives.

---

## Monty byte code

Below are some general rules for writing Monty byte code;

- Files could have an optional `.m` suffix.
- There can only be one instruction per line, subsequent instructions are ignored.
- There can be any number of spaces before or after the opcode (and its argument).
- If the first non-space character on a line is `#`, the line is treated as a comment.

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

Otherwise, to install and move to a standard location, run the following instead:

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

#### Operations

- `push <int>`: Puts an integer `<int>` on the stack.
- `pall`: Prints all the items on the stack.
- `pint`: Prints the value at the top of the stack.
- `pop` : Removes the top element of the stack.
- `swap`: Swaps the top two elements on the stack.
- `add` : Adds the top two elements of the stack. The result is stored in the
  second top element of the stack, and the top element is removed.
- `nop` : Does nothing.
- `sub` : Substracts the top element of the stack from the second top element.
  The result is stored in the second top element, and the top element is removed.
- `div` : Divides the second top element by the top element. The result is stored
  in the second top element, and the top element is removed.
- `mul` : Multiplies the second top element by the top element. Result is stored
  in the second top element, and the top element is removed.
- `mod` : Gets the remainder of the division of the second top element by the top
  element. The result is stored in the second top element, and the top is removed.
- `pchar`: Prints the character whose **ascii** value corresponds to the value
  of the top element on the stack.
- `pstr`: Prints the string starting at the top of the stack until **0** is met
  or the character is not printable or the stack is over.
- `rotl`: Makes the top element the last one, and the second top the new top.
- `rotr`: Makes the last element the top element.
- `stack`: Sets the format of the data to a stack. This is also the default of `monty`.
- `queue`: Sets the format of the data to a queue.

---

## Contributors

[Chee-zaram Okeke](https://github.com/chee-zaram).

---

- For bugs and suggestions, consider
  [opening an issue](https://github.com/chee-zaram/monty/issues).
- For collaborations, email \<ecokeke21@gmail.com\>.

---

[sponsor-badge]: https://img.shields.io/badge/♥-Sponsor-fc0fb5.svg
[sponsor]: https://github.com/sponsors/chee-zaram
[license-badge]: https://img.shields.io/github/license/chee-zaram/monty
[license]: https://github.com/chee-zaram/monty/blob/main/LICENSE
[contributors-badge]: https://img.shields.io/github/contributors/chee-zaram/monty
[contributors]: https://github.com/chee-zaram/monty#contributors
