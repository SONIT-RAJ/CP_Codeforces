#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    m--;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    int right=0;
    priority_queue<int, vector<int>, greater<int>> pqr;
    for(int i=m+1;i<n;i++){
        pqr.push(a[i]);
        right+=a[i];
        while(right<0){
            int val=pqr.top();
            pqr.pop();
            right-=2*val;
            ans++;
        }
    }
    priority_queue<int>pq;
    int left=0;
    for(int i=m;i>0;i--){
        pq.push(a[i]);
        left+=a[i];
        while(left>0){
            int val=pq.top();
            pq.pop();
            left-=2*val;
            ans++;
        }
    }
    cout<<ans;

}
signed main() {
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}