#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    int pos = 0;
    while(q--){
        int opt;
        cin>>opt;
        if(opt == 1){
            int c;
            cin>>c;
            pos = (pos + c) % n;
        }
        else{
            int l, r;
            cin>>l>>r;

            int ll = (l - 1 + pos) % n + 1;
            int rr = (r - 1 + pos) % n + 1;

            if(ll <= rr) cout<<p[rr] - p[ll - 1]<<el;
            else cout<<p[n] - p[ll - 1] + p[rr]<<el;
        }
    }
    return 0;
}