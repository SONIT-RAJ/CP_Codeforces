#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        int c=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==-1)c++;
        }
        int c1=n-c;
        int ans=0;
        if(c%2==1){
            ans++;
            c--;
            c1++;
        }
        int d=0;
        if(c1<c){
            if((c-c1)%2==0){
                d=(c-c1)/2;
                if(d%2==0){
                    ans+=d;
                }
                else{
                    ans+=d+1;
                }
            }
            else{
                d=(c-c1)/2+1;
                if(d%2==0){
                    ans+=d;
                }
                else{
                    ans+=d+1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}