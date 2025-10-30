#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
ll line(int x1, int y1, int x2, int y2, int x3, int y3){
    return 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    cin>>m;
    while(m--){
        int x, y;
        cin>>x>>y;

        bool ok = 1;
        for(int i = 0; i < n; i++){
            int j = (i + 1) % n;
            if(line(a[i].fi, a[i].se, a[j].fi, a[j].se, x, y) <= 0LL){
                ok = 0;
                break;
            }
        }
        cout<<ok<<el;
    }
    return 0;
}