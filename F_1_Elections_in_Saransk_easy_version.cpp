/*
   Author: SONIT RAJ
    created: 22:12:13 12-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;

const int maxi=5e5+1;

int spf[maxi];

void pre(){
    for(int i=2;i<=5e5;i++){
        if(spf[i]==0){
            for(int j=i;j<=5e5;j+=i){
                if(spf[j]==0)spf[j]=i;
            }
        }
    }
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    set<int>s;
    map<int,int>cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]>1){
            int p=spf[a[i]];
            while(a[i]%p==0){
                cnt[p]++;
                a[i]/=p;
            }
            s.insert(p);
        }
    }
    int ans=1;
    for(auto &x:s){
        ans=(ans*(cnt[x]+1))%mod;
    }
    cout<<ans;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    pre();
    while(_--){
        solve();
        cout<<"\n";
    }
}