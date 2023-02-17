#include "step1.h"

//This function check if a solution is feasible
int isFeasible(Solution *solution, Item *items, int capacity, int n) {
    int totalWeight = 0;
    int totalSetup = 0;
    for (int i = 0; i < n; i++) {
        if (solution->items[i]) {
            totalWeight += items[i].weight;
            if (!totalSetup || items[i].setup_cost > totalSetup) {
                totalSetup = items[i].setup_cost;
            }
            if (!solution->setup_cost || items[i].setup_cost > solution->setup_cost) {
                solution->setup_cost = items[i].setup_cost;
            }
        }
    }
    return (totalWeight <= capacity) && (totalSetup <= (solution->value - solution->setup_cost));
}

