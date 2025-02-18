#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int t, x;
const int maxn = (int)1e6;
bool ok;
int p[maxn + 5];

int calc(int x){
    if(p[x] != -1) return p[x];

    int s = 0;
    while(x > 0){
        s += x % 10;
        x /= 10;
    }
    return p[x] = s;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(p, -1, sizeof(p));

    cin>>t;
    while(t--){
        cin>>x;
        ok = 0;

        if(x % 2 == 0){
            cout<<x/2<<" "<<x/2<<el;
            continue;
        }

        int l = x / 2;
        int r = x - l;

        while(l > 0 && r < x){
            if(calc(l) == calc(r)) {
                cout<<l<<" "<<r<<el;
                ok = 1;
                break;
            }
            l--;
            r++;
        }
        if(!ok) cout<<-1<<el;
    }

    // cin >> t;
    // while (t--) {
    //     cin >> x;
    //     if (x % 2 == 0) {
    //         cout <<x / 2<<" "<<x / 2<<el;
    //         continue;
    //     }

    //     int st = (5 * x % 9) % 9;
    //     bool found = 0;

    //     for (int l = st; l <= x / 2; l += 9) {
    //         int r = x - l;
    //         if (calc(l) == calc(r)) {
    //             cout <<l<<" "<<r<<el;
    //             found = 1;
    //             break;
    //         }
    //     }
    //     if (!found) cout<<-1<<el;
    // }
    return 0;
}
// 4
// 4
// 33
// 243
// 29