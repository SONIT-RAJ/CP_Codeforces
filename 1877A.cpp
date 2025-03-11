#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        int count=0;
        for(int i=0;i<n-1;i++){
            cin>>x;
            count+=x;

        }
        cout<<-count<<endl;
    }
    return 0;
}