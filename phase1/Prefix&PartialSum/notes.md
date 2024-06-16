

### Prefix Sum
Used to quickly retrieve subarray sums

```cpp
vector<int> calcPrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    return prefixSum;
}

// subArrSum = prefixSum[r] - prefixSum[l-1];
```


### Partial Sum
Efficiently process queries to update values in a range, then use prefix sum to compute final array

```cpp
// add x to values in range [l,r]
arr[l]+=x;
arr[r+1]-=x;

// do prefix sum
```

