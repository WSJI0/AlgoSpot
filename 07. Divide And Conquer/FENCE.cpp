#include <bits/stdc++.h>
using namespace std;

int t, n, fence[20005];

int solve(int s, int e){
    if(s==e) return fence[s];
    int mid=(s+e)/2;

    int ret=max(solve(s, mid), solve(mid+1, e));

    int l=mid, h=mid+1;
    int height=min(fence[l], fence[h]);
    ret=max(ret, height*2);

    while(s<l || h<e){
        if(s<l && (h==e || fence[l-1]>fence[h+1])) 
            height=min(height, fence[--l]);
        else height=min(height, fence[++h]);
        ret=max(ret, height*(h-l+1));
    }

    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++) cin>>fence[i];
        cout<<solve(0, n-1)<<"\n";
    }
}
