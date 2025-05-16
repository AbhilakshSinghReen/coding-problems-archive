#include <vector>

using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    int numLesserAfter = 0;
    for (int i = 1; i < nums.size(); i++) {
      numLesserAfter += (nums[i] < nums[i - 1]);
    }
    if (numLesserAfter > 0 && nums.size() > 1 && nums.front() < nums.back()) {
      return false;
    }

    return numLesserAfter <= 1;
  }
};