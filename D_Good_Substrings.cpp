/*
   Author: SONIT RAJ
    created: 01:09:59 18-05-2026
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long

struct DoubleHash {

    const int MOD1 = 1e9 + 7;
    const int MOD2 = 1e9 + 9;

    const int P1 = 31;
    const int P2 = 57;

    vector<int> pref1, pref2;
    vector<int> power1, power2;

    DoubleHash(string &s) {

        int n = s.size();

        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);

        power1.resize(n + 1, 1);
        power2.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            power1[i] = (power1[i - 1] * P1) % MOD1;
            power2[i] = (power2[i - 1] * P2) % MOD2;
        }

        for(int i = 0; i < n; i++) {

            int val = s[i] - 'a' + 1;

            pref1[i + 1] =
                (pref1[i] * P1 + val) % MOD1;

            pref2[i + 1] =
                (pref2[i] * P2 + val) % MOD2;
        }
    }

    pair<int,int> getHash(int l, int r) {

        int hash1 =
            pref1[r + 1]
            - (pref1[l] * power1[r - l + 1]) % MOD1;

        hash1 %= MOD1;

        if(hash1 < 0)
            hash1 += MOD1;

        int hash2 =
            pref2[r + 1]
            - (pref2[l] * power2[r - l + 1]) % MOD2;

        hash2 %= MOD2;

        if(hash2 < 0)
            hash2 += MOD2;

        return {hash1, hash2};
    }
};

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    string s;
    cin>>s;
    DoubleHash rh(s);
    string f;
    cin>>f;
    int k;
    cin>>k;
    vector<pair<int,int>>st;
    int n=s.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
            if(f[s[j]-'a']=='0')cnt++;
            if(cnt<=k){
                auto val=rh.getHash(i, j);
                st.push_back(val);
            }
            else{
                break;
            }
        }
    }
    if(st.empty()){
        cout<<0;
        return;
    }
    sort(st.begin(),st.end());
    int ans=1;
    for(int i=1;i<st.size();i++){
        if(st[i]!=st[i-1])ans++;
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