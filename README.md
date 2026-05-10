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