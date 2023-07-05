#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

vll dp(1e6+1,-1);

ll minCoins(int coins[], int m, int val){
    if(val==0){
        return 0;
    }
    if(val<0){
        return INT_MAX;
    }

    if(dp[val]!=-1){
        return dp[val];
    }

    ll ans = INT_MAX;
    for(int i=0; i<m; i++){
        ll ans1=0;
        ans1=minCoins(coins,m,val-coins[i]);
        //cout<<"ans1="<<ans1<<endl;
        if(ans1!=INT_MAX)
            ans = min(ans,ans1+1);

    }
    dp[val] = ans;
    return ans;
}

int main(){
   // cout<<"enter the number of coins:";
    int n;
    cin>>n;
    int val;
    cin>>val;
    //cout<<"\nenter the array elements:\n";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //cout<<"enter the value that you want to generate:";
    
    ll ans = minCoins(arr,n,val);
    if(ans==INT_MAX)
    {
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}