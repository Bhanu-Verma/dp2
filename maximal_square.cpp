#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

/*prob -- Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s*/

int solve(vector<vector<int>> mat, int i, int j, int &maxi){
    if(i>=mat.size() || j>=mat[0].size()) return 0;
    int right = solve(mat,i,j+1,maxi);
    int down =  solve(mat,i+1,j,maxi);
    int diagonal = solve(mat,i+1,j+1,maxi);

    if(mat[i][j]==1){
        int ans = min(right,min(down,diagonal));
        maxi = max(maxi,ans);
        return ans;
    }else{
        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    solve(mat,0,0,maxi);
    return maxi;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vi> mat(n,vi(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    cout<<maxSquare(n,m,mat)<<endl;
    return 0;
}

