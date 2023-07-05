#include <bits/stdc++.h>
using namespace std;
 
void min_parity(vector<int> p, vector<int> &odd, vector<int> &even, int i, int &mn){
    if(i==p.size() || (even.size()==0 && odd.size()==0)){
        int count=0;
        for(int i=0; i<p.size()-1; i++){
            if(p[i]%2 != p[i+1]%2){
                count++;
            }
        }
        if(count<mn){
            mn = count;    
        }
        return;
    }
    
    if(p[i]!=0){
        min_parity(p,odd,even,i+1,mn);
        return;
    }
    else{
        if(even.size()!=0){
            int x=even.back();
            even.pop_back();
            p[i] = x;
            
            min_parity(p,odd,even,i+1,mn);
            
            even.push_back(x);
        }
        
        if(odd.size()!=0){
            int x=odd.back();
            odd.pop_back();
            p[i]=x;
            
            min_parity(p,odd,even,i+1,mn);
            odd.push_back(x);
        }
    }
    
}
 
int main(){
    int n;
    cin>>n;
    vector<int> p(n);
    map<int,int> m;
    for(int i=1; i<=n; i++){
        m[i]=1;
    }
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < p.size(); i++) {
 
        // Erase existing numbers
        if (p[i] != 0)
            m.erase(p[i]);
    }

    for (auto i : m) {
        if (i.first % 2 == 0)
            even.push_back(i.first);
        else
            odd.push_back(i.first);
    }
    int mn = INT_MAX;
    min_parity(p,odd,even,0,mn);
    cout<<mn<<endl;
    return 0;
}