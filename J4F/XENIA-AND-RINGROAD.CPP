#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    ll res = 0;
    int pos = 1;
    while(m--){
        int x;
        cin>>x;

        if(x >= pos)
            res += x - pos;
        else res += (n - pos + x);
        pos = x;
    }
    cout<<res;
    return 0;
}