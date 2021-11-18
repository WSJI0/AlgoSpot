#include <bits/stdc++.h>
using namespace std;

int t, n, dp[5][5][12];
int mv[8][2]={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
string s;
bool res=false;
char board[5][5];

void solve(int cur){
    if(cur>s.size()) return;
    for(int y=0; y<5; y++){
        for(int x=0; x<5; x++){
            if(board[y][x]!=s[cur-1]) continue;
            for(int i=0; i<8; i++){
                int my=y+mv[i][0], mx=x+mv[i][1];
                if(0<=mx && mx<5 && 0<=my && my<5){
                    if(dp[my][mx][cur-1]==1){
                        dp[y][x][cur]=1;
                    }
                }
            }
        }
    }
    solve(cur+1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin>>board[i][j];
            }
        }
        cin>>n;
        for(int i=0; i<n; i++){
            memset(dp, 0, sizeof(dp));
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    dp[i][j][0]=1;
                }
            }
            cin>>s;
            solve(1);
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    if(dp[i][j][s.size()]) res=true;
                }
            }
            if(res){
                cout<<s<<" YES"<<"\n";
                res=false;
            } else cout<<s<<" NO"<<"\n";
        }
    }
}
