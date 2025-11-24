/*
   Author: SONIT RAJ
    created: 18:46:19 23-11-2025
*/


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
typedef unsigned long long ull;
typedef long double lld;

// ╭──────────────────────────────╮
// │         MACROS ZONE          │
// ╰──────────────────────────────╯
#define ll                long long
#define int               long long
#define eb                emplace_back
#define mp                make_pair
#define ff                first
#define ss                second
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(),x.rend()
#define ins               insert
#define ln                '\n'
#define endl              "\n"
#define endlf             "\n" << flush;
#define yes               cout << "YES\n"
#define no                cout << "NO\n"
#define fr(i,n)           for(int i = 0; i < n; ++i)
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define getunique(v)      {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define NP(a)             next_permutation(all(a))
#define sz(x)             (int)((x).size())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll



// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,k,qu;
    cin>>n>>k>>qu;
    vector<int>a(n,0);
    vector<vector<int>>q(qu,vector<int>(3));
    for(int i=0;i<qu;i++){
        int t,l,r;
        cin>>t>>l>>r;
        l--;
        r--;
        q[i]={t,l,r};
    }
    sort(q.begin(),q.end());
    for(int i=0;i<qu;i++){
        if(q[i][0]==1){
            for(int j=q[i][1];j<=q[i][2];j++){
                a[j]=max(a[j],k);
            }
        }
        else{
            int l=q[i][1];
            int r=q[i][2];
            unordered_set<int>s;
            vector<vector<int>>temp;
            temp.reserve(r-l+1);
            for(int j=l;j<=r;j++){
                if(a[j]>=k){
                    a[j]=k+1;
                    temp.push_back({a[j],j});
                }
                else if(s.count(a[j])==0){
                    s.insert(a[j]);
                }
                else{
                    temp.push_back({a[j],j});
                }
            }
            sort(temp.begin(),temp.end());
            int x=0;
            for(int j=0;j<=k-1;j++){
                if(s.count(j)==0){
                    a[temp[x++][1]]=j;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}


