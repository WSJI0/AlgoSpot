#include <bits/stdc++.h>
using namespace std;

int t, h, w, ans, cnt;
int block[4][3][2]={
    {{0, 0}, {1, 0}, {0, 1}}, 
    {{0, 0}, {0, 1}, {1, 1}}, 
    {{0, 0}, {1, 0}, {1, 1}}, 
    {{0, 0}, {1, 0}, {1, -1}}
};
char board[21][21];

void fill(int y, int x, int t, char c){
    for(int i=0; i<3; i++){
        int by=block[t][i][0]+y, bx=block[t][i][1]+x;
        board[by][bx]=c;
    }
}

void solve(int cur, int cnt){
    if(cnt==0){
        ans++;
        return;
    }
    
    if(cur==w*h) return;
    int y=cur/w, x=cur%w; 
    if(board[y][x]!='.'){
        solve(cur+1, cnt);
        return;
    }
    for(int i=0; i<4; i++){
        bool ok=true;
        for(int j=0; j<3; j++){
            int by=block[i][j][0]+y, bx=block[i][j][1]+x;
            if(0<=by && by<h && 0<=bx && bx<w){
                if(board[by][bx]!='.') ok=false;
            } else ok=false;
        }
        if(!ok) continue;
        fill(y, x, i, (char)(cur+48));
        solve(cur+1, cnt-3);
        fill(y, x, i, '.');
    } 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        ans=cnt=0;
        cin>>h>>w;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>board[i][j];
                if(board[i][j]=='.') cnt++;
            }
        }
        if(cnt%3==0) solve(0, cnt);
        cout<<ans<<"\n";
    }
}
