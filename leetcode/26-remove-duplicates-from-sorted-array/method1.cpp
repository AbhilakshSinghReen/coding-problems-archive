#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int numUniqueElements = 1, destinationIndex = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        numUniqueElements++;
        nums[destinationIndex] = nums[i];
        destinationIndex++;
      }
    }

    return numUniqueElements;
  }
};