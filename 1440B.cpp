#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n>>k;
        vector<int>a(n*k);
            long long sum=0;
            long long d;
            if(n%2==1){
                d=n/2;
            }
            else{
                d=n/2-1;
            }
            long long c=1;
            for(int i=0;i<(n*k);i++){
                cin>>a[i];
                if(i==(d)*k+(c-1)*(n-d)){
                    sum+=a[i];
                    c++;
                }
            }
            cout<<sum<<endl;

    }
    return 0;
}