class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, tank = 0, startIdx = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If we run out of gas at this station, reset the start index
            if (tank < 0) {
                startIdx = i + 1;  // Start from next station
                tank = 0;  // Reset tank
            }
        }

        return (totalGas >= totalCost) ? startIdx : -1;
    }
};
