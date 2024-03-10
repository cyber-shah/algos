#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = 0;
    int gasRemaning = gas[start];
    int currentStop = 0;
    bool solutionFound = false;

    std::set<int> visitedSet;
    visitedSet.insert(start);

    int n = gas.size();

    while (visitedSet.size() < n) {
      cout << "visited so far : " << visitedSet.size() << endl;
      cout << "start : " << start << endl;
      cout << "current Stop :" << currentStop << endl;
      cout << "gas Remaning :" << gasRemaning << endl;
      cout << "next move cost : " << cost[currentStop] << endl;
      cout << "gas remaning if we move : " << gasRemaning - cost[currentStop]
           << endl;
      cout << " " << endl;

      // 1. check if we can move ahead
      if (gasRemaning - cost[currentStop] > 0) {
        // move from the current stop, and pay the gas
        gasRemaning -= cost[currentStop];
        // fill gas at the next stop

        currentStop++;
        currentStop = currentStop % gas.size();
        gasRemaning += gas[currentStop];
        // make currentStop loop in that range
      }

      // if that doesn't work out, start from a new point which
      // is not between old start and current stop
      else {
        start += 1;
        currentStop = start;
        gasRemaning = gas[start];

        visitedSet.insert(currentStop);
      }

      // check if we have already arrived
      // and found the solution
      if (currentStop - 1 == start && visitedSet.size() == n) {
        solutionFound = true;
        break;
      }
    }

    if (solutionFound) {
      return start;
    } else {
      return -1;
    }
  }
};
