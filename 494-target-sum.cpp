#include <vector>

using namespace std;

class Solution {
public:
  int output = 0;
  int findTargetSumWays(vector<int> &nums, int target) {
    recursiveSum(nums, target, 0, 0);
    return output;
  }

  void recursiveSum(vector<int> &nums, int target, int total, int index) {
    // base case
    if (index == nums.size() - 1) {
      if (total == target) {
        ++output;
      } else {
        return;
      }
    }

    // choice 1
    int leftTotal = total + nums[index];
    recursiveSum(nums, target, leftTotal, index + 1);

    // choice 2
    int rightTotal = total - nums[index];
    recursiveSum(nums, target, rightTotal, index + 1);
  }
};
