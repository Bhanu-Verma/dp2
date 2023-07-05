#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>


int solve_rec(int sum){
    if(sum<0){
        return 0;
    }
    if(sum==0){
        return 1;
    }
    int ans = 0;
    for(int i=1; i<=6; i++){
        ans += solve_rec(sum-i);
    }
    return ans;
}

ll solve_memo(int sum, vi &dp){
    if(sum<0){
        return 0;
    }
    if(sum==0){
        return dp[sum] = 1;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }

    int ans = 0;
    for(int i=1; i<=6; i++){
        ans += solve_memo(sum-i,dp);
    }
    return dp[sum]=ans;
}

int main(){
    int sum;
    cout<<"give the sum that you want to form:\n";
    cin>>sum;

    cout<<solve_rec(sum)<<endl;
    vi dp(sum+1,-1);
    cout<<solve_memo(sum,dp)<<endl;
    for(int i=0; i<=sum; i++){

    }
    return 0;
}