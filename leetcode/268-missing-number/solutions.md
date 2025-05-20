# Method 1: No bitwise operations

Let's assume that we were given a perfect array of `n + 1` elements from `[0, n]`. The sum of this array would be the sum of the range `[0, n]`, let's call this the `expectedSum`.

Now, we know that the actual array has one element missing, so the sum of the actual array will be less than `expectedSum` (unless the missing element is 0, for now, let's assume that it isn't). Let's call this sum `actualSum`.

The difference between `expectedSum` and `actualSum` gives the value of the missing element, and this works even if the missing element is `0`.

# Method 2: Use XOR

Kinda similar to Method 1, but Method 1 is much more intuitive.

The thing about XOR is:
`x ^ x = 0`

So, if we take the XOR of the range `[0, n]` twice, i.e:

```
rx = 0
for x in [0, n]:
    rx ^= x
for x in [0, n]:
    rx ^= x
```

the final value would be 0.

If, we had a perfect array of `n + 1` elements from `[0, n]`, we could xor all the elements, then have a loop from `[0, n]` and xor again. For the perfect array, the resultant XOR `rx` should be 0.

But, we don't have a perfect array, what would the resultant XOR be if the one element was missing. It would be the missing element itself!
