/*
   Author: SONIT RAJ
    created: 01:16:13 28-03-2025
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

    int n,k,t;
    cin>>n>>k>>t;
    vector<int>a(n);
    int flag=1;
    int count=0;
    int flag2=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=t){
            flag=0;
        }
        if(i!=0 && a[i]<=t && a[i-1]<=t){
            count++;
        }
        else if(a[i]<=t){
            count=1;
        }
        else{
            count=0;
        }
        if(count>=k){
            flag2=0;
        }

    }
    if(flag==1 || flag2==1){
        cout<<0;
        return;
    }
    int i=0;
    int j=0;
    int answer=0;
    count=0;
    int current=0;
    while(j<n && i<n){
        if(a[j]>t){
            j++;
            i=j;
            count=0;
            current=0;
        }
        else{
            count++;
            if(count>=k){
                current++;
                answer+=current;
            }
            j++;

        }
    }
    cout<<answer;





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