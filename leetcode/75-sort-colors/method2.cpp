#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int zeroPlacingIndex = 0, twoPlacingIndex = nums.size() - 1;
    while (zeroPlacingIndex < nums.size() && nums[zeroPlacingIndex] == 0) {
      zeroPlacingIndex++;
    }
    while (twoPlacingIndex >= 0 && nums[twoPlacingIndex] == 2) {
      twoPlacingIndex--;
    }

    for (int i = zeroPlacingIndex; i <= twoPlacingIndex; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[zeroPlacingIndex]);
        zeroPlacingIndex++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[twoPlacingIndex]);
        twoPlacingIndex--;
        i--;
      }
    }
  }
};