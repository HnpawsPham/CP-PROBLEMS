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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 1, prev = 0, res = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) cnt++;
        else {
            prev = cnt;
            cnt = 1;
        }
        res = max({res, cnt / 2, min(prev, cnt)});
    }
    cout<<(res >= k);
    return 0;
}