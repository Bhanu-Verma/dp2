#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
const int N=1e3;
ll dp[N+1];

ll get_fib(int n){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=get_fib(n-1)+get_fib(n-2);
    return dp[n];
}

ll fib(int n){
    dp[0]=0;
    dp[1]=1;
    if(n==0 || n==1){
        return dp[n];
    }
    for(int i=2; i<=n; i++){
        dp[n]=dp[n-1]+dp[n-2];
    }
    return dp[n];
}

int main(){
    for(int i=0; i<N+1; i++){
        dp[i]=-1;
    }
  int n;
  cin>>n;
  cout<<get_fib(n)<<endl;
  dp[0]=0;
  dp[1]=1;
  cout<<fib(n)<<endl;
  return 0;
}