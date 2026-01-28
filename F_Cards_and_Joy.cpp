/*
   Author: SONIT RAJ
    created: 11:16:14 27-01-2026
*/


#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>c(n*k);
    for(int i=0;i<n*k;i++){
        cin>>c[i];
    }
    vector<int>f(n);
    vector<int>mpp(1e5+1,0);
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>f[i];
        mpp[f[i]]++;
        s.insert(f[i]);
    }
    vector<int>freq(1e5+1,0);
    for(int i=0;i<n*k;i++){
        freq[c[i]]++;
    }
    vector<int>h(k+1,0);
    for(int i=1;i<=k;i++){
        cin>>h[i];
    }
    int ans=0;
    for(auto &x:s){
        int players=mpp[x];
        int frequency=freq[x];
        vector<vector<int>>dp(players+1,vector<int>(frequency+1,0));
        for(int j=1;j<=players;j++){
            for(int q=1;q<=frequency;q++){
                for(int p=0;p<=min(k,q);p++){
                    dp[j][q]=max(dp[j][q],dp[j-1][q-p]+h[p]);
                }
            }
        }
        ans+=dp[players][frequency];
    }
    cout<<ans;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}