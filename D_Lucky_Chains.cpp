/*
   Author: SONIT RAJ
    created: 22:29:06 27-03-2026
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long;
vector<vector<int>>factors(1e7+1);
vector<bool>p(1e7+1,true);

void pre(){
    for(int i=2;i<=1e7;i++){
        if(p[i]==false)continue;
        for(int j=i*i;j<=1e7;j+=i){
            p[j]=false;
        }
    }
    for(int i=2;i<=1e7;i++){
        if(p[i]==false)continue;
        for(int j=i;j<=1e7;j+=i){
            factors[j].push_back(i);
        }
    }
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int x,y;
    cin>>x>>y;
    if(__gcd(x,y)!=1){
        cout<<0;
        return;
    }
    int r=abs(y-x);
    int sz=factors[r].size();
    if(sz==0){
        cout<<-1;
        return;
    }
    int mini=INT_MAX;
    for(int i=0;i<sz;i++){
        int f=factors[r][i];
        mini=min(mini,(f-x%f)%f);
    }
    cout<<mini;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}