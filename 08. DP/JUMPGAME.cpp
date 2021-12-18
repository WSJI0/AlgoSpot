#include <bits/stdc++.h>
using namespace std;

int t, n, board[101][101], dp[101][101];
int mv[2][2]={
    {0, 1}, {1, 0}
};

void solve(int y, int x){
    if(dp[y][x]) return;

    dp[y][x]=1;

    int b=board[y][x];
    for(int i=0; i<2; i++){
        int my=mv[i][0]*b+y, mx=mv[i][1]*b+x;
        if(0<=my && my<n && 0<=mx && mx<n){
            solve(my, mx);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin>>board[i][j];
        }

        memset(dp, 0, sizeof(dp));
        solve(0, 0);

        cout<<(dp[n-1][n-1]==1? "YES":"NO")<<"\n";
    }
}
