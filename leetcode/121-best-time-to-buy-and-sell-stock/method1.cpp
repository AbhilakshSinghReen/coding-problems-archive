#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();

    vector<int> minBefore(n);
    minBefore[0] = INT_MAX;
    int minElement = prices[0];
    for (int i = 1; i < n; i++) {
      minBefore[i] = minElement;

      minElement = min(minElement, prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
      int profit = prices[i] - minBefore[i];
      maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
  }
};