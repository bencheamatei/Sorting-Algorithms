#!/bin/bash

algs="$1"
tests="$2"
bins="bin"

# Input validation
if [ -z "$algs" ] || [ -z "$tests" ]; then
    echo "Usage: ./benchmark.sh <algorithm_folder> <test_folder>"
    exit 1
fi

mkdir -p "$bins"

echo -e "\e[36m=== Compiling Algorithms ===\e[0m"
for sort_file in "$algs"/*.cpp; do 
    [ -e "$sort_file" ] || continue
    sort_name=$(basename "$sort_file" .cpp)
    
    # CRITICAL: No -O3 flag used here. Compiling purely unoptimized.
    g++ -std=c++20 "$sort_file" -o "$bins/$sort_name"
    
    if [ $? -eq 0 ]; then
        echo -e " \e[90m[+] Compiled $sort_name\e[0m"
    else
        echo -e " \e[31m[!] Failed to compile $sort_name\e[0m"
    fi
done 

tmp_results=$(mktemp) 
rm -f res.txt         

echo -e "\n\e[36m=== Running Benchmarks ===\e[0m" | tee -a res.txt

for test_file in "$tests"/*.in; do
    [ -e "$test_file" ] || continue
    
    test_name=$(basename "$test_file" .in)
    echo -e "\e[33mOn $test_name:\e[0m" | tee -a res.txt
    
    for bin_file in "$bins"/*; do 
        sort_name=$(basename "$bin_file")
        
        # Capture the raw double value printed by <chrono> in the C++ file
        timp=$("$bin_file" < "$test_file")
        
        # Print formatted time to screen and file
        printf "  %s - %.6f s\n" "$sort_name" "$timp" | tee -a res.txt
        
        # Save raw data for awk to process later
        echo "$sort_name $timp" >> "$tmp_results"
    done 
    echo "-----------------------------" | tee -a res.txt
done 

echo "" >> res.txt
echo -e "\e[32m=== FINAL BENCHMARK RESULTS ===\e[0m" >> res.txt

# Use awk to calculate the averages
awk '
{
    sum[$1] += $2
    count[$1]++
}
END {
    best_alg = ""
    best_time = 999999999.0 
    
    for (alg in sum) {
        avg = sum[alg] / count[alg]
        printf "  %s average time: %.6f s\n", alg, avg
        
        if (avg < best_time) {
            best_time = avg
            best_alg = alg
        }
    }
    
    print "-----------------------------"
    printf "BEST: %s (%.6f s on average)\n", best_alg, best_time
}' "$tmp_results" | tee -a res.txt

# Cleanup
rm -rf "$bins" "$tmp_results"