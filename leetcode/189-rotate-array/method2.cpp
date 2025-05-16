#include <vector>

using namespace std;

class Solution {
public:
  inline int computeSource(int n, int k, int destination) {
    int source = destination - k;
    if (source < 0) {
      int numNToAdd = ceil((float)(source * -1) / n);
      source += (n * numNToAdd);
    }

    return source;
  }

  void rotate(vector<int> &nums, int k) {
    int n = nums.size();

    int numElementsCompleted = 0;
    for (int startIndex = 0; startIndex < k && numElementsCompleted < n;
         startIndex++) {
      int startElement = nums[startIndex];
      int source = -1, destination = startIndex;

      while (true) {
        source = computeSource(n, k, destination);

        if (source == startIndex) {
          nums[destination] = startElement;
          numElementsCompleted++;
          break;
        }

        nums[destination] = nums[source];

        destination = source;

        numElementsCompleted++;
      }
    }
  }
};
