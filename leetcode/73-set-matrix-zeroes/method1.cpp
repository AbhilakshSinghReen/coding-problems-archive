#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<bool> isRow0(m, false), isColumn0(n, false);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          isRow0[i] = true;
          isColumn0[j] = true;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isRow0[i] || isColumn0[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};