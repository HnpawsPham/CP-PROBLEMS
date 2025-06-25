#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m, k;
const int maxn = 5e4 + 5;
vector<int> a(maxn), b(maxn);

bool check(ll x){
    ll cnt = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            cnt = m * (x >= 0);
            continue;
        }

        int l = 0, r = m - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;

            if((a[i] > 0 && a[i] * b[mid] <= x)
            || (a[i] < 0 && a[i] * b[mid] >= x))
                l = mid + 1;
            
            else r = mid - 1;
        }

        if(a[i] > 0) cnt += l;
        else cnt += m - l;
    }
    return (cnt >= k); 
}

// bool check(ll x){
//     ll cnt = 0;

//     for(int i = 0; i < n; i++){
//         if(a[i] == 0){
//             cnt += m * (x >= 0);
//             continue;
//         }

//         ll target = x / a[i];

//         else if(a[i] > 0)
//             cnt += upper_bound(b.begin(), b.begin() + m, target) - b.begin();

//         else cnt += m - (lower_bound(b.begin(), b.begin() + m, target + (!x % a[i])) - b.begin());
//     }

//     return (cnt >= k);
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    ll l = -1e10, r = 1e10, mid;
    while(l <= r){
        mid = l + (r - l) / 2;

        if(check(mid))
            r = mid - 1;

        else l = mid + 1;
    }
    cout<<l;
    return 0;
}