/*
   Author: SONIT RAJ
    created: 18:28:08 25-05-2026
*/


#include<bits/stdc++.h>
using namespace std;
// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n*m,vector<int>(2));
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[t][0];
            a[t++][1]=i;
        }
    }
    sort(a.begin(),a.end());
    vector<vector<int>>ans(n,vector<int>(m,-1));
    t=0;
    for(int i=0;i<m;i++){
        int idx=a[i][1];
        ans[idx][t]=a[i][0];
        t=(t+1)%m;
    }
    int c=0;
    for(int j=0;j<n;j++){
        c=0;
        for(int i=m;i<n*m;i++){
            if(a[i][1]==j){
                while(ans[j][c]!=-1){
                    c=(c+1)%m;
                }
                ans[j][c]=a[i][0];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



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
    }
}