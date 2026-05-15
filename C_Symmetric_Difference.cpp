/*
   Author: SONIT RAJ
    created: 20:21:32 13-05-2026
*/


#include<bits/stdc++.h>
using namespace std;
void solve(){

    int sz1;
    cin>>sz1;
    set<int>s1;
    for(int i=0;i<sz1;i++){
        int x;
        cin>>x;
        s1.insert(x);
    }
    int sz2;
    cin>>sz2;
    set<int>s2;
    for(int i=0;i<sz2;i++){
        int x;
        cin>>x;
        s2.insert(x);
    }
    vector<int>ans;
    ans.reserve(2500);
    for(int i=-1000;i<=1000;i++){
        if(s1.count(i) && s2.count(i)==0){
            ans.push_back(i);
        }
        else if(s1.count(i)==0 && s2.count(i)){
            ans.push_back(i);
        }
    }
    int sz=ans.size();
    cout<<sz<<" ";
    for(int i=0;i<sz;i++){
        cout<<ans[i]<<" ";
    }





}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){

    int _=1;
    while(_--){
        solve();
    }
}