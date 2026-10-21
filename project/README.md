_This project has been created as part of 42 curriculum by fernfern and jcortes._

# push_swap

## Description

**push_swap** is a sorting algorithm project that involves sorting a stack of integers using a limited set of operations.

The goal of this project is to sort a stack of integers in ascending order using two stacks, **A** and **B**, while minimizing the total number of operations performed and respecting the restrictions and requirements of the 42 curriculum.

The program takes a list of integers as arguments, processes them, and outputs the sequence of operations required to sort the stack.

_push_swap_ uses two stacks and supports the following operations:

- **sa**: Swap the first two elements of stack A
- **sb**: Swap the first two elements of stack B
- **ss**: Swap the first two elements of both stacks A and B
- **pa**: Push the top element of stack B onto stack A
- **pb**: Push the top element of stack A onto stack B
- **ra**: Rotate stack A upward (the first element becomes the last)
- **rb**: Rotate stack B upward (the first element becomes the last)
- **rr**: Rotate both stacks A and B upward
- **rra**: Reverse rotate stack A (the last element becomes the first)
- **rrb**: Reverse rotate stack B (the last element becomes the first)
- **rrr**: Reverse rotate both stacks A and B

The project also focuses on developing efficient sorting strategies to minimize the number of operations required, handling different input sizes, and ensuring proper error management for invalid inputs, duplicate values, and integer overflow.

The final output is a sequence of valid operations that, when executed, sorts stack A in ascending order with all elements in stack A and stack B empty.

## Instructions

### Compiling

To compile the program and generate `push_swap` executable, run:

```bash
make
```

### Makefile Rules

The Makefile contains the following rules:

- `make` — Compile the program.
- `make bonus` — Compile the program with the complementary part.
- `make clean` — Remove all object files.
- `make fclean` — Remove all object files and the program.
- `make re` — Recompile the program from scratch.

## Usage

Run the program by passing a list of integers as arguments:

```
./push_swap 4 2 7 1 3
```

You can also pass the numbers as a double quoted string:

```
./push_swap "4 2 7 1 3"
```

The program outputs the sequence of operations required to sort the stack in ascending order.

### Example

```
$ ./push_swap 3 2 1
rra
sa
```

The output may vary depending on the sorting algorithm implemented, but the result should always sort the stack correctly.

### Testing

You can verify the output using the **checker** program, if available:

```
./push_swap 4 2 7 1 3 | ./checker_linux 4 2 7 1 3
```

The checker should output `OK` if the operations correctly sort the stack, or `KO` if they do not.

## Contributors

This project is divided in several modules made by the contributors.

- **project_structure**: by jcortes
- **main**: by fernfern
- **parser**: by fernfern
- **bench**: by fernfern
- **analyzer**: by fernfern
- **stacker**: by jcortes
- **checker**: by jcortes
- **solver**: by ferfern, jcortes

## Threshold justification

We use `x` to refer to the disorder index (0-1), the insight that tells us how much disordered is the input array.

- x < 0.2: Use the simple algorithm. (bubble sort for stacks)
- 0.2 <= x < 0.5: Use the medium algorithm. (chunk sort for stacks)
- 0.5 <= x: Use the complex algorithm. (turk sort for stacks)

You can read more for this algorithms in the resources section.

## Resources

The following resources were useful for understanding sorting algorithms, stack operations, and the requirements of the _push_swap_ project:

- [**Sorting Algorithms**](https://www.geeksforgeeks.org/sorting-algorithms/) — An overview of different sorting algorithms and their time complexities.
- [**Big O Notation**](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/) — Understanding algorithm efficiency and complexity.
- [**Stacks in C**](https://www.geeksforgeeks.org/stack-data-structure/) — Learning about stack data structures and their operations.
- [**Bubble Sort Algorithm**](https://www.geeksforgeeks.org/bubble-sort-algorithm/) — Explains how bubble sort works by repeatedly comparing adjacent elements and swapping them when they are in the wrong order.
- [**The Turk Algorithm**](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) — An explanation of a strategy commonly used to optimize the number of operations in _push_swap_.

These resources helped develop an understanding of stack manipulation, algorithm design, and optimization techniques to sort integers using the fewest possible operations.

This project use AI tools to check the exhaustiveness of the tests and received some guidance to optimize the algorithms and write this `README.md`.
