#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int solve_rec(int n, int a[], int curr, int prev){
    if(curr==n){
        return 0;
    }
    //include the element--
    int include = 0;
    if(a[curr]>a[prev] || prev==-1){
        include = 1 + solve_rec(n,a,curr+1,curr);
    }
    //exclude the element--
    int exclude = solve_rec(n,a,curr+1,prev);
    return max(include,exclude);
}

int solve_memo(int n, int a[], int curr, int prev, vector<vi> &dp){
    if(curr==n){
        return dp[curr][prev+1] = 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    //include --
    int include = 0;
    if(a[curr]>a[prev] || prev==-1){
        include = 1 + solve_memo(n,a,curr+1,curr,dp);
    }
    int exclude = solve_memo(n,a,curr+1,prev,dp);
    return dp[curr][prev+1] = max(include,exclude);
}

int longestSubsequence2_tab(int n, int a[])
{
       vector<int> length(n+1,1);
       length[n] = 0;
       for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<=n; j++){
                if(a[j]>a[i]){
                    length[i] = max(length[i],length[j]+1);
                }
            }
       }

       int ans = 1;
       for(int i=0; i<n; i++){
            ans = max(ans,length[i]);
       }
       return ans;
}

int solve_bin(int n, int a[]){
    vector<int> v;
    for(int i=0; i<n; i++){
        int x=a[i];
        auto itr = upper_bound(v.begin(),v.end(),x);
        if(binary_search(v.begin(),v.end(),x)){
            continue;
        }
        if(itr == v.end()){
            v.push_back(x);
        }else{
            int j = itr - v.begin();
            v[j] = x;
        }

    }

    return v.size();
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<longestSubsequence2_tab(n,a)<<endl;
    cout<<solve_rec(n,a,0,-1)<<endl;

    vector<vi> dp(n+1,vi(n+1,-1));
    cout<<solve_memo(n,a,0,-1,dp)<<endl;

    cout<<solve_bin(n,a)<<endl;
    return 0;
}