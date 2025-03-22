#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long a,b,n;
        cin>>a>>b>>n;
        vector<long long>v(n);
        long long ans=b;
        for(long long i=0;i<n;i++){
            cin>>v[i];
            ans+=min(v[i],a-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}