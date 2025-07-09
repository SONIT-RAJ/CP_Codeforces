/*
   Author: SONIT RAJ
    created: 21:45:25 08-07-2025
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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b=a;
    sort(b.begin(),b.end());
    int v=b[k-1];
    int i=0;
    int j=n-1;
    int c=0;
    while(i<=j){
        if(a[i]==a[j] && a[i]<=v){
            i++;
            j--;
        }
        else{
            if(a[i]>v){
                i++;
                c++;
            }
            else if(a[j]>v){
                j--;
                c++;
            }
            else if(a[i]==v){
                i++;
                c++;
            }
            else if(a[j]==v){
                j--;
                c++;
            }
            else{
                cout<<"NO";
                return;
            }
        }
    }
    if(n-c>=k-1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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