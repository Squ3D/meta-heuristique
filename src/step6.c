// Function to run experiments on the knapsack problem
void run_experiments() {
    // Read data from file
    Item *items;
    int capacity, n;
    read_data_from_file("knapsack.txt", &items, &capacity, &n);
    // Set up parameters for experiments
    int pop_size = 100;
    int num_generations = 100;
    // Run experiments for 10 random seeds
    printf("Seed\tInitial\tLS1\tLS2\tGA\n");
    for (int seed = 1; seed <= 10; seed++) {
        // Set random seed
        srand(seed);
        // Run greedy initial solution and local search
        Solution initial_solution = create_initial_solution(items, capacity, n);
        local_search(&initial_solution, items, capacity, n);
        // Run LS1 local search
        Solution ls1_solution = create_initial_solution(items, capacity, n);
        ls1_local_search(&ls1_solution, items, capacity, n);
        // Run LS2 local search
        Solution ls2_solution = create_initial_solution(items, capacity, n);
        ls2_local_search(&ls2_solution, items, capacity, n);
        // Run genetic algorithm
        Solution ga_solution = genetic_algorithm(items, capacity, n, pop_size, num_generations);
        // Print results for this seed
        printf("%d\t%d\t%d\t%d\t%d\n", seed, initial_solution.total_value, ls1_solution.total_value, ls2_solution.total_value, ga_solution.total_value);
    }
    // Free memory used by items
    free(items);
}

