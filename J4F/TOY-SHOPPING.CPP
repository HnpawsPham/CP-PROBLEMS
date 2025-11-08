#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

string sol(){
    int n, x;
    cin>>n>>x;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }

    if(x <= n / 2) return "YES";

    sort(b, b + n);
    for(int i = n - x; i < x; i++)
        if(a[i] != b[i]) return "NO";
    return "YES";
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

// 4
// 3 3
// 5 3 1
// 4 3
// 1 3 5 7
// 5 2
// 5 1 2 3 4
// 5 4
// 1 2 3 4 4