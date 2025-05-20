#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> frequencies;
    for (int x : nums) {
      if (frequencies.find(x) == frequencies.end()) {
        frequencies[x] = 0;
      }

      frequencies[x]++;
    }

    int maxFrequency = 0, maxFrequencyNumber = INT_MIN;
    for (unordered_map<int, int>::iterator it = frequencies.begin();
         it != frequencies.end(); it++) {
      if (it->second > maxFrequency) {
        maxFrequency = it->second;
        maxFrequencyNumber = it->first;
      }
    }

    return maxFrequencyNumber;
  }
};