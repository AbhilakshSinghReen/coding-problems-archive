#include <vector>

using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();

    vector<int> rearranged(n);
    int positivePlaceIndex = 0, negativePlaceIndex = 1;

    for (int x : nums) {
      if (x > 0) {
        rearranged[positivePlaceIndex] = x;
        positivePlaceIndex += 2;
      } else if (x < 0) {
        rearranged[negativePlaceIndex] = x;
        negativePlaceIndex += 2;
      }
    }

    return rearranged;
  }
};