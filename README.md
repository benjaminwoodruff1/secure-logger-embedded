# README #
Put important information about this repository here! Use of markdown is highly
recommended.

[Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)

## How to Build ##
This project is configured with [CMake](https://cmake.org).

There are a few different configurations (build types) for building this code:

``CMAKE_BUILD_TYPE``  | Description                                              | Compiler Flags
--------------------- | -------------------------------------------------------- | -----------------
``Debug``             | For development                                          | ``-Wall -g -Og --coverage``
``Release``           | Official build for end users                             | ``-Wall -O2``
``RelWithDebInfo``    | Same as release, but includes debug symbols              | ``-Wall -O2 -g``
``MinSizeRel``        | Same as release, but optimize for size rather than speed | ``-Wall -Os``

To generate a Makefile for your machine, you need only invoke ``cmake``. Here's a typical example:

``cmake -DCMAKE_BUILD_TYPE=Debug -B build``

From here, you can use [GNU Make](https://www.gnu.org/software/make) to compile
all target binaries. Here's an example using the above ``build`` directory:

`` cd build && make ``

## Unit Testing ##
This project makes use of [Google Test](http://google.github.io/googletest) in
order to self-test. By default, the testing binary is always built. This can be
optionally disabled by setting the CMake variable ``DO_UT`` to ``OFF``. It is on
by default.

``cmake -D CMAKE_BUILD_TYPE=Release -D DO_UT=OFF -B build_release``

If you are interested in checking the line coverage of the unit test suite, you
can use [gcovr](https://github.com/gcovr/gcovr) to generate a concise report.

For convenience, this has been made an optional Makefile target, ``check``. To
generate this report, navigate to your build directory and run ``make check``.

**Note that in order for the coverage report to generate properly, the build
type must be ``Debug``!**
