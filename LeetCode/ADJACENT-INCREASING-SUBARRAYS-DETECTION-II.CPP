#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

bool check(int k, const vi& a){
    int sz = 1, prevsz = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]) sz++;
        else{
            prevsz = sz;
            sz = 1;
        }
        if(sz / 2 >= k || min(sz, prevsz) >= k) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 1, r = n / 2;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid, a)) l = mid + 1;
        else r = mid - 1;
    }
    cout<<l - 1;
    return 0;
}

// 10
// 2 5 7 8 9 2 3 4 3 1

// 10
// 1 2 3 4 4 4 4 5 6 7