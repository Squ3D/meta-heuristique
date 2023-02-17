// Function to check if a solution is feasible
int is_feasible(Solution *solution, Item *items, int capacity, int n) {
    int total_weight = 0;
    int total_setup = 0;
    for (int i = 0; i < n; i++) {
        if (solution->items[i]) {
            total_weight += items[i].weight;
            if (!total_setup || items[i].setup_cost > total_setup) {
                total_setup = items[i].setup_cost;
            }
        }
    }
    return (total_weight <= capacity) && (total_setup <= (solution->total_value - solution->setup_cost));
}

