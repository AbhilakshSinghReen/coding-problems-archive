#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();

    int runningXor = 0;
    for (int x : nums) {
      runningXor ^= x;
    }

    for (int i = 0; i <= n; i++) {
      runningXor ^= i;
    }

    return runningXor;
  }
};