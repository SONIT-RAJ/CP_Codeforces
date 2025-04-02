/*
   Author: SONIT RAJ
    created: 17:31:50 02-04-2025
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

void solve(){

    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return;
    }
    int count=0;
    int maximum=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]!=b[j]){
                continue;
            }
            int count=1;
            while(1){
                if(i+count<a.size() && j+count<b.size()){
                    if(a[i+count]==b[j+count]){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            maximum=max(maximum,count);
        }
    }
    cout<<a.size()+b.size()-maximum-maximum;




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}