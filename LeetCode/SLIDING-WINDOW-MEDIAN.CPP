#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    multiset<int> ms(a.begin(), a.begin() + k);
    vector<db> res;
    auto mid = next(ms.begin(), k / 2);

    for(int i = k; ; i++){
        res.push_back((db)(*mid + *prev(mid, 1 - (k % 2))) / 2);
        if(i == n) break;

        ms.insert(a[i]);

        if(a[i] < *mid) mid--;
        if(a[i - k] <= *mid) mid++;

        ms.erase(ms.lower_bound(a[i - k]));
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 8 3
// 1 3 -1 -3 5 3 6 7