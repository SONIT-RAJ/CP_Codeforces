/*
   Author: SONIT RAJ
    created: 23:58:32 05-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>a(n,{0,0});
    int val2=0;
    int val5=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        while(x%2==0){
            a[i].first++;
            x/=2;
        }
        while(x%5==0){
            a[i].second++;
            x/=5;
        }
        val2+=a[i].first;
        val5+=a[i].second;
    }
    int mini=min(val2,val5);
    vector<vector<vector<int>>>dp(2,vector<vector<int>>(k+1,vector<int>(mini+1,-1)));
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        int temp_i=i%2;
        int new_i=(i+1)%2;
        for(int j=0;j<=min(i,k);j++){
            for(int p=0;p<=mini;p++){
                if(dp[temp_i][j][p]==-1)continue;
                dp[new_i][j][p]=max(dp[new_i][j][p],dp[temp_i][j][p]);
                if(j+1<=k){
                    int e=(mini==val2)?a[i].first+p:a[i].second+p;
                    int value=(mini==val2)?a[i].second:a[i].first;
                    int new_p=e;
                    dp[new_i][j+1][new_p]=max(dp[new_i][j+1][new_p],dp[temp_i][j][p]+value);
                }
            }
        }
    }
    int ans=0;
    for(int p=0;p<=mini;p++){
        ans=max(ans,min(dp[n%2][k][p],p));
    }
    cout<<ans;


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