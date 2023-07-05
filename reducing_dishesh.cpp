#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>


ll solve_rec(int n, vi &satisfaction, int i, int t){
    if(i==n){
        
        return 0;
    }

    ll ans1 = solve_rec(n,satisfaction,i+1,t);  //include the element
    ll ans2 = t*satisfaction[i] + solve_rec(n,satisfaction,i+1,t+1);        //excluce the element

    return max(ans1,ans2);
}

ll solve_memo(int n, vi &satisfaction, vector<vi> &dp, int i, int t){
    if(i==n){
        return dp[i][t] = 0;
    }
    if(dp[i][t]!=-1){
        return dp[i][t];
    }

    ll ans1 = solve_memo(n,satisfaction,dp,i+1,t);  //include the element
    ll ans2 = t*satisfaction[i] + solve_memo(n,satisfaction,dp,i+1,t+1); 
    return dp[i][t] = max(ans1,ans2);
}


ll solve_tab(int n, vi satisfaction){
    vector<vi> dp(n+1,vi(n+1,0));
    for(int i=1; i<=n; i++){
        dp[n][i] = 0;
    }
    
    for(int i=n-1; i>=0; i--){
        for(int t=i; t>=0; t--){
            ll ans1 = dp[i+1][t];  //include the element
            ll ans2 = (t+1)*satisfaction[i] + dp[i+1][t+1];        //excluce the element
            dp[i][t] = max(ans1,ans2);
        }
    }

    
    return dp[0][0];
}


ll solve_so(int n, vi satisfaction){
    vector<vi> dp(n+1,vi(n+1,0));
    vi curr(n+1,0);
    vi prev(n+1,0);
    for(int i=1; i<=n; i++){
        curr[i] = 0;
    }
    
    for(int i=n-1; i>=0; i--){
        prev = curr;
        for(int t=i; t>=0; t--){
            ll ans1 = prev[t];  //include the element
            ll ans2 = (t+1)*satisfaction[i] + prev[t+1];        //excluce the element
            curr[t] = max(ans1,ans2);
        }
    }

    return curr[0];
}


int main(){
    int n;
    cout<<"Enter the number of dishesh:\n";
    cin>>n;
    vi satisfaction(n);
    for(int i=0; i<n; i++){
        cin>>satisfaction[i];
    }
    sort(satisfaction.begin(),satisfaction.end());
    
    ll ans = solve_rec(n,satisfaction,0,1);
    cout<<ans<<endl;

    vector<vi> dp(n+1,vi(n+1,-1));
    ll ans2 = solve_memo(n,satisfaction,dp,0,1);
    cout<<ans2<<endl;
    cout<<solve_tab(n,satisfaction)<<endl;
    cout<<solve_so(n,satisfaction)<<endl;
    return 0;
}