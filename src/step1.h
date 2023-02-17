//
// Created by Alexis on 17/02/2023.
//

#ifndef META_HEURISTIQUE_STEP1_H
#define META_HEURISTIQUE_STEP1_H

// Define a struct to represent an item
typedef struct {
    int weight;
    int value;
    int setup_cost;
} Item;

// Define a struct to represent a solution
typedef struct {
    int *items; // binary vector indicating which items are included in the knapsack
    int value; // total value of the selected items
    int setup_cost; // total setup cost of the selected items
} Solution;

Item *read_items(const char *filename, int *n, int *capacity);

Solution *initialize_solution(int n);

void free_solution(Solution *solution);

void print_solution(Solution *solution, int n);

int compare_items(const void *a, const void *b);

void sort_items(Item *items, int n);




#endif //META_HEURISTIQUE_STEP1_H
