# aristophanes

Ancient Greek NLP toolkit. Currently envisioned with two components: a front-end interface with the user, and back-end language engine; will be made into a bare library later.

# Build Instructions

Simply run `make` in the root directory to build, and `make run` to run `aristo`.

The program requires a reasonably up-to-date version of `g++` to build, such that it supports the commandline option `-std=gnu++17`. Development is done on WSL Ubuntu 22.04 with GCC 11.4.0, and it should work on anything newer as well.

# Dependencies 

It has only one external dependency in the form of Nemanja Trifunović's [utfcpp](https://github.com/nemtrif/utfcpp) library, which is bundled with the code.
