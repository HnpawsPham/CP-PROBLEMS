#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll sol(){
    int n;
    cin>>n;
    int a[n + 1] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];

    ll cnt = 0;
    int b[n + 1] = {0};
    for(int i = 0; i < n; i += 2){
        int x = a[i];

        if(i >= 2) x = min(x, a[i - 1] - b[i - 2]);
        if(i < n - 1) x = min(x, a[i + 1]);

        b[i] = x;
        cnt += a[i] - x;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}