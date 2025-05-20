# Method 1: The Running Sum

Let's keep a running Sum of the array. If the running sum is negative, we know that the last `x` elements sum up to a negative value. So would these element be a part of the Maximum Subarray? The answer is no, because we can always remove these elements to get a subarray with a higher sum.

So, the algorithm is as follows. We start from the start of the array and assume that the maximum subarray starts here, we keep a running sum. The movement our running sum goes negative, we discard the subarray and start a new maximum subarray.
At each iteration, we keep checking if the current subarray sum is the highest recorded so far.
