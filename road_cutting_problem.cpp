#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

/*given a rod of length n we've to cut it to parts such that every part has length of x,y or z
we're to find the maximum number of picies that we can cut
*/

int solve_mem(int n, int x, int y, int z,vi &dp){
   // cout<<"called\n";
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans1 = 1+solve_mem(n-x,x,y,z,dp);
    
    int ans2 = 1+solve_mem(n-y,x,y,z,dp);
    int ans3 = 1+solve_mem(n-z,x,y,z,dp);
    return max(max(ans1,ans2),ans3);
}

int solve_tab(int n, int x, int y, int z){
    vector<int> dp(n+1,-1);
    dp[0]=0;
   
    
    for(int i=1; i<=n; i++){
        if(i-x>=0 && dp[i-x]!=-1)
            dp[i]= max(dp[i],dp[i-x]+1);
        if(i-y>=0 && dp[i-y]!=-1)
            dp[i]= max(dp[i],dp[i-y]+1);
        if(i-z>=0 && dp[i-z]!=-1)
            dp[i]= max(dp[i],dp[i-z]+1);
        
    }
    if(dp[n]<0){
        return 0;
    }else{
        return dp[n];
    }
}

int main(){
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    vi dp(n+1,-1);
    int ans = solve_mem(n,x,y,z,dp);
    cout<<((ans<0)? 0:ans)<<endl;
    cout<<solve_tab(n,x,y,z)<<endl;
    return 0;
}