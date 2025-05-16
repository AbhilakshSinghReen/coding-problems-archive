# Method 1

To count the number of unique elements, we can just iterate over the array and increase the counter every time `nums[i] != nums[i - 1]`.

To update the values of `nums` in-place, we can just maintain a `destinationIndex`, i.e. the index of `nums` at which we will write the next unique number.

Since always `i >= destinationIndex`, writing to the `destinationIndex` will no affect our counting of the unique elements.

Also, at the end of the loop, the `destinationIndex` iteself can give us the count of unique elements.

## Edge Cases

Although this does not fit in the constraints of the question, the above method should check if the lenght of the input array is 0. The code does perform this check with a simple `if` statement.
