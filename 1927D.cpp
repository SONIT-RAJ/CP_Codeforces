/*
   Author: SONIT RAJ
    created: 21:02:02 27-05-2025
*/


#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

void find(vector<int>&vec){
    int l,r;
    cin>>l>>r;
    if(l==r){
        cout<<-1<<" "<<-1;
        return;
    }
    auto it_l = upper_bound(vec.begin(), vec.end(), l);
    auto it_r = upper_bound(vec.begin(), vec.end(), r);
    if(it_l==it_r){
        cout<<-1<<" "<<-1;
        return;
    }
    cout<< *(it_l)-1<<" "<<*(it_l);

}

void solve(){

    int n;
    cin>>n;
    vector<int>a;
    a.reserve(n);
    int last;
    int x;
    cin>>x;
    last=x;
    a.emplace_back(1);
    for(int i=1;i<n;i++){
        cin>>x;
        if(last==x){
            continue;
        }
        last=x;
        a.emplace_back(i+1);
    }
    int q;
    cin>>q;
    while(q--){
        find(a);
        cout<<"\n";
    }



}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}