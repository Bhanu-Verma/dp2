// C++ Program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate the total
// number of ways to have sum N
int findWays(int N, int dp[])
{
    // Base Case
    if (N == 0) {
        return 1;
    }
 
    // Return already stored result
    if (dp[N] != -1) {
 
        return dp[N];
    }
 
    int cnt = 0;
 
    // Recur for all 6 states
    for (int i = 1; i <= 6; i++) {
 
        if (N - i >= 0) {
            cnt = cnt
                  + findWays(N - i, dp);
        }
    }
 
    // Return the result
    return dp[N] = cnt;
}
 
// Driver Code
int main()
{
    // Given sum N
    int N = 5;
 
    // Initialize the dp array
    int dp[N + 1];
 
    memset(dp, -1, sizeof(dp));
 
    // Function Call
    cout << findWays(N, dp);
 
    return 0;
}