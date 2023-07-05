#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
const int M = 1e9+7;

long int disarrange2_mem(int N, vector<long int> &dp){
    if(N==1) return 0;
    if(N==2) return 1;
    if(dp[N]!=-1) return dp[N];

    long int ans = (((N-1)%M)*(disarrange2_mem(N-1,dp)%M+disarrange2_mem(N-2,dp)%M))%M;
    return dp[N]=ans;
}

long int disarrange2_tab(int N){
    vector<long int> dp(N+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for(int i=3; i<=N; i++){
        dp[i] = (((i-1)%M)*((dp[i-2]%M)+(dp[i-1]%M)))%M;
    }
    return dp[N];
}

long int disarrange2_sp(int N){
    if(N==1) return 0;
    if(N==2) return 1;
    long int prev2 = 0;
    long int prev1 = 1;
    long int ans;
    for(int i=3; i<=N; i++){
        ans = (((i-1)%M)*((prev2%M)+(prev1%M))%M);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int main(){
    int n;
    cin>>n;
    vector<long int> dp(n+1,-1);
    cout<<disarrange2_mem(n,dp)<<endl;
    cout<<disarrange2_tab(n)<<endl;
    cout<<disarrange2_sp(n)<<endl;
    /*for(auto i:dp){
        cout<<i<<" ";
    }*/
    return 0;
}