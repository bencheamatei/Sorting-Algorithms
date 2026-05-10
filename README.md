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

<<<<<<< HEAD
* ```Radix sort``` - a LSD, base 256 implementation of the radix sort
=======
* ```Radix sort``` - a LSD, base 256 implementation of the radix sort

## How the tests are developed

* The main generator is `test-generation/gen.py`, which creates seven families: `pure-random`, `all-equal`, `decreasing-ish`, `increasing-ish`, `anti-merge`, `radix-random`, and `anti-quick`.
* Sizes are fixed to two tiers: `small` ($20,000$) for $O(n^2)$ algorithms and `big` ($10,000,000$) for $O(n \log n)$ and non-comparison algorithms.
* Each family is designed to emphasize a specific property: presorted order, heavy duplicates, adversarial recursion patterns, or value distributions that favor radix counting passes.

## Testcase families

* `pure-random` - values are sampled uniformly from the full 32-bit signed range.
* `all-equal` - every element is the same random value.
* `decreasing-ish` - random values sorted descending, then a small number of random swaps are applied.
* `increasing-ish` - random values sorted ascending, then a small number of random swaps are applied.
* `anti-merge` - recursively interleaves left/right halves to make merges less cache-friendly and harder to exploit.
* `radix-random` - values are drawn from a few tight ranges (small positives, small negatives, and extreme halves), clustering digits.
* `anti-quick` - builds many duplicates by repeating a small set of distinct values, arranged to stress partitioning.
>>>>>>> 6033c7b8c4cc84287a77d2a1ccf1e8371bc3c211
