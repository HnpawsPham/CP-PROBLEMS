#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn], p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    p[0] = 0;
    for(int i = 1; i<=n;i++){
        cin>>a[i];
        p[i] = a[i] ^ p[i - 1];
    }

    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<(p[r] ^ p[l - 1])<<el;
    }

    return 0;
}