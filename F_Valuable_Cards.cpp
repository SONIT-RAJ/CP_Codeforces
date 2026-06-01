/*
   Author: SONIT RAJ
    created: 20:00:23 01-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){

    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int>s;
    int ans=1;
    for(int i=0;i<n;i++){
        if(x%a[i]!=0){
            continue;
        }
        int req=x/a[i];
        if(s.count(req)){
            ans++;
            s.clear();
            s.insert(a[i]);
        }
        else{
            vector<int>temp;
            temp.reserve(500);
            for(auto &y:s){
                if(x%(y*a[i])!=0)continue;
                temp.push_back(y*a[i]);
            }
            s.insert(a[i]);
            for(int i=0;i<temp.size();i++){
                s.insert(temp[i]);
            }
        }
    }
    cout<<ans;



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}