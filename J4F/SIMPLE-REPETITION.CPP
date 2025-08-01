#include <bits/stdc++.h>
using namespace std;
#define el '\n'

bool checkp(int x){
    if(x < 2) return 0;
    int cnt = 0;
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0) return 0;

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, x, k;
    cin>>t;
    while(t--){
        cin>>x>>k;
        if(x == 1 && k == 2) cout<<"YES"<<el;
        else if(k == 1) cout<<(checkp(x) ? "YES" : "NO")<<el;
        else cout<<"NO"<<el;
    }
    return 0;
}