#!/bin/bash

algs="all"
tests="teste"
bins="bin"

mkdir -p "$bins"

for sort_file in "$algs"/*.cpp; do 
    [ -e "$sort_file" ] || continue
    sort_name=$(basename "$sort_file" .cpp)
    g++ -std=c++20 "$sort_file" -o "$bins/$sort_name"
done 

TIMEFORMAT="%4R"

for test_file in "$tests"/*.in; do
    [ -e "$test_file" ] || continue
    
    test_name=$(basename "$test_file" .in)
    
    echo "On $test_name: "
    
    for bin_file in "$bins"/*; do 
        sort_name=$(basename "$bin_file")
        timp=$({ time "$bin_file" < "$test_file" > /dev/null; } 2>&1)
        echo "  $sort_name - $timp s"
    done 
    echo "-----------------------------"
done > res.txt

rm -rf "$bins"