#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

void sol() {
    if (n % 2 != 0) {
        for (int i = 1; i <= n; ++i) {
            if (i % 2 != 0) cout << -1;
            else cout << 3;

            if (i < n) cout << " ";
        }
        cout << el;
    } 
    else {
        for (int i = 1; i <= n - 2; ++i) {
            if (i % 2 != 0) 
                cout << -1 << " ";
            else cout << 3 << " ";
        }
        cout << -1 << " " << 2 << el;
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        sol();
    }

    return 0;
}