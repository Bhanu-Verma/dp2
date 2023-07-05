#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int solve_rec(int n, int obstacles[], int pos, int lane){
    if(pos==n) return 0;
    if(obstacles[pos+1]!=lane){
        return solve_rec(n,obstacles,pos+1,lane);
    }
    int ans = INT_MAX;
    for(int i=1; i<=3; i++){
        if(i==lane || i==obstacles[pos]) continue;
        int ans1 = 1+solve_rec(n,obstacles,pos,i);
        ans = min(ans,ans1);
    }
    return ans;

}


int solve_memo(int n, int obstacles[], int pos, int lane, vector<vi> &dp){
    if(pos==n) return dp[lane][pos]=0;
    if(dp[lane][pos]!=-1){
        return dp[lane][pos];
    }

    if(obstacles[pos+1]!=lane){
        return solve_memo(n,obstacles,pos+1,lane,dp);
    }
    int ans = INT_MAX;
    for(int i=1; i<=3; i++){
        if(i==lane || i==obstacles[pos]) continue;
        int ans1 = 1+solve_memo(n,obstacles,pos,i,dp);
        ans = min(ans,ans1);
    }
    return dp[lane][pos]=ans;

}

int solve_tab(int n, int obstacles[]){
    vector<vi> dp(4,vi(n+1,1e9));
    for(int i=0; i<=3; i++){
        dp[i][n] = 0;
    }

    for(int pos=n-1; pos>=0; pos--){
        for(int lane=1; lane<=3; lane++){
            if(obstacles[pos+1]!=lane){
                dp[lane][pos] = dp[lane][pos+1];
                continue;
            }
            else{
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(i==lane || i==obstacles[pos]) continue;
                    int ans1 = 1+dp[i][pos+1];
                    ans = min(ans,ans1);
                }
                dp[lane][pos] = ans;
            }
        }
    }
    
    return min(dp[2][0],1+min(dp[1][0],dp[3][0]));
}

//here space optimization is also possible as ans depends only on next column

int solve_so(int n, int obstacles[]){
    vi prev(4,1e9);
    vi curr(4,1e9);
    for(int i=0; i<=3; i++){
        curr[i] = 0;
    }

    for(int pos=n-1; pos>=0; pos--){
        for(int lane=1; lane<=3; lane++){
            prev = curr;
            if(obstacles[pos+1]!=lane){
                curr[lane] = prev[lane];
                continue;
            }
            else{
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(i==lane || i==obstacles[pos]) continue;
                    int ans1 = 1+prev[i];
                    ans = min(ans,ans1);
                }
                curr[lane] = ans;
            }
        }
    }
    
    return min(curr[2],1+min(curr[1],curr[3]));
}



int main(){
    int n;
    cin>>n;

    int obstacles[n+1];
    for(int i=0; i<n+1; i++){
        cin>>obstacles[i];
    }

    cout<<"Minimum number of sideways jumps required is:"<<solve_rec(n,obstacles,0,2)<<endl;
    vector<vi> dp(4,vi(n+1,-1));
    cout<<"Minimum number of sideways jumps required is:"<<solve_memo(n,obstacles,0,2,dp)<<endl;
    cout<<"Minimum number of sideways jumps required is:"<<solve_tab(n,obstacles)<<endl;
    cout<<"Minimum number of sideways jumps required is:"<<solve_so(n,obstacles)<<endl;
    return 0;
}