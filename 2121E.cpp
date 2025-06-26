#include<bits/stdc++.h>
using namespace std;
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

void solve(){

    int x, y;
    cin >> x >> y;

    string a = to_string(x);
    string b = to_string(y);

    int ans = 0;
    int i = 0,j = 0;

    while (i < a.size() && j < b.size() && a[i] == b[j]) {
        i++;
        j++;
        ans += 2;
    }

    if(i < a.size() && j < b.size() && (a[i]-'0')==(b[j]-'0')+1) {
        i++;
        j++;
        ans++;
        while(i < a.size() && j < b.size() && (a[i]-'0')==0 && b[j]-'0'==9) {
            i++;
            j++;
            ans++;
        }
    }
    else if(i < a.size() && j < b.size() && (b[j]-'0')==(a[i]-'0')+1) {
        i++;
        j++;
        ans++;
        while(i < a.size() && j < b.size() && (b[j]-'0')==0 && a[i]-'0'==9) {
            i++;
            j++;
            ans++;
        }
    }

    cout<<ans;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}