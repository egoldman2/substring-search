# Substring search comparison

Programming Assignment 2 compares naive substring search and Knuth–Morris–Pratt (KMP). Both return the index of the first occurrence of a pattern in a text, or `std::string_view::npos` when there is no match. An empty pattern matches at index 0. The functions operate on bytes and support embedded zero bytes.

Both implementations are attributed to Ethan Goldman.

## Run the tests

A C++17 compiler and `make` are required:

```sh
make test
```

The tests cover boundary cases, a KMP fallback example, and every pair of binary strings of length up to six against `std::string::find`. Run `make clean` to remove the build directory.

## Status

The search implementations and initial correctness tests are in place. The benchmark, experiments, report, video and peer responses remain to be completed.
