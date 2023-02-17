#include "step1.h"

// Function to perform 1-flip local search on a solution
void one_flip_ls(Solution *solution, Item *items, int capacity, int n) {
    int best_value = solution->total_value;
    int best_setup = solution->setup_cost;
    int best_i = -1;
    for (int i = 0; i < n; i++) {
        if (solution->items[i]) {
            // Try removing item i
            solution->items[i] = 0;
            solution->total_value -= items[i].value;
            solution->setup_cost -= items[i].setup_cost;
            if (is_feasible(solution, items, capacity, n) && solution->total_value > best_value) {
                best_value = solution->total_value;
                best_setup = solution->setup_cost;
                best_i = i;
            }
            // Add item i back
            solution->items[i] = 1;
            solution->total_value += items[i].value;
            solution->setup_cost += items[i].setup_cost;
        }
    }
    // If improvement is found, perform 1-flip move
    if (best_i != -1) {
        solution->items[best_i] = 0;
        solution->total_value = best_value;
        solution->setup_cost = best_setup;
    }
}

// Function to perform swap local search on a solution
void swap_ls(Solution *solution, Item *items, int capacity, int n) {
    int best_value = solution->total_value;
    int best_setup = solution->setup_cost;
    int best_i = -1;
    int best_j = -1;
    for (int i = 0; i < n - 1; i++) {
        if (solution->items[i]) {
            for (int j = i + 1; j < n; j++) {
                if (solution->items[j]) {
                    // Try swapping items i and j
                    solution->items[i] = 0;
                    solution->items[j] = 0;
                    solution->total_value -= items[i].value + items[j].value;
                    solution->setup_cost -= items[i].setup_cost + items[j].setup_cost;
                    if (is_feasible(solution, items, capacity, n) && solution->total_value > best_value) {
                        best_value = solution->total_value;
                        best_setup = solution->setup_cost;
                        best_i = i;
                        best_j = j;
                    }
                    // Swap items back
                    solution->items[i] = 1;
                    solution->items[j] = 1;
                    solution->total_value += items[i].value + items[j].value;
                    solution->setup_cost += items[i].setup_cost + items[j].setup_cost;
                }
            }
        }
    }
    // If improvement is found, perform swap move
    if (best_i != -1) {
        solution->items[best_i] = 0;
        solution->items[best_j] = 0;
        solution->total_value = best_value;
        solution->setup_cost = best_setup;
    }
}

