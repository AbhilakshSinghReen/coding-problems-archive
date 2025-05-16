# Method 1

Let's assume the array is sorted and never rotated. How do we check for a sorted array? It's a pretty simple problem.

Start from index `1` and go till the end. At every element, make sure the previous element is less than or equal to it.

In other words, if we were counting the number of pairs in the array in which the second element is lesser than the first (let's call it `numLesserAfter`), this count should be 0 for a sorted array.

Now, let's see what this count will be if a sorted array is rotated, by some value that is not a multiple of its length.

This count would incrase to 1.

So, can we say that if for the given array, this count is equal to 0 or 1, then it is a rotated sorted array, else, it is not.

We can, but we need one more check. Consider this array:

```
[2, 1, 3, 4]
```

The `numLesserAfter` for this array is 1, but it's not a rotated sorted array.

If it were a rotated sorted array, we should also check if the first element is greater than the last. But, in case it is a pure sorted array, we need not perform this check.

So, we just add in this check, if we have a rotated array that is mostly sorted, i.e. `numLesserAfter > 0`.

So, if `numLesserAfter > 0 && nums.size() > 1 && nums.front() < nums.back()`, our array is not a rotated sorted array.
