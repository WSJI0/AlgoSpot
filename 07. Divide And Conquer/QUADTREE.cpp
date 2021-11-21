#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int pointer=0;

string solve(){
    if(pointer==s.size()) return "";
    char p=s[pointer++];
    if(p=='b') return "b";
    if(p=='w') return "w";

    string q[4];
    for(int i=0; i<4; i++) q[i]=solve();
    return "x"+q[2]+q[3]+q[0]+q[1];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        pointer=0;
        cin>>s;
        cout<<solve()<<"\n";
    }
}
