# Method 1

Forgetting to take into account the case where `k` can be greater than the size of the `nums` array. <br />
This is why we have a `while` to check if `source < 0`, instead of an `if`.

# Method 2

Case where `k` is a divisor of `n`. <br/>
Case where `GCD(k, n)` is greater than 1. <br>
