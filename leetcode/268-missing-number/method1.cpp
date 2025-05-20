#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();

    int expectedSum = 0, actualSum = 0;
    for (int i = 0; i <= n; i++) {
      expectedSum += i;
    }

    for (int x : nums) {
      actualSum += x;
    }

    int missingElement = expectedSum - actualSum;

    return missingElement;
  }
};