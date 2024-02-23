#include <vector> //;
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int start = 0;
    int end = matrix.size() - 1;
    int middle = end / 2;
    int last_item = matrix[middle].size() - 1;

    while (start <= end) {
      middle = (start + end) / 2;

      if (target > matrix[middle][0]) {
        // between the range of first and last
        if (target <= matrix[middle][last_item]) {
          for (int i = 0; i < matrix[middle].size(); i++) {
            if (matrix[middle][i] == target) {
              return true;
            }
          }
          return false;
        }

        // if target is greater than the last time
        else if (target > matrix[middle][last_item]) {
          start = middle + 1;
          end = end;
        }
      } else if (target < matrix[middle][0]) {
        // move the indices upwards
        start = start;
        end = middle - 1;
      } else if (target == matrix[middle][0]) {
        return true;
      }
    }
    return false;
  }
};
