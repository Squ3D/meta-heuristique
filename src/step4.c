#include "step1.h"

// Function to perform local search on a solution using 1-flip and swap moves
void local_search(Solution *solution, Item *items, int capacity, int n) {
    int improved = 1;
    while (improved) {
        improved = 0;
        // Perform 1-flip local search
        one_flip_ls(solution, items, capacity, n);
        // Perform swap local search
        swap_ls(solution, items, capacity, n);
        // Check if improvement is made
        if (solution->improved) {
            improved = 1;
            solution->improved = 0;
        }
    }
}

