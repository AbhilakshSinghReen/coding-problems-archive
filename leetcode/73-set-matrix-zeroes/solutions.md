# Method 1

Pretty straightforward, check code.

# Method 2

In Method 1, we declared 2 vectors to check which rows and column of the matrix were to be set to 0.

In this method, we will use the first row and the first column of the matrix as these vectors.

But we need to avoid recursion. For example, if `(2, 3)` is `0`, it will set `(2, 0)` to 0. This will set `(3, 0)` to `0`, which will set the entire row `3` to `0`, even if there was no `0` in row `3` initially.

To combat this, in the second loop, we don't set any values in `row 0` or `column 0`. Instead, we have separate loops for this row and column at the end. Whether or not `row 0` and `column 0` have to be set to `0` can be determined by two `bool`s, which can be computed in the first iteration.
