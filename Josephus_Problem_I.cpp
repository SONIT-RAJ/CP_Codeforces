#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n,k;
    cin>>n>>k;
    k++;
    queue<int>q;
    for(int i=1;i<=n;i++)q.push(i);
    int t=1;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int i=q.front();
            q.pop();
            if(t%k){
                q.push(i);
            }
            else{
                cout<<i<<" ";

            }
            t++;
            t%=k;
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
