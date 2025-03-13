#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c=0;
        int max=0;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==0){
                c++;
            }
            else{
                c=0;
            }
            if(max<c){
                max=c;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}