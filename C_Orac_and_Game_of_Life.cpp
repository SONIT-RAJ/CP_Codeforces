/*
   Author: SONIT RAJ
    created: 00:59:40 02-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve(){

    int r,c,qu;
    cin>>r>>c>>qu;
    vector<string>a(r);
    for(int i=0;i<r;i++){
        cin>>a[i];
    }
    queue<pair<int,int>>q;
    vector<vector<int>>v(r,vector<int>(c,-1));
    vector<vector<int>>d={{0,1},{1,0},{-1,0},{0,-1}};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<4;k++){
                int x=i+d[k][0];
                int y=j+d[k][1];
                if(x>=0 && y>=0 && x<r && y<c && a[x][y]==a[i][j]){
                    q.push({i,j});
                    v[i][j]=1;
                    break;
                }
            }
        }
    }
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int x=i+d[k][0];
            int y=j+d[k][1];
            if(x>=0 && y>=0 && x<r && y<c && v[x][y]==-1){
                q.push({x,y});
                v[x][y]=1+v[i][j];
            }
        }
    }
    while(qu--){
        int i,j,t;
        cin>>i>>j>>t;
        i--;
        j--;
        if(t>=v[i][j] && v[i][j]!=-1){
            int e=t-v[i][j];
            if(e%2==1){
                cout<<a[i][j]<<endl;
            }
            else{
                if(a[i][j]=='1'){
                    cout<<0<<endl;
                }
                else{
                    cout<<1<<endl;
                }
            }
        }
        else{
            cout<<a[i][j]<<endl;
        }
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}