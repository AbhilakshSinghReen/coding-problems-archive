This problem has more edge cases than a soap opera has plot twists.

# Method 1

There are 3 main things to take care of here:

1. If after reversal, the value is outside [INT_MIN, INT_MAX], we should return 0.
2. We should remove leading 0s after reversal. For example, 120 should become 21.
3. We cannot store 64-bit integers.

## What if we could store 64-bit integers? (Ref 1)

In that case the task becomes quite easy:

1. Convert `x` to digits.
2. Reverse the digits, remove leading zeros.
3. Convert digits to a 64-bit int.
4. Add a negative sign if the original number had a negative sign.
5. Check if the new number is greater than INT_MAX or less than INT_MIN. If so, return 0.
6. Else, return the new number.

## Coming Back

The core logic that we'll be following would be the same as the case in which we're allowd to store 64-bit ints. However, the implementation of step `1` and step `5` would be very different.

Since we are not allowed to store 64-bit integers, we cannot perform `a > INT_MAX` or `a < INT_MIN` operations directly. Instead, we will have to perform these with `vector<int>`s.

Let's assume that we have the following functions available with us:

1. `vector<int> intToDigits(int x)`: takes an integer and returns a vector of integers containing the digits of the original integer, arranged from right to left.
2. `bool vectorIntGte(vector<int> x, vector<int> y)`: checks if the number formed by the digits in the vector `x` is greater than or equal to the number formed by converting the digits in the vector `y`. Digits here are also from right to left.
3. `int digitsToInt(vector<int> digits)`: takes a `vector<int>` representing the digits of a number and returns the number.
4. `vector<int> removeLeadingZeros(vector<int> digits)`: removes all leading zeros from the input vector.

With the above functions available, we can rewrite the logic defined in `Ref 1` as follows:

```cpp
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
```

Note that this does not account for the edge case `x = 0`, that has to be handled separately.

Now, the trick is the implementation of the above 4 helper functions without using 64-bit integers. For that, take a look at the code.
