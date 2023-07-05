#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

// void solve_rec(ll n, vll &a, vll &b, int i, ll &ans){
//     if(i==n){
//         ll x = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 x += (a[i]+a[j])*(a[i]+a[j]);
//                 x += (b[i]+b[j])*(b[i]+b[j]);
//             }
//         }
//         if(x<ans){
//             ans = x;
//         }
//         return;
//     }

//     solve_rec(n,a,b,i+1,ans);
//     swap(a[i],b[i]);
//     solve_rec(n,a,b,i+1,ans);
//     swap(a[i],b[i]);
// }


ll solve_rec2(ll n, vll &a, vll &b, ll idx){
    if(idx==-1){
        return 0;
    }
    ll x1 = 0;
    for(int j=idx+1; j<n; j++){
        x1 += (a[idx]+a[j])*(a[idx]+a[j]);
        x1 += (b[idx]+b[j])*(b[idx]+b[j]);
    }
    ll ans1 = x1 + solve_rec2(n,a,b,idx-1);
    swap(a[idx],b[idx]);

    ll x2 = 0;
    for(int j=idx+1; j<n; j++){
        x2 += (a[idx]+a[j])*(a[idx]+a[j]);
        x2 += (b[idx]+b[j])*(b[idx]+b[j]);
    }
    ll ans2 = x2 + solve_rec2(n,a,b,idx-1);

    
    swap(a[idx],b[idx]);
    return min(ans1,ans2);
}



void solve(){
    ll n;
    cin>>n;
    vll a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    
    cout<<solve_rec2(n,a,b,n-1)<<endl;
    // vll dp(n+1,-1);
    // cout<<solve_memo(n,a,b,n-1,dp)<<endl;
    // for(int i=0; i<=n; i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}