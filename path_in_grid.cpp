#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

int solve(int n, vector<vi> a){
    vector<vi> ans(n,vi (n,0));
    ans[0][0]=a[0][0];

    for(int i=1; i<n; i++){
        ans[0][i] = ans[0][i-1] + a[0][i];
    }

    for(int i=1; i<n; i++){
        ans[i][0] = ans[i-1][0] + a[i][0];
    }
    

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            
            ans[i][j] = max(ans[i-1][j],ans[i][j-1]) + a[i][j];
        }
    }

    return ans[n-1][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<vi> a(n,vi (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    cout<<solve(n,a)<<endl;
    return 0;
}