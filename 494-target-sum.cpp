#include <vector>

using namespace std;

class Solution {
public:
  int output = 0;
  vector<vector<int>> *dp;
  int findTargetSumWays(vector<int> &nums, int target) {
    vector<vector<int>> actualvector(nums.size(), vector<int>(nums.size(), -1));
    dp = &actualvector;

    recursiveSum(nums, target, 0, 0);
    return output;
  }

  void recursiveSum(vector<int> &nums, int target, int total, int index) {
    // base case
    if (index == nums.size()) {
      if (total == target) {
        ++output;
      } else {
        return;
      }
    }

    if (index < nums.size()) {

      // choice 1
      int leftTotal = total + nums[index];
      recursiveSum(nums, target, leftTotal, index + 1);

      // choice 2
      int rightTotal = total - nums[index];
      recursiveSum(nums, target, rightTotal, index + 1);
    }
  }
};
