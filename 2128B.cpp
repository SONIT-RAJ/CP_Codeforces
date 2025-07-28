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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    int j=n-1;
    int flag=0;
    string ans;
    while(i<=j){
        char temp;
        if(flag==0){
            if(a[i]<a[j]){
                temp='L';
                i++;
            }
            else{
                temp='R';
                j--;
            }
            flag=1;
        }
        else{
            if(a[i]<a[j]){
                temp='R';
                j--;
            }
            else{
                temp='L';
                i++;
            }
            flag=0;
        }
        ans.push_back(temp);
    }
    cout<<ans;




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