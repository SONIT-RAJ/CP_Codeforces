#include<bits/stdc++.h>
using namespace std;
#define endi "\n"
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
const ll mod = 1e9 + 7;

const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

//rbegin()
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        ll ans=0;
        int prev=0;

        for(int i=1;i<n;i++){
                int k=ceil((log2(1.0*a[i-1]/a[i])));
                prev+=k;
                prev=max(0,prev);
                ans+=prev;
        }
        cout<<ans<<endi;
    }
}