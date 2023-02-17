#include <stdio.h>
#include <stdlib.h>
#include "step1.h"


// Function to read the problem data from a file and store it in an array of items
Item *read_items(const char *filename, int *n, int *capacity) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fscanf(file, "%d %d", n, capacity);
    Item *items = (Item*) malloc(*n * sizeof(Item));
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %d %d", &items[i].weight, &items[i].value, &items[i].setup_cost);
    }
    fclose(file);
    return items;
}

// Function to initialize a solution with all items set to 0
Solution *initialize_solution(int n) {
    Solution *solution = (Solution*) malloc(sizeof(Solution));
    solution->items = (int*) calloc(n, sizeof(int));
    solution->value = 0;
    return solution;
}

// Function to free the memory used by a solution
void free_solution(Solution *solution) {
    free(solution->items);
    free(solution);
}

// Function to print a solution
void print_solution(Solution *solution, int n) {
    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (solution->items[i]) {
            printf("%d ", i);
        }
    }
    printf("\nTotal value: %d\n", solution->value);
}

// Function to compare the value-to-setup cost ratio of two items
int compare_items(const void *a, const void *b) {
    Item *item_a = (Item*) a;
    Item *item_b = (Item*) b;
    double ratio_a = (double) item_a->value / item_a->setup_cost;
    double ratio_b = (double) item_b->value / item_b->setup_cost;
    if (ratio_a > ratio_b) {
        return -1;
    } else if (ratio_a < ratio_b) {
        return 1;
    } else {
        return 0;
    }
}

// Function to sort the items in descending order of value-to-setup cost ratio
void sort_items(Item *items, int n) {
    qsort(items, n, sizeof(Item), compare_items);
}

//step 2 

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    int n, capacity;
    Item *items = read_items(argv[1], &n, &capacity);

    // Step 1: Reading the data and representing a solution
    sort_items(items, n);
    Solution *solution = initialize_solution(n);
    int weight = 0;
    for (int i = 0; i < n; i++) {
        if (weight + items[i].weight <= capacity) {
            solution->items[i] = 1;
            solution->value += items[i].value;
            weight += items[i].weight;
        }
}



// Print the solution
print_solution(solution, n);

// Free the memory
free_solution(solution);
free(items);

return 0;

}
