#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intToDigits(int x) {
    if (x == INT_MIN) { // since INT_MIN cannot be converted to its positive
                        // counterpart, we add an exception for it
      return vector<int>{2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    }

    if (x < 0) {
      x *= -1;
    }

    /*
        INT_MAX = 2,147,483,647
        INT_MIN = -2,147,483,648

        max pow (int32) = 1,000,000,000 = 1e9

        ith digit = x % 10**i / 10**(i - 1)
    */

    vector<int> digits;
    for (int i = 0; i <= 8; i++) {
      int modulator = pow(10, i + 1);
      int divisor = pow(10, i);

      int digit = (x % modulator) / divisor;

      digits.push_back(digit);
    }

    if (x >= 1e9) {
      if (x >= 2 * 1e9) {
        digits.push_back(2);
      } else {
        digits.push_back(1);
      }
    }

    std::reverse(digits.begin(), digits.end());
    digits = removeLeadingZeros(digits);

    return digits;
  }

  bool vectorIntGte(vector<int> x, vector<int> y) {
    x = removeLeadingZeros(x);
    y = removeLeadingZeros(y);

    if (x.size() != y.size()) {
      return x.size() > y.size();
    }

    for (int i = 0; i < x.size(); i++) {
      if (x[i] == y[i]) {
        continue;
      }

      if (x[i] > y[i]) {
        return true;
      } else {
        return false;
      }
    }

    return true; // the function is GTE, if it was GT, this should return false
  }

  int digitsToInt(vector<int> digits) {
    int x = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      x += digits[i] * pow(10, digits.size() - 1 - i);
    }

    return x;
  }

  vector<int> removeLeadingZeros(vector<int> digits) {
    int firstNonZeroIndex = 0;
    while (digits[firstNonZeroIndex] == 0) {
      firstNonZeroIndex++;
    }

    vector<int> updated;
    for (int i = firstNonZeroIndex; i < digits.size(); i++) {
      updated.push_back(digits[i]);
    }

    return updated;
  }

  int reverse(int x) {
    if (x == 0) {
      return 0;
    }

    vector<int> intMinDigits = intToDigits(INT_MIN);
    vector<int> intMaxDigits = intToDigits(INT_MAX);

    bool isNegative = x < 0;
    vector<int> inputIntDigits = intToDigits(x);

    std::reverse(inputIntDigits.begin(), inputIntDigits.end());
    inputIntDigits = removeLeadingZeros(inputIntDigits);

    if (isNegative) {
      if (vectorIntGte(inputIntDigits, intMinDigits)) {
        return 0;
      }

      return -1 * digitsToInt(inputIntDigits);
    }

    if (vectorIntGte(inputIntDigits, intMaxDigits)) {
      return 0;
    }

    return digitsToInt(inputIntDigits);
  }
};
