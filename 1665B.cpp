#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        unordered_map<int,int>mpp;
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mpp[a[i]]++;
            if(maximum<mpp[a[i]]){
                maximum=mpp[a[i]];
            }
        }
        long long ans=n-maximum;
        if(ans==0){
            cout<<0<<endl;
            continue;
        }
        long long sum=ceil((double)n/maximum);
        sum=ceil(log2(sum));
        ans+=sum;
        cout<<ans<<endl;

    }
    return 0;
}