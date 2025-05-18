/*
   Author: SONIT RAJ
    created: 02:00:26 18-05-2025
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

    int n;
    cin>>n;
    string s;
    cin>>s;
    int f1=0;
    int c1=0;
    int i=0;
    int j=n-1;
    char r='A';
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            c1++;
            if(r=='A'){
                r=s[j];
                j--;
            }
            else{
                if(s[j]==r){
                    j--;
                }
                else if(s[i]==r){
                    i++;
                }
                else{
                    f1=1;
                    break;
                }
            }
        }
    }
    int f2=0;
    i=0;
    j=n-1;
    r='A';
    int c2=0;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            c2++;
            if(r=='A'){
                r=s[i];
                i++;
            }
            else{
                if(s[j]==r){
                    j--;
                }
                else if(s[i]==r){
                    i++;
                }
                else{
                    f2=1;
                    break;
                }
            }
        }
    }
    if(f1==0 && f2==0){
        cout<<min(c1,c2);
    }
    else if(f1==0){
        cout<<c1;
    }
    else if(f2==0){
        cout<<c2;
    }
    else{
        cout<<-1;
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