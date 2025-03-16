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
            int sum=0;
            int d;
            if(n%2==1){
                d=n/2;
            }
            else{
                d=n/2-1;
            }
            int c=1;
            for(int i=0;i<(n*k);i++){
                cin>>a[i];
                if(i==(d+1)*k+(c-1)*(n-d)){
                    sum+=a[i];
                    c++;
                }
            }
            cout<<sum<<endl;

    }
    return 0;
}