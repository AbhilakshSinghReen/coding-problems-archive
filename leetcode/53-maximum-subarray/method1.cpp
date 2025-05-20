#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSubarraySum = INT_MIN, currentSubarraySum = 0;

    for (int x : nums) {
      currentSubarraySum += x;
      maxSubarraySum = max(maxSubarraySum, currentSubarraySum);

      if (currentSubarraySum < 0) {
        currentSubarraySum = 0;
      }
    }

    return maxSubarraySum;
  }
};
