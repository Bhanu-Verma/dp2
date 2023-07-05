#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
unsigned long long M=1e9+7;


ll solve_tab(ll n){
    vll dp(n+1,0);
    dp[0]=1;
     for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if((i-j)>=0)
                dp[i] = (dp[i]+dp[i-j])%M;
                
        }
        
    }
    
   
        return dp[n];
    
}


int main(){
    ll n;
    cin>>n;
    //vll dp(n+1,-1);
    cout<<solve_tab(n)<<endl;
    
    return 0;
}