#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> copy(nums);

    for (int i = 0; i < n; i++) {
      int source = i - k;
      while (source < 0) {
        source += n;
      }

      nums[i] = copy[source];
    }
  }
};
