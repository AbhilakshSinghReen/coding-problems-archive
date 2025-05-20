#include <vector>

using namespace std;

class Solution {
public:
  template <typename T> int boyerMooreMajorityVoting(vector<T> &inputs) {
    /*
    #algoFunction
    Returns the index of the majority element in the array i.e. the element that
    appears more than floor(n / 2) times. The algorithm cannot tell the case in
    which there is no majority element and will give an incorrect out if so.
     */

    int n = inputs.size();
    int threshold = floor(n / 2);

    int candidateIndex = -1, candidateVotes = 0;

    for (int a = 0; a < 2; a++) {
      for (int i = 0; i < n; i++) {
        if (candidateIndex == -1) {
          candidateIndex = i;
        }

        if (inputs[i] == inputs[candidateIndex]) {
          candidateVotes++;
          if (candidateVotes > threshold) {
            return candidateIndex;
          }
        } else {
          candidateVotes--;
          if (candidateVotes == 0) {
            candidateIndex = i;
            candidateVotes = 1;
          }
        }
      }
    }

    return candidateIndex;
  }

  int majorityElement(vector<int> &nums) {
    int candidateIndex = boyerMooreMajorityVoting<int>(nums);

    int candidate = nums[candidateIndex];
    return candidate;
  }
};
