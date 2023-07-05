#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int mx_sum_memoization(int arr[], int n, int i,vector<int> &dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int sum1 = arr[i]+mx_sum_memoization(arr,n,i+2,dp);
    int sum2 = mx_sum_memoization(arr,n,i+1,dp);
    dp[i]=max(sum1,sum2);
    return dp[i];
}

//tabulation se kr--


int main(){
    int n;
    cout<<"give the number of elements in the array:";
    cin>>n;
    int arr[n];
    cout<<"give the elements of the array:\n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> dp(n,-1);
    cout<<mx_sum_memoization(arr,n,0,dp)<<endl;
    //cout<<mx_sum_tabulation(arr,n)<<endl;
    return 0;
}