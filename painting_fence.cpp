#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
const int M = 1e9+7;
long long countways_mem(int n, int k, vector<long long> &dp){
    if(n==1) return dp[n]=k;
    if(n==2){
        return dp[n]=k*k;
    }
    if(dp[n]!=-1) return dp[n];
    
    long long ans1 = (((k-1)%M)*(countways_mem(n-1,k,dp))%M)%M;
    long long ans2 = (((k-1)%M)*(countways_mem(n-2,k,dp))%M)%M;
    long long ans = (ans1%M + ans2%M) % M;
    return dp[n] = ans;
}

long long countways_tab(int n, int k){
    vector<long long> dp(n+1,0);
    dp[1]=k;
    dp[2]=(k*k)%M;
    for(int i=3; i<=n; i++){
        long long ans1 = (((k-1)%M)*(dp[i-1])%M)%M;
        long long ans2 = (((k-1)%M)*(dp[i-2])%M)%M;
        dp[i] = (ans1%M + ans2%M) % M;
    }
    return dp[n];
}

long long countways_sp(int n, int k){
       // vector<long long> dp(n+1,0);
        if(n==1){
            return k;
        }else if(n==2){
            return (k*k)%M;
        }
        long long prev2=k;
        long long prev1=(k*k)%M;
        for(int i=3; i<=n; i++){
            long long ans1 = (((k-1)%M)*(prev2)%M)%M;
            long long ans2 = (((k-1)%M)*(prev1)%M)%M;
            long long ans = (ans1%M + ans2%M)%M;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> dp(n+1,-1);
    cout<<countways_tab(n,k)<<endl;
    for(auto i:dp){
        cout<<i<<" ";
    }
    return 0;
}