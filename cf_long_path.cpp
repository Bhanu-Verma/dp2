#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
const int M = 1e9+7;
#define int long long

// ll solve(int room, ll &ans, vi p, ll n, vi &cross, vector<vi> &dp){
//     cout<<"room="<<room<<endl;
//     cross[room]++;
//     if(cross[room]&1){
//         if(dp[room][1]!=-1){
//             return dp[room][1];
//         }
//     }else{
//         if(dp[room][0]!=-1){
//             return dp[room][0];
//         }
//     }
    
//     if(room == n+1){
//         return dp[room][1] = dp[room][0] = 0;
//     }
//     if(cross[room]&1){
//         ans++;
//         return dp[room][1] = (1 + solve(p[room],ans,p,n,cross,dp))%M;
//     }else{
//         ans++;
//         return dp[room][0] = (1 + solve(room+1,ans,p,n,cross,dp))%M;
//     }

// }

signed main(){
    ll n;
    cin>>n;
    vi p(n+1);
    vi cross(n+2,0);
    vector<vi> dp(n+2,vi(2,-1));
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    //ll ans = 0;
    //cout<<solve(1,ans,p,n,cross,dp)<<endl;
    
    int r = 1;
    int ans = 0;
    while(r!=n+1){
        cross[r]++;
        if(cross[r]&1){
            r = p[r];
            ans = (ans+1)%M;
        }else{
            r = r+1;
            ans =(ans+1)%M;
        }
    }
    cout<<ans<<endl;
    return 0;
}