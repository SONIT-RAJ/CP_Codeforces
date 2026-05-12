/*
   Author: SONIT RAJ
    created: 20:03:20 12-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

vector<int>cnt(15000001,0);
vector<bool>prime(15000001,true);
// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    int g=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        g=__gcd(a[i],g);
    }
    for(int i=0;i<n;i++){
        a[i]/=g;
        cnt[a[i]]++;
    }
    if(cnt[1]==n){
        cout<<-1;
        return;
    }
    int ans=n-1;
    for(int i=2;i<15000001;i++){
        if(prime[i]==false)continue;
        for(int j=i+i;j<15000001;j+=i){
            prime[j]=false;
            cnt[i]+=cnt[j];
        }
        ans=min(ans,n-cnt[i]);
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