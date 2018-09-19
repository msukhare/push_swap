# push_swap

## About push_swap

* push_swap is a project consisting of two software, `push_swap` and `checker`.

* the goal of this project is use any sorting algorithm and adapte them to the limited instruction we can do to sort the stack.

##### about first software, `push_swap`:

* `push_swap` is a software that sorts a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) in ascending order.

* `push_swap` has only 11 instructions to sort stack, and a temporary stack to help sort elements of the first stack.

* `push_swap` writes the instructions, in the [standard output](https://en.wikipedia.org/wiki/Standard_streams#Standard_output_(stdout)), which makes to sort stack.

* `push_swap` uses a modified [quick sort](), and a [selection sort]() to sort stack.

##### about second software, `checker`:

* `checker` checks that the stack is sorted. `checker` reads the instructions on [standard input](https://en.wikipedia.org/wiki/Standard_streams#Standard_input_(stdin)), and applies them to the stack. If after application of the instructions, the stack is sorted, it writes "OK", otherwise writes "KO".

## What you need for make push_swap compile ?

* gcc or clang

* make

* C library

* ar

## How make push_swap compile ?

    Use `make` to compile `push_swap` and `checker`.

## Rules of Makefile

    all: compile `libft.a`, `push_swap` `and checker`

    clean: delete objects

    fclean: call clean and delete `libft.a`, `push_swap` and `checker`

    re: call fclean and all
