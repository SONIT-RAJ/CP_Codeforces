/*
   Author: SONIT RAJ
    created: 21:04:09 29-06-2025
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

bool check(int p,int q,vector<int>&a,vector<int>&b){
        auto p1=lower_bound(a.begin(),a.end(),p);
        auto q1=lower_bound(b.begin(),b.end(),q);
        if(*p1==p && *q1==q){
            return true;
        }
        else{
            return false;
        }

    }

void solve(){

    int n,m,q;
    cin>>n>>m>>q;
    int A=0;
    int B=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        A+=a[i];
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
        B+=b[i];
    }
    for(int i=0;i<n;i++){
        a[i]=A-a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        b[i]=B-b[i];
    }
    sort(b.begin(),b.end());
    while(q--){
        int x;
        cin>>x;
        bool flag=false;
        bool positive=true;
        if(x<0){
            positive=false;
            x*=-1;
        }
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int p=i;
                int q=x/i;
                if(positive){
                    if(check(p,q,a,b) || check(-p,-q,a,b)){
                        flag=true;
                        break;
                    }
                }
                else{
                    if(check(-p,q,a,b) || check(p,-q,a,b)){
                        flag=true;
                        break;
                    }
                }
                swap(p,q);
                if(positive){
                    if(check(p,q,a,b) || check(-p,-q,a,b)){
                        flag=true;
                        break;
                    }
                }
                else{
                    if(check(-p,q,a,b) || check(p,-q,a,b)){
                        flag=true;
                        break;
                    }
                }

            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}