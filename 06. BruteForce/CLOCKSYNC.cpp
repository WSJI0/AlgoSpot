#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int t, cl[17], check[17], ans=INF;
int sw[10][16]={
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

void pu(int s){
    for(int i=0; i<16; i++){
        if(sw[s][i]) cl[i]=(cl[i]+3)%12;
    } check[s]++;
}

bool isEnd(){
    for(int i=0; i<16; i++){
        if(cl[i]!=0) return false;
    } return true;
}

int solve(int s){
    if(s==10){
        if(isEnd()) return 0;
        return INF;
    }

    int ret=INF;
    for(int i=0; i<4; i++){
        ret=min(ret, solve(s+1)+i);
        pu(s);
    } check[s]=0;
    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        ans=-1;
        for(int i=0; i<16; i++){
            cin>>cl[i];
            cl[i]%=12;
        }
        ans=solve(0);
        if(ans!=INF) cout<<ans<<"\n";
        else cout<<"-1"<<"\n";
    }
}
