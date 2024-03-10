#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int compareOne;
    int compareTwo;

    for (int i = 0; i < nums.size(); i++) {
      compareOne = nums[i];
      for (int j = i; j < nums.size(); j++) {
        compareTwo = nums[j];
        if (compareTwo == compareOne) {
          return compareOne;
        }
      }
    }
    return compareOne;
  }
};
