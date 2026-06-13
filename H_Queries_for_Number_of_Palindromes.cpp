/*
   Author: SONIT RAJ
    created: 19:22:17 12-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

int dp[5002][5002];
int p[5002][5002];
void solve(){

    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        p[i][i]=1;
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int start=0;start+len-1<n;start++){
            if(len==2){
                p[start][start+len-1]=(s[start]==s[start+len-1]);
                continue;
            }
            p[start][start+len-1]=(p[start+1][start+len-2] && (s[start]==s[start+len-1]));
        }
    }
    for(int len=2;len<=n;len++){
        for(int start=0;start+len-1<n;start++){
            dp[start][start+len-1]=dp[start][start+len-2]+dp[start+1][start+len-1]-dp[start+1][start+len-2]+p[start][start+len-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<dp[l][r]<<endl;
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}