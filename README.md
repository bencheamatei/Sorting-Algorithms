# Sorting-Algorithms

## The mcsort team:
* [Benchea Matei](https://github.com/bencheamatei)
* [Mitoceanu Ciprian Minodor](https://github.com/ciprian-mx)

## Intro

This project is a comprehensive C++ benchmarking suite designed to evaluate the performance of various sorting algorithms on diverse datasets. Developed as a team project for the Data Structures course, the primary goal is to implement nine distinct sorting algorithms and rigorously test them to highlight their respective strengths, weaknesses, and edge cases.

## Project Structure
* `algs/` — Contains various draft implementations, experimental approaches, and testing iterations for the sorting algorithms.
* `final_big/` & `final_small/` — Contain the final, optimized source code used for our definitive benchmarks.
* `test-generations/` — Includes all the generators and scripts utilized to create our diverse benchmarking datasets.
* `b.sh` — The primary shell script used to automate the benchmarking process.
* `project.pdf` — The official project requirements and specifications provided for the course.

## The algorithms

### Insertion Sort

A standard implementation of insertion sort with backwards insertion.
Complexity: $O(N^2)$

### Gnome Sort


Complexity: $O(N^2)$

### Bubblesort

Complexity: $O(N^2)$

### Heapsort 

Complexity: $O(NlogN)$

### Quicksort

Complexity: $O(NlogN)$

### Mergesort

Complexity: $O(NlogN)$

### Introsort

Complexity: $O(NlogN)$

### Patience Sorting

Complexity: $O(NlogN)$

### Radix Sort

Complexity: $O(d(n+b))$