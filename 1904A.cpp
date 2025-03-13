#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int xk,yk;
        cin>>xk>>yk;
        int xq,yq;
        cin>>xq>>yq;
        vector<vector<int>>king;
        vector<vector<int>>queen;
        king.push_back({xk+a,yk+b});
        queen.push_back({xq+a,yq+b});

        king.push_back({xk+a,yk-b});
        queen.push_back({xq+a,yq-b});

        king.push_back({xk+b,yk+a});
        queen.push_back({xq+b,yq+a});

        king.push_back({xk+b,yk-a});
        queen.push_back({xq+b,yq-a});

        king.push_back({xk-a,yk+b});
        queen.push_back({xq-a,yq+b});

        king.push_back({xk-a,yk-b});
        queen.push_back({xq-a,yq-b});

        king.push_back({xk-b,yk+a});
        queen.push_back({xq-b,yq+a});

        king.push_back({xk-b,yk-a});
        queen.push_back({xq-b,yq-a});
        int c=0;
        for(int i=0;i<king.size();i++){
            for(int j=0;j<queen.size();j++){
                if(king[i]==queen[j]){
                    c++;
                    break;
                }
            }
        }
        if(a==b){
            cout<<c/2<<endl;
        }
        else{
            cout<<c<<endl;
        }


    }
    return 0;
}