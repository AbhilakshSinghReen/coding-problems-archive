# Method 1: Count, Swap, and Set

To move all the zeros to the end, we can count the number of zeros of the array and set them as the last elements. Let's assume that we have `x` zeros.

Note that this displaces the last `x` elements. And also note that these are not the only elements that need to be changed.

Every time a zero is moved to the end, the next non-zero element should take it's place.

So, we can follow the following logic instead:

1. Keep two running counts: `currentNonZeroIndex` and `numZeros`. The first tells us which index to place the next non-zero element. The second tells us how many zeros we have encountered so far.
2. Iterate over the array, if we encounter a 0, we increment `numZeros` and move on.
3. If we encounter a non-zero element, we place it at at `currentNonZeroIndex` in the array and increment the value of `currentNonZeroIndex`.
4. Once the iteration is complete, we set the last `numZeros` elements of the array to `0`.
