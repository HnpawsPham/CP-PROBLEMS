#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t;
ll a, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while (t--) {
        cin >> a >> n;
        a %= 10; 

        vi res;
        int x = a;
        do {
            res.push_back(x);
            x = (x * a) % 10;
        } while (x != res[0]);

        int len = res.size();
        int idx = (n - 1) % len; 
        cout << res[idx]<<el;
    }
    return 0;
}