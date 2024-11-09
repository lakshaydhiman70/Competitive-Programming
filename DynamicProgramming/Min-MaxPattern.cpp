#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Function prototype for topDown DP approach
int topDown(int target, const std::vector<int>& ways, const std::vector<int>& cost, std::vector<int>& memo);

int main() {
    int target = 10; // Example target value
    std::vector<int> ways = {1, 2, 3}; // Example steps
    std::vector<int> cost = {1, 3, 4}; // Cost associated with each step

    // Memoization table, initialized to -1 (indicating uncomputed states)
    std::vector<int> memo(target + 1, -1);

    // Initial call to the topDown DP function
    int result = topDown(target, ways, cost, memo);

    // Output the result
    if (result == INT_MAX) {
        std::cout << "It's not possible to achieve the target with the given steps.\n";
    } else {
        std::cout << "Minimum cost to achieve the target is: " << result << "\n";
    }

    return 0;
}

int topDown(int target, const std::vector<int>& ways, const std::vector<int>& cost, std::vector<int>& memo) {
    // Base case: if target is 0, no cost is needed
    if (target == 0) {
        return 0;
    }

    // If the target is negative, return a large number indicating an invalid path
    if (target < 0) {
        return INT_MAX;
    }

    // If the result is already computed, return the cached value
    if (memo[target] != -1) {
        return memo[target];
    }

    // Initialize the result to a large number
    int result = INT_MAX;

    // Try all the possible steps and compute the minimum cost recursively
    for (size_t j = 0; j < ways.size(); ++j) {
        int tempResult = topDown(target - ways[j], ways, cost, memo);
        if (tempResult != INT_MAX) {
            result = std::min(result, tempResult + cost[j]);
        }
    }

    // Memoize the result before returning
    return memo[target] = result;
}
