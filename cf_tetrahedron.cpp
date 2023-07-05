#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
const int M = 1e9+7;

// ll solve(ll n, int ver, vector<vi> &dp){
//     if(dp[ver][n]!=-1){
//         return dp[ver][n];
//     }
//     if(n==0 && ver==4){
//         return dp[ver][n] = 1;
//     }
//     if(n==0){
//         return dp[ver][n] = 0;
//     }
//     ll ans2 = 0;
//     for(int i=1; i<=4; i++){
//         if(i==ver){
//             continue;
//         }
//         ans2 = (ans2 + solve(n-1,i,dp))%M;
//     }
//     return dp[ver][n] = ans2;
// }


int main(){
    ll n;
    cin>>n;

    ll perv[5] = {-1,0,0,0,1};
    ll curr[5] = {-1,1,1,1,0};
    for(int i=2; i<=n; i++){
        for(int k=1; k<=4; k++){
            perv[k] = curr[k];
            //cout<<perv[k]<<" ";
        }
        //cout<<endl;
        for(int j=1; j<=4; j++){
            curr[j] = 0;
            for(int l=1; l<=4; l++){
                if(j!=l)
                 curr[j] = (curr[j] + perv[l])%M;
            }
        }
        
    }
    cout<<curr[4]<<endl;
    return 0;
}