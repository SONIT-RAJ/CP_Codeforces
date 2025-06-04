/*
   Author: SONIT RAJ
    created: 16:51:25 31-05-2025
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

    int n,s;
    cin>>n>>s;
    int sum=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            sum++;
        }
    }
    if(sum<s){
        cout<<-1;
        return;
    }
    else if(sum==s){
        cout<<0;
        return;
    }
    else{
        int f=sum-s;
        int i=0;
        int j=n-1;
        int l=0;
        while(l!=f){
            if(a[i]==1){
                l++;
            }
            i++;
        }
        int ans1=i;
        i--;
        int k=n-1;
        while(i>=0 && i<=k){
            if(a[i]==1){
                while(a[k]==0){
                    k--;
                }
                k--;
            }
            if(i>k){
                break;
            }
            ans1=min(ans1,i+n-k-1);
            i--;
        }




        l=0;
        while(l!=f){
            if(a[j]==1){
                l++;
            }
            j--;
        }
        int ans2=n-1-j;
        k=0;
        j++;
        while(j<n && j>=k){
            if(a[j]==1){
                while(a[k]==0){
                    k++;
                }
                k++;
            }
            if(j<k){
                break;
            }
            ans2=min(ans2,k+n-j-1);
            j++;
        }
        cout<<min(ans1,ans2);

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