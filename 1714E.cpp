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
    vector<int>a(n);
    vector<int>b(n);
    bool diff=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(i!=0 && b[i]!=b[i-1]){
            diff=true;
        }
        a[i]%=20;
    }
    if(diff==false){
        cout<<"Yes";
        return;
    }
    set<int>s1={0,5,10,15};
    set<int>s2={1,2,4,8,13,16,17,19};
    set<int>s3={3,6,7,9,11,12,14,18};
    bool flag1=false;
    bool flag2=false;
    bool flag3=false;

    for(int i=0;i<n;i++){
        if(s1.find(a[i])!=s1.end()){
            flag1=true;
        }
        else if(s2.find(a[i])!=s2.end()){
            flag2=true;
        }
        else if(s3.find(a[i])!=s3.end()){
            flag3=true;
        }
    }
    if(flag1==true){
        if(flag2==true){
            cout<<"No";
            return;
        }
        else if(flag3==true){
            cout<<"No";
            return;
        }
    }
    else if(flag2==true){
        if(flag3==true){
            cout<<"No";
            return;
        }
        else{
            cout<<"Yes";
            return;
        }
    }
    else{
        cout<<"Yes";
        return;
    }
    for(int i=0;i<n;i++){
        while(b[i]%10){
            b[i]+=(b[i]%10);
        }
    }
    bool final=false;
    for(int i=1;i<n;i++){
        if(b[i]!=b[i-1]){
            final=true;
            break;
        }
    }
    if(final==false){
        cout<<"Yes";
    }
    else{
        cout<<"No";
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