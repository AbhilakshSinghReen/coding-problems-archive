#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();

    int maxProfit = 0, lowestPriceSoFar = prices[0];
    for (int i = 1; i < n; i++) {
      int profit = prices[i] - lowestPriceSoFar;
      maxProfit = max(maxProfit, profit);

      lowestPriceSoFar = min(lowestPriceSoFar, prices[i]);
    }

    return maxProfit;
  }
};