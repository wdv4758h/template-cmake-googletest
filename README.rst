========================================
Project Skeleton - CMake + Google Test
========================================


.. contents:: Table of Contents


Requirements
========================================

* CMake
* C Compiler (e.g. Clang)



Build
========================================

.. code-block:: sh

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

    # Run The Test: method 1
    $ make test
    # Run The Test: method 2
    $ ctest -V
    # Run The Test: method 3
    $ bin_tests/_sampleTests
