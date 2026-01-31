/*
   Author: SONIT RAJ
    created: 10:21:53 30-01-2026
*/


#include<bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")
#define int long long
void solve(){

    int r,c;
    cin>>r>>c;
    vector<int>p(c+1,0);
    vector<int>ps(c+2,0);
    ps[0]=-1e8;
    ps[c+1]=-1e8;
    for(int i=1;i<=r;i++){
        int sum=0;
        if(i%2==0){
            for(int j=1;j<=c;j++){
                int x;
                cin>>x;
                sum+=x;
                ps[j]=max(sum+ps[j+1],ps[j-1]);
            }
        }
        else{
            for(int j=1;j<=c;j++){
                cin>>p[j];
                p[j]+=p[j-1];
            }
            for(int j=c;j>=1;j--){
                ps[j]=max(p[j]+ps[j-1],ps[j+1]);
            }
        }
    }
    cout<<max(ps[1],ps[c]);




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}