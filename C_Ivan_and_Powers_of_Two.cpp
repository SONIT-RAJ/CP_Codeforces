

//  AMD ki MKC


/*
   Author: SONIT RAJ
    created: 21:30:37 08-05-2026
*/


#include<bits/stdc++.h>
using namespace std;
#define int  long long

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=a[0];
    int last=a[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }
        else{
            while(last<a[i] && cnt>0){
                if(cnt%2==0){
                    ans++;
                }
                cnt/=2;
                last++;
            }
            if(last==a[i]){
                cnt++;
            }
            else{
                ans+=a[i]-last;
                last=a[i];
                cnt=1;
            }
        }
    }
    while(cnt>0){
        if(cnt%2==0){
            ans++;
        }
        cnt/=2;
        last++;
    }
    cout<<ans;




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}