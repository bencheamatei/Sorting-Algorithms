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

## How the tests are made

The main generator is `test-generation/gen.py`, which uses `test-generation/spec_random.py` to build nine deterministic families and writes input files in the standard format:

* **Format**: first line is `N`, second line has `N` integers separated by spaces.
* **Naming**: `<family>-<index>.in` (for example `pure-random-0.in`).
* **Sizes**:
	* `small` = 20,000 elements (for $O(n^2)$ algorithms).
	* `big` = 10,000,000 elements (for $O(n \log n)$ and non-comparison algorithms).

### Generator usage

```
python test-generation/gen.py <folder> <no_of_tests> <big|small> [family_indexes...]
```

* If `family_indexes` is omitted, families are used round-robin in the order below.
* If `family_indexes` is provided, only those families are used (still round-robin).

Family order and indexes:

```
0: pure-random
1: all-equal
2: decreasing-ish
3: increasing-ish
4: anti-merge
5: almost-equal
6: sawtooth
7: few-distinct
8: alternating
```

Note: `gen.py` imports `numpy`, so make sure it is installed in your Python environment.

## Testcase families (spec_random.py)

* `pure-random` - values are sampled uniformly from the full 32-bit signed range.
* `all-equal` - every element is the same random value.
* `decreasing-ish` - random values sorted descending, then up to `min(500, sqrt(n))` swaps.
* `increasing-ish` - random values sorted ascending, then up to `min(500, sqrt(n))` swaps.
* `anti-merge` - recursively interleaves even/odd positions of a sorted array to fight merge locality.
* `almost-equal` - values are clustered around a single base value with offsets in `[-1000, 1000]`.
* `sawtooth` - concatenation of sorted blocks of size `sqrt(n)`.
* `few-distinct` - array values are drawn from 10 random distinct values.
* `alternating` - alternating negative and non-negative values.

## Average timing table

Fill in the averages you compute for your benchmarks (units are up to you, ms recommended):

| Algorithm | Dataset size | Avg time | Avg time #2 |
| --- | --- | --- | --- |
| Bubblesort | small | 0.935888 s |  0.525643 s|
| Gnomesort | small | 0.999981 s  |  0.579373 s |
| Insertion sort | small | 0.039498 s | 0.022863 s |
| Patience Sorting | big | 1.375485 s | 0.636356 s |
| Quicksort | big | 0.952951 s | 0.499832 s |
| Mergesort | big | 0.764982 s | 0.419123 s |
| Heapsort | big | 1.824383 s | 0.872940 s |
| Introsort | big |  0.768892 s | 0.414114 s |
| Radix sort | big | 0.128475 s | 0.095082 s |
