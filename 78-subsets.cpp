#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    set<set<int>> result;
    set<int> empty = {};
    // append this empty set to the result
    result.insert(empty);

    // build a iterator for the for loop
    set<set<int>>::iterator result_itr;

    // for each item in the result now, append the nums to it
    // and decide based on DECISION
    for (result_itr = result.begin(); result_itr != result.end();
         result_itr++) {                      // O(2^n)
      for (int j = 0; j < nums.size(); j++) { // O(n)
        build(result_itr, nums[j], &result);
      }
    }

    // convert the set of sets to vector of vectors
    vector<vector<int>> result_vector;
    for (result_itr = result.begin(); result_itr != result.end();
         result_itr++) {
      result_vector.push_back(
          vector<int>(result_itr->begin(), result_itr->end()));
    }

    return result_vector;
  }

  void build(set<set<int>>::iterator result_itr, int num,
             set<set<int>> *result) {
    // two choices :
    // 1. include the number in the set
    set<int> new_set = *result_itr;
    new_set.insert(num);

    // 2. don't include the number
    // already included in the result

    // modify the result set
    result->insert(new_set);
  }
};
