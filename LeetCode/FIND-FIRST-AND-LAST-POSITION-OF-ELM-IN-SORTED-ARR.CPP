#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vi res = {-1, -1};
    int l = 0, r = n - 1, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] >= k) {
            if(a[mid] == k) res[0] = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    l = 0; r = n - 1; mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] <= k) {
            if(a[mid] == k) res[1] = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout<<res[0]<<" "<<res[1];
    return 0;
}

// 6 8
// 5 7 7 8 8 10 