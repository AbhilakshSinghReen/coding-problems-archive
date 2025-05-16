# Method 1: Simple

Make a copy of `nums` to keep the original values safe, let's call this array `copy`.
Then, iterate over each value of `nums` and set it as:

```
nums[i] = copy[i - k]
```

Of course, if `i - k` is less than 0, it should circle back.

# Method 2: Constant Space

We cannot store the entire `nums` array or a range of values from it as that will take up `O(n)` space.

So, the idea is, to avoid storing any list of numbers, we will proceed as follows:

1. Start at 0 i.e. the first number, store its value in a safe place (a single integer).
2. If this number is the destination, then what index will be the source number? `0 - k` rotated around, let this be `s`.
3. Set `nums[0] = nums[s]`.
4. Now instead of processing the next number i.e. `nums[1]` (like we did in method 1), we will process `nums[s]` instead. So, we repeat steps 1 to 3, but for `s` instead of `0`.
5. Repeat these steps until we come to element `0` again.

## Edge Cases

Let's consider a case `(n, k) = (8, 2)`.

```
nums = [1, 2, 3, 4, 5, 6, 7, 8]
k = 8
```

If we run the above algorithm on this case, we only run for 4 iterations.

```
Initial: [1, 2, 3, 4, 5, 6, 7, 8]

    d = 0, s = 6
        [7, 2, 3, 4, 5, 6, 7, 8]

    d = 6, s = 4
        [7, 2, 3, 4, 5, 6, 5, 8]

    d = 4, s = 2
        [7, 2, 3, 4, 3, 6, 5, 8]

    d = 2, s = 0
        [7, 2, 1, 4, 3, 6, 5, 8]
```

After `0` becomes the source (step 5), we stop.

Okay, so we have an edge case for when `n % k == 0`. This can be solved simply by running multiple "iterations" from different start positions. For example, in the above case, we execute the whole algorithm twice, once starting from index `0` and another time starting from index `1`.

```
Initial: [1, 2, 3, 4, 5, 6, 7, 8]

Iteration 1 (start at 0):
    startValue = 1

    d = 0, s = 6
        [7, 2, 3, 4, 5, 6, 7, 8]

    d = 6, s = 4
        [7, 2, 3, 4, 5, 6, 5, 8]

    d = 4, s = 2
        [7, 2, 3, 4, 3, 6, 5, 8]

    d = 2, s = 0 (from startValue)
        [7, 2, 1, 4, 3, 6, 5, 8]

After Iteration 1: [7, 2, 1, 4, 3, 6, 5, 8]

Iteration 2 (start at 1):
    startValue = 2

    d = 1, s = 7
        [7, 8, 1, 4, 3, 6, 5, 8]

    d = 7, s = 5
        [7, 8, 1, 4, 3, 6, 5, 6]

    d = 5, s = 3
        [7, 8, 1, 4, 3, 4, 5, 6]

    d = 3, s = 1 (from startValue)
        [7, 8, 1, 2, 3, 4, 5, 6]

After Iteration 2: [7, 8, 1, 2, 3, 4, 5, 6]
```

But `n % k == 0` is not the only edge case that we have. What if `(n, k) = (10, 4)`.
Based on the above algorithm, each iteration will have 5 steps. For example, for iteration 1:

```
d = 0, s = 6
d = 6, s = 2
d = 2, s = 8
d = 8, s = 4
d = 4, s = 0
```

But, since we are running k iterations, we will have 20 (5 \* 4) steps in total. However, the array only has 10 elements, which means that we're setting each element twice.

So, let us run k iterations, but add a provision for stopping early. We will track the number of elements we have shifted (in `numElementsCompleted`). Once this number reached `n`, we stop. This is enough to handle this edge case.

Infact, if we proceed in this manner, we don't have to run k iterations.

## Reason for working

The reason this method works is that, each element in the original and final `nums` array has a one-to-one mapping to its counterpart. There are no 2 destinations for a source index and similarly there are no 2 sources for a destination index.

## Additional Optimizations

Note: the `computeSource` used in this method is an optimized version of the one used in Method 1.
