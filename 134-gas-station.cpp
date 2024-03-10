
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int totalGas = 0;
    int totalCost = 0;
    int currentGas = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); ++i) {
      totalGas += gas[i];
      totalCost += cost[i];
      currentGas += gas[i] - cost[i];

      // If currentGas becomes negative, reset the starting station
      if (currentGas < 0) {
        currentGas = 0;
        start = i + 1;
      }
    }

    // Check if there is a solution
    if (totalGas >= totalCost) {
      return start;
    } else {
      return -1;
    }
  }
};
