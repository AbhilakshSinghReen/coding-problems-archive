#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int x : nums) {
      count0 += (x == 0);
      count1 += (x == 1);
      count2 += (x == 2);
    }

    for (int i = 0; i < count0; i++) {
      nums[i] = 0;
    }
    for (int i = count0; i < (count0 + count1); i++) {
      nums[i] = 1;
    }
    for (int i = (count0 + count1); i < nums.size(); i++) {
      nums[i] = 2;
    }
  }
};