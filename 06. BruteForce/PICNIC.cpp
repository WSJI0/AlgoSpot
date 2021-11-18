#include <bits/stdc++.h>
using namespace std;

int ans=0;
int n, fr[11][11];
int choose[11];
map<vector<int>, int> mp;

void solve(int N, vector<int> v){
    if(N==0){
        if(!mp[v]) ans++;
        mp[v]=1;
        return;
    }
    for(int i=0; i<n; i++){
        if(choose[i]==1) continue;
        for(int j=i+1; j<n; j++){
            if(choose[j]==1) continue;
            if(fr[i][j]){
                choose[i]=choose[j]=1;
                v[i]=j; v[j]=i;
                solve(N-2, v);
                choose[i]=choose[j]=0;
                v[i]=v[j]=0;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, m, a, b;

    cin>>t;
    while(t--){
        mp.clear();
        for(int i=0; i<10; i++){
            choose[i]=0;
            for(int j=0; j<10; j++){
                fr[i][j]=0;
            }
        }
        cin>>n>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            fr[a][b]=1;
            fr[b][a]=1;
        }
        vector<int> v(10, 0);
        solve(n, v);
        cout<<ans<<"\n";
        ans=0;
    }
}
