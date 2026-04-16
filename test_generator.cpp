#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

// Writes the size N followed by the array elements
void writeToFile(const string& filename, const vector<int>& data) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: Could not create " << filename << "\n";
        return;
    }
    out << data.size() << "\n";
    for (int x : data) {
        out << x << " ";
    }
    out.close();
    cout << "  -> Generated: " << filename << "\n";
}

void generateTests(int N, const string& prefix) {
    vector<int> data(N);
    // Fixed seed for deterministic, repeatable tests
    mt19937 gen(42); 
    uniform_int_distribution<int> dist(-2000000000, 2000000000);

    // 1. UNIFORM RANDOM: The standard baseline.
    for (int i = 0; i < N; i++) data[i] = dist(gen);
    writeToFile(prefix + "_random.txt", data);

    // 2. ASCENDING (Already Sorted): 
    // Best-case for Insertion/Bubble. Worst-case for naive Quicksort (O(N^2) if pivot is edge).
    vector<int> ascending_data = data;
    sort(ascending_data.begin(), ascending_data.end());
    writeToFile(prefix + "_ascending.txt", ascending_data);

    // 3. DESCENDING (Reverse Sorted): 
    // Absolute worst-case for Insertion/Gnome/Bubble. Forces maximum memory shifting.
    vector<int> descending_data = ascending_data;
    reverse(descending_data.begin(), descending_data.end());
    writeToFile(prefix + "_descending.txt", descending_data);

    // 4. FEW UNIQUE (High Duplicates): 
    // Stress-tests 3-way partitioning in Quicksort and stability in Mergesort/Radix.
    vector<int> few_unique(N);
    uniform_int_distribution<int> small_dist(1, 10);
    for (int i = 0; i < N; i++) few_unique[i] = small_dist(gen);
    writeToFile(prefix + "_few_unique.txt", few_unique);

    // 5. NEARLY SORTED (1% elements out of place):
    // Allows O(N^2) algorithms like Insertion/Gnome to show their only real-world strength.
    vector<int> nearly_sorted = ascending_data;
    int swaps = max(1, N / 100); 
    uniform_int_distribution<int> idx_dist(0, N - 1);
    for (int i = 0; i < swaps; i++) {
        int idx1 = idx_dist(gen);
        int idx2 = idx_dist(gen);
        swap(nearly_sorted[idx1], nearly_sorted[idx2]);
    }
    writeToFile(prefix + "_nearly_sorted.txt", nearly_sorted);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Generating Small Tests (N = 20,000) ===\n";
    cout << "USE THESE FOR: Bubble, Insertion, Gnome, Patience\n";
    generateTests(20000, "small");

    cout << "\n=== Generating Big Tests (N = 10,000,000) ===\n";
    cout << "USE THESE FOR: Quicksort, Mergesort, Heapsort, Introsort, Radix\n";
    cout << "WARNING: Generating ~450MB of text files. Stand by...\n";
    generateTests(10000000, "big");

    cout << "\nAll 10 test files generated successfully. Lock in and get sorting.\n";
    return 0;
}