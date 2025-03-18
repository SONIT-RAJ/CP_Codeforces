#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int c=0;
        int c0=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1){
                c++;
            }
            else if(a[i]==0){
                c0++;
            }
        }
        long long ans=1LL*c*pow(2,c0);
        cout<<ans<<endl;
    }
    return 0;
}