Author: Odell Dotson  -  odelldotson@gmail.com

###################################################


To run tests:

	./test

To compile code and build tests from scratch:

	make test; ./test


###################################################


Inline documentation provides a pretty good explination of the code, but here's a quick rundown of the files:

Tests.c                         - Unit tests for the project.

List.c / List.h                 - defines push, pop, enqueue, and dequeue methods 

Main.c                          - Calls test cases, gets complied into the test executable by the makefile

ListEntry.c /ListEntry.h        - Data structure for list elements, and a constructor for new list elements.

CustomType.h                    - Headerfile with some nice-to-haves for C: NULL and boolean type

makefile                        - A makefile for building library and tests

README.md                       - You are here!


###################################################
