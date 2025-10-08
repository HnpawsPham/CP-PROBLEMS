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
ll k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(b.begin(), b.end(), greater<int>());

    vi res(n, 0);
    for(int i = 0; i < n; i++){
        int l = 0, r = m - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(1LL * b[mid] * a[i] >= k)
                l = mid + 1;
            else r = mid - 1;
        }
        res[i] = l;
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 3 5 7
// 5 1 3
// 1 2 3 4 5

// 3 3 16
// 3 1 2
// 8 5 8