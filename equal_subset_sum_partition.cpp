#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

//prob - check if it is possible to partition array in two parts such that their sum is equal

int solve2(int n, int a[], int target, int i){
    if(target<0) return 0;
    if(target==0) return 1;
    if(i==n) return 0;
    int excl = solve2(n,a,target,i+1);
    int incl = solve2(n,a,target-a[i],i+1);
    return (incl || excl);
}
    
int solve_so(int n, int a[], int target){
    //vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    vector<int> curr(target+1,0);
    vector<int> prev(target+1,0);
    curr[0]=1;
    prev[0]=1;
   

    for(int i=n-1; i>=0; i--){
        prev = curr;
        for(int t=1; t<=target; t++){
            int excl = prev[t];
            int incl;
            if(t-a[i]>=0){
                incl = prev[t-a[i]];
            }
            else{
                incl = 0;
            }
            curr[t] = (excl || incl);
        }
    }

    return curr[target];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum += a[i];
    }
    int target = 0;
    if(sum&1){
        cout<<"NO\n";
        
    }else{
        target = sum/2;
    

    if(solve_so(n,a,target)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    }
    return 0;
}