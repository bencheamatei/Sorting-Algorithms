#!/bin/bash

algs="$1"
tests="$2"
bins="bin"

mkdir -p "$bins"

for sort_file in "$algs"/*.cpp; do 
    [ -e "$sort_file" ] || continue
    sort_name=$(basename "$sort_file" .cpp)
    g++ -std=c++20 "$sort_file" -o "$bins/$sort_name"
done 

TIMEFORMAT="%4R"
tmp_results=$(mktemp) 
rm -f res.txt         

echo "Running tests..."

for test_file in "$tests"/*.in; do
    [ -e "$test_file" ] || continue
    
    test_name=$(basename "$test_file" .in)
    echo "On $test_name: " >> res.txt
    
    for bin_file in "$bins"/*; do 
        sort_name=$(basename "$bin_file")
        timp=$({ time "$bin_file" < "$test_file" > /dev/null; } 2>&1)
        echo "  $sort_name - $timp s" >> res.txt
        echo "$sort_name $timp" >> "$tmp_results"
    done 
    echo "-----------------------------" >> res.txt
done 

# 3. Calculate averages and find the winner using awk
echo "" >> res.txt
echo "=== FINAL BENCHMARK RESULTS ===" >> res.txt

awk '
{
    # $1 is the sort_name, $2 is the time in seconds
    sum[$1] += $2
    count[$1]++
}
END {
    best_alg = ""
    best_time = 999999999 # Start with an artificially high number
    
    for (alg in sum) {
        avg = sum[alg] / count[alg]
        printf "  %s average time: %.4f s\n", alg, avg
        
        if (avg < best_time) {
            best_time = avg
            best_alg = alg
        }
    }
    
    print "-----------------------------"
    printf "🏆 WINNER: %s (%.4f s on average)\n", best_alg, best_time
}' "$tmp_results" >> res.txt

# 4. Clean up and print results to terminal
rm -rf "$bins" "$tmp_results"
cat res.txt