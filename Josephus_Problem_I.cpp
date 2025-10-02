#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    if(!(cin>>n)) return;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) a[i]=i;
    bool flag=true;
    while(n>0){
        if(flag){
            for(int i=2;i<=n;i+=2) cout<<a[i]<<" ";
            int idx=1;
            for(int i=1;i<=n;i+=2) a[idx++]=a[i];
            if(n%2==1){
                n=n/2+1;
                flag=false;
            }
            else{
                n/=2;
                flag=true;
            }
        } else {
            for(int i=1;i<=n;i+=2) cout<<a[i]<<" ";
            int idx=1;
            for(int i=2;i<=n;i+=2) a[idx++]=a[i];
            if(n%2==1){
                n=n/2;
                flag=true;
            }
            else{
                n/=2;
                flag=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}
