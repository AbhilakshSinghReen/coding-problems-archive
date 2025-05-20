#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int numZeros = 0;
    int currentNonZeroIndex = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        numZeros++;
        continue;
      }

      nums[currentNonZeroIndex] = nums[i];
      currentNonZeroIndex++;
    }

    for (int i = nums.size() - numZeros; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};
