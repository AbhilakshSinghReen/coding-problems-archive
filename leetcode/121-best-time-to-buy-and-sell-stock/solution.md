# Method 1 & 2: Think in Reverse

Instead of thinking of what day to sell if we were to buy on day `i`, let's think this way: if we were going to sell the stock on day `i` what day would it make most profit to have bought it on.

So if we are selling on day `i`, we would get the most profit if we had bought it on the day which had the minimum price before day `i` i.e. `indexOf(min[prices[0:i-1]])`.

We can compute these min values in an array, then iterate over `prices` again and calculate the max profit possible for each day.

Method 2: We do not need to put this in a separate array, since the min is only from `0:i-1`, we can have a running min. The running min is possible because `min(prices[0:i-1])` is a function of `min(prices[0:i-2])` and `prices[i - 1]`.
