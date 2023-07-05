#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>


//using recursion from last to first element--

int solve_rec(vi &w, vi &v, int idx, int W){
    if(idx==0){
        if(w[0]<=W) return v[0];
        else return 0;
    }



    int ans1=0, ans2=0;
    if(w[idx]<=W)
        ans2 = v[idx] + solve_rec(w,v,idx-1,W-w[idx]);
    ans1 = solve_rec(w,v,idx-1,W);
    return max(ans1,ans2);
}


int solve_mem(vi &w, vi &v, int idx, int W, vector<vi> &dp){
    if(idx==0){
        if(w[0]<=W) return v[0];
        else return 0;
    }
    if(dp[idx][W]!=-1){
        return dp[idx][W];
    }


    int ans1=0, ans2=0;
    if(w[idx]<=W)
        ans2 = v[idx] + solve_mem(w,v,idx-1,W-w[idx],dp);
    ans1 = solve_mem(w,v,idx-1,W,dp);
    return dp[idx][W]=max(ans1,ans2);
}



int solve_tab(vi &w, vi &v, int idx, int W){
    //step1 - create a 2d vector for storing answers
    vector<vi> dp(v.size(),vi(W+1,0));
    //step2 - analyze the base case to find the initial state of the dp vector
    for(int i=w[0]; i<=W; i++){
        if(w[0]<=W) dp[0][i] = v[0];
        else dp[0][i] = 0;
    }

    for(int i=1; i<v.size(); i++){
        for(int j=0; j<=W; j++){
            int include = 0;
            if(w[i]<=j){
                include = v[i] + dp[i-1][j-w[i]];
            }
            int exclude = dp[i-1][j];
            dp[i][j] = max(include,exclude);
        }
    }
    return dp[v.size()-1][W];
}

int solve_sp(vi &w, vi &v, int idx, int W){
    //step1 - create a 1d vector for storing answers
    vi curr(W+1,0);
    //step2 - analyze the base case to find the initial state of the dp vector
    for(int i=w[0]; i<=W; i++){
        if(w[0]<=W){
            curr[i] = v[0];
        }else{
            curr[i] = 0;
        }
    }

    for(int i=1; i<v.size(); i++){
        for(int j=W; j>=0; j--){
            int include = 0;
            if(w[i]<=j){
                include = v[i] + curr[j-w[i]];
            }
            int exclude = curr[j];
            curr[j] = max(include,exclude);
        }
    }
    return curr[W];
}


int main(){
    int n,W;
    cin>>n>>W;
    vi w(n),v(n);
    vector<vi> dp(n,vi (W+1,-1));
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<solve_sp(w,v,n-1,W);
    return 0;
}