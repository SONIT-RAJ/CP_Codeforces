/*
   Author: SONIT RAJ
    created: 12:02:20 12-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

vector<int>cnt(1e7+1,0);
vector<bool>prime(1e7+1,true);
vector<int>p(1e7+1,0);

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int maxi=1e7;
    for(int i=2;i<=1e7;i++){
        if(prime[i]==false)continue;
        for(int j=i;j<=1e7;j+=i){
            if(j!=i)prime[j]=false;
            p[i]+=cnt[j];
        }
    }
    for(int i=2;i<=1e7;i++){
        p[i]+=p[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l=min(l,maxi);
        r=min(r,maxi);
        cout<<p[r]-p[l-1]<<endl;
    }




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