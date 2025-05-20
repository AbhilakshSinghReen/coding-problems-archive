#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int maxConsecutiveOnesCount = 0;
    int currentConsecutiveOnesCount = 0;

    for (int x : nums) {
      if (x == 1) {
        currentConsecutiveOnesCount++;
        maxConsecutiveOnesCount =
            max(maxConsecutiveOnesCount, currentConsecutiveOnesCount);
      } else {
        currentConsecutiveOnesCount = 0;
      }
    }

    return maxConsecutiveOnesCount;
  }
};