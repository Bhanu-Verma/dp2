#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

ll min_score_triangle_rec(int n, int arr[], int i, int j){
    if(i+1==j){
        return 0;
    }
    ll new_ans = INT_MAX;
    ll ans = 1;
    int k=j-1;
    for(int x=k; x>i; x--){
        ans = arr[i]*arr[j]*arr[x] + min_score_triangle_rec(n,arr,i,x) + min_score_triangle_rec(n,arr,x,j);
        new_ans = min(new_ans,ans);
    }
    return new_ans;
}

ll min_score_triangle_memo(int n, int arr[], int i, int j, vector<vll> &dp){
    if(i+1==j){
        return dp[i][j] = 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll new_ans = INT_MAX;
    ll ans = 1;
    int k=j-1;
    for(int x=k; x>i; x--){
        ans = arr[i]*arr[j]*arr[x] + min_score_triangle_memo(n,arr,i,x, dp) + min_score_triangle_memo(n,arr,x,j, dp);
        new_ans = min(new_ans,ans);
    }
    return dp[i][j] = new_ans;
}

ll min_score_triangle_tab(int n, int arr[]){
    vector<vll> dp(n,vll(n,0));
    for(int i=n-1; i>=0; i--){
        for(int j=i+2; j<n; j++){
            ll ans = INT_MAX;
            for(int k=i+1; k<j; k++){
                ans = min(ans,arr[i]*arr[j]*arr[k]+dp[i][k]+dp[k][j]);
            }

            dp[i][j] = ans;
        }
    }

    
    return dp[0][n-1];
}


int main(){
    cout<<"enter the no. of sides in the polygon:";
    int n;
    cin>>n;
    cout<<"enter the weights on the vertices:\n";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll final_ans = INT_MAX;
    ll ans1 = min_score_triangle_rec(n,arr,0,n-1);
    cout<<ans1<<endl;
    vector<vll> dp(n,vll(n,-1));
    ll ans2 = min_score_triangle_memo(n,arr,0,n-1,dp);
    cout<<ans2<<endl;
    ll ans3 = min_score_triangle_tab(n,arr);
    cout<<ans3<<endl;
    return 0;
}