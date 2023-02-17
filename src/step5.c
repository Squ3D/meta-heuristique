#include "step1.h"

// Function to perform genetic algorithm on a set of items and capacity constraint
Solution genetic_algorithm(Item *items, int capacity, int n, int pop_size, int num_generations) {
    // Initialize population
    Solution *population = (Solution*) malloc(sizeof(Solution) * pop_size);
    for (int i = 0; i < pop_size; i++) {
        population[i] = create_initial_solution(items, capacity, n);
        local_search(&population[i], items, capacity, n);
    }
    // Sort population in decreasing order of fitness
    qsort(population, pop_size, sizeof(Solution), compare_solutions);
    // Initialize best solution
    Solution best_solution = population[0];
    // Evolve population for specified number of generations
    for (int i = 0; i < num_generations; i++) {
        // Select parents using tournament selection
        Solution parent1 = tournament_selection(population, pop_size);
        Solution parent2 = tournament_selection(population, pop_size);
        // Crossover parents to produce offspring
        Solution offspring = crossover(parent1, parent2, items, capacity, n);
        // Mutate offspring
        mutate(&offspring, items, capacity, n);
        // Perform local search on offspring
        local_search(&offspring, items, capacity, n);
        // Replace worst solution in population with offspring
        replace_worst_solution(population, pop_size, offspring);
        // Sort population in decreasing order of fitness
        qsort(population, pop_size, sizeof(Solution), compare_solutions);
        // Update best solution
        if (population[0].total_value > best_solution.total_value) {
            best_solution = population[0];
        }
    }
    // Free memory used by population
    for (int i = 0; i < pop_size; i++) {
        free(population[i].selected_items);
    }
    free(population);
    // Return best solution found
    return best_solution;
}

