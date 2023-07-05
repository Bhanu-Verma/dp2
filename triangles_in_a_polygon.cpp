#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

//approach -- fix a base and now think that we are going to construct a triangle on it.
//for it we need another point for it you can traverse using a loop.
//now we are going to count how many triangles we can form using other two sides of the 
//triangle as the base.
//if we multiply then we'll get the no. of all the triangles that we can form if we construct 
//that particular triangle

//now if we add all the above results we'll get the final result

ll solve_rec(int n){
    if(n<=2) return 1;  //because we are going to multiply it
    if(n==3) return 1;
    //loop n-2 times as we can select third point out of these three
    ll ans = 0;
    for(int i=1; i<=n-2; i++){
        ans += 1*solve_rec(i+1)*solve_rec(n-i);
    }
    return ans;
}

ll solve_tab(int n){
    vector<int> dp(n+1);
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for(int x=3; x<=n; x++){
        dp[x] = 0;
        for(int i=1; i<=x-2; i++){
            dp[x] += 1*dp[i+1]*dp[x-i];
            
        }
        
    }
   
    return dp[n];
}

int main(){
    cout<<"Enter the number of sides in the polygon:\n";
    int n;
    cin>>n;
    ll ans = solve_rec(n);
    printf("We can form %d triangles in this polygon.\n",ans);
    ll ans1 = solve_tab(n);
    printf("We can form %d triangles in this polygon.\n",ans1);
    return 0;
}