# Sorting-Algorithms

## The mcsort team:
* [Benchea Matei](https://github.com/bencheamatei)
* [Mitoceanu Ciprian Minodor](https://github.com/ciprian-mx)
* [Catalin-George Tisca](https://github.com/in-th3-l00p)

## Intro

This project is a comprehensive C++ benchmarking suite designed to evaluate the performance of various sorting algorithms on diverse datasets. Developed as a team project for the Data Structures course, the primary goal is to implement nine distinct sorting algorithms and rigorously test them to highlight their respective strengths, weaknesses, and edge cases.

## Project Structure
* `algs/` — Contains various draft implementations, experimental approaches, and testing iterations for the sorting algorithms.
* `final_big/` & `final_small/` — Contain the final, optimized source code used for our definitive benchmarks.
* `test-generation/` — Includes all the generators and scripts utilized to create our diverse benchmarking datasets.
* `b.sh` — The primary shell script used to automate the benchmarking process.
* `project.pdf` — The official project requirements and specifications provided for the course.

## Implemented algorithms 

* ```Bubblesort``` - implemented with a boundary marker for less useless checks of the already sorted

* ```Gnomesort``` - the basic implementation

* ```Insertion sort``` - implemented with backwards insertion for swaplessness

* ```Quicksort``` - implemented with non-deterministic pivot choice, in particular the median of 3 random selected values, along with the [Dutch Flag partitioning](https://en.wikipedia.org/wiki/Dutch_national_flag_problem)

* ```Mergesort``` - implemented the interative version

* ```Heapsort``` - implemented as a bottom-up heapsort for avoiding function calls overheading

* ```Introsort``` - implemented by combining the best of out insertion sort, heapsort and quicksort

* ```Patience Sorting``` - basic implementation along with a monte carlo heuristic 

* ```Radix sort``` - a LSD, base 256 implementation of the radix sort

## Strengths, weaknesses, and testcase focus

This section maps each algorithm to the testcase families that best expose its typical behavior. Testcase names match the outputs from `test-generation/gen.py` (for example `pure-random-0.in` or `anti-merge-1.in`).

* ```Bubblesort``` - great on nearly sorted data, very slow on reversed or random input. Focus on `increasing-ish` vs `decreasing-ish` and `pure-random`.

* ```Gnomesort``` - similar to insertion sort: ok when almost sorted, quadratic with many inversions. Compare `increasing-ish` with `decreasing-ish` and `pure-random`.

* ```Insertion sort``` - excellent on nearly sorted arrays, quadratic on reversed or random. Use `increasing-ish` and `decreasing-ish`.

* ```Quicksort``` - fast on average; 3-way partitioning helps with duplicates, but adversarial patterns can still hurt. Look at `pure-random`, `all-equal`, and `anti-quick`.

* ```Mergesort``` - stable $O(n \log n)$ regardless of input order, but with extra memory and heavy data movement. See `pure-random` and `anti-merge`.

* ```Heapsort``` - reliable $O(n \log n)$ and in-place, but cache-unfriendly. See `pure-random` and `decreasing-ish`.

* ```Introsort``` - quicksort speed with heapsort fallback, so it should stay safe on adversarial inputs. See `pure-random` and `anti-quick`.

* ```Patience Sorting``` - can exploit existing order or runs, but has higher overhead on random data. See `increasing-ish` and `pure-random`.

* ```Radix sort``` - near-linear for fixed-width integers; extra memory and performance tied to value distribution. See `radix-random`, `all-equal`, and `pure-random`.

## How the tests are developed

* The main generator is `test-generation/gen.py`, which creates seven families: `pure-random`, `all-equal`, `decreasing-ish`, `increasing-ish`, `anti-merge`, `radix-random`, and `anti-quick`.
* Sizes are fixed to two tiers: `small` (20,000) for $O(n^2)$ algorithms and `big` (10,000,000) for $O(n \log n)$ and non-comparison algorithms.
* Each family is designed to emphasize a specific property: presorted order, heavy duplicates, adversarial recursion patterns, or value distributions that favor radix counting passes.
* `test-generation/test_generator.cpp` is a deterministic alternative that outputs random, ascending, descending, few-unique, and nearly-sorted arrays with a fixed seed for repeatability.
* `test-generation/polygon_gen.cpp` is a minimal uniform random generator using testlib.