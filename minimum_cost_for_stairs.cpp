#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

//top-bottom approach
int solve1(int n, vector<int> &dp1, vector<int> cost){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp1[n]!=-1){
        return dp1[n];
    }

    dp1[n]=cost[n]+min(solve1(n-1,dp1,cost),solve1(n-2,dp1,cost));
    return dp1[n];
}


//bottom-up approach
int solve2(int n, vector<int> cost){
    vector<int> dp(n+1,-1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2; i<n; i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i];
    }
    dp[n]=min(dp[n-1],dp[n-2]);
    return dp[n];
}

//space optimized approach--
int solve3(int n,vector<int> cost){
    int prev1=cost[1];
    int prev2=cost[0];

    for(int i=2; i<n; i++){
        int curr = cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);

}

int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int n=cost.size();
    vector<int> dp1(n+1,-1);
    //here we are avoiding to call the function for n because for n 
    // we don't need to add the cost of that stair
    cout<<min(solve1(n-1,dp1,cost),solve1(n-2,dp1,cost))<<endl;
    cout<<solve2(n,cost)<<endl;
    cout<<solve3(n,cost)<<endl;
    return 0;
}