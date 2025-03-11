#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0){
            cout <<n/2 <<" "<<n/2<<endl;
            continue;
        }
        int flag=0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cout << n/i <<" "<<n-n/i<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)cout <<1 <<" "<<n-1<<endl;
        }


    return 0;
}