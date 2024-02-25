#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result_vector;

    // Initially, add an empty set to the result
    result_vector.push_back(vector<int>());

    // Iterate through each element in nums
    for (int j = 0; j < nums.size(); j++) {
      // Get the current size of result_vector before modification
      int n = result_vector.size();

      // Iterate over existing subsets and append num to create new subsets
      for (int i = 0; i < n; i++) {
        // copy the exisiting set
        vector<int> new_set = result_vector[i];
        // add the current number to the new set
        new_set.push_back(nums[j]);
        // add the new set to the result
        result_vector.push_back(new_set);
      }
    }

    return result_vector;
  }

  void
  build(vector<int> *result_itr, int num,
        vector<vector<int>> *result_vector) { // gets a pointer to the result
    // two choices :
    // 1. include the number in the new_set
    // instead of creating copies, we can directly modify the result set
    // TODO: learn what this means more on pointers
    vector<int> new_set = *result_itr;
    new_set.push_back(num);

    // 2. don't include the number
    // already included in the result
    (*result_vector).push_back(new_set);
  }
};
