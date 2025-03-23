/*
   Author: SONIT RAJ
    created: 23:57:55 22-03-2025
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

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n==1){
        cout<<"NO";
        return;
    }
    int i=0;
    int j=n-1;
    unordered_map<char,int>mpp;
    while(i<=j){
        if(s[i]<s[j]){
            cout<<"YES";
            return;
        }
        else if(s[i]>s[j]){
            if(k==0){
                cout<<"NO";
                return;
            }
            cout<<"YES";
            return;

        }
        else{
            mpp[s[i]]++;
            mpp[s[j]]++;
            i++;
            j--;
        }
    }
    if(mpp.size()>1 && k>0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
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