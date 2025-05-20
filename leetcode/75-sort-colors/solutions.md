# Method 1: Count and Set

Count the number of `0`s, `1`s, and `2`s in the array.
Iterate over the array again and set the values.

# Method 2: Count and Swap

Now, how do we do this in one pass?

Let's assume a simpler version of the problem: one two elements - `0`s and `1`s.

So, we can iterate over the array, if we encounter a `0`, we move it to the start, and if we encounter a `1`, we move it to the end.
Of course, once we set a `0` to the start, we need to increment the start position, where will be setting the `0`s and the same for the end.

But, when we move a `1` to the end, what if the value we got after swapping also needs to be processed. So, we have to check that element again. This does not hold for moving to the start, because whatever we get from the start is an element that we've already processed.

Now, with three elements `0`s, `1`s, and `2`.
We follow a similar logic: move all the `0`s to the start (`zeroPlacingIndex`) and move all the `2`s to the end (`twoPlacingIndex`). We don't need to process the `1`s, they will find there place themselves.

Note that this does not work with more than 3 values.
