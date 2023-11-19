// Subarrays - Subset - Subsequence
// Consider an array -  {1,2,3,4}

// Subarray: contiguous sequence in an array i.e. {1,2},{1,2,3}
// Subarray = n*(n+1)/2

// Subsequence: Need not to be contiguous, but maintains order i.e. {1,2,4}
// Subseqeunce = (2^n) -1 (non-empty subsequences)

// Subset: Same as subsequence except it has empty set i.e. does not maintain the order {1,3},{}
//A subset does not Order nor Continuity.
// Subset = 2^n


//We have an array of length n = 3 and we want to select all the subarrays of length k = 2 then how can we find it
// we can find it by n-k+1 formula 
//eg -> 1 2 3 -> n = 3, k = 2
//If we want to select the subarrays of only size 2 from the array of length 3
// we have to pick the elements that can cover the subarray of size 2

//But if i want to pick all the subarrays of length k and greater than length k then what can we do is
// first we shall find all the subarrays of length k using the same above formula n-k+1

//Good problem to understand this concept link: https://codeforces.com/problemset/problem/1840/C