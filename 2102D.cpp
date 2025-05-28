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

    int n;
    cin>>n;
    if(n==4){
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int n1=a[0]*1000+a[1]*100+a[2]*10+a[3];
        int n2=a[2]*1000+a[3]*100+a[0]*10+a[1];
        if(n1<=n2){
            cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
            return;
        }
        else{
            cout<<a[2]<<" "<<a[3]<<" "<<a[0]<<" "<<a[1];
            return;
        }

    }
    vector<int>e,e1;
    vector<int>o,o1;
    e.reserve(n);
    o.reserve(n);
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i%2==0){
            e.emplace_back(x);
        }
        else{
            o.emplace_back(x);
        }
    }
    e1=e;
    o1=o;
    sort(e.begin(),e.end());
    sort(o.begin(),o.end());
    int k=0;
    int l=0;
    map<int,bool>mpp;
    for(int i=1;i<=n-3;i++){
        if(i%2==1){
            cout<<o[k]<<" ";
            mpp[o[k]]=true;
            k++;
        }
        else{
            cout<<e[l]<<" ";
            mpp[e[l]]=true;
            l++;
        }
    }
    if(n%2==0){
        int flag
        for(int i=0;i<e1.size();i++){
            if(mpp[e1[i]]==true){
                continue;
            }
            cout<<e1[i]<<" ";
            for(int j=0;j<o1.size();j++){
                if(mpp[o1[j]]==true){
                    continue;
                }
                cout<<o1[j]<<" ";
            }
        }
    }
    else{
        for(int i=0;i<o1.size();i++){
            if(mpp[o1[i]]==true){
                continue;
            }
            cout<<o1[i]<<" ";
            for(int j=0;j<e1.size();j++){
                if(mpp[e1[j]]==true){
                    continue;
                }
                cout<<e1[j]<<" ";
            }
        }
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