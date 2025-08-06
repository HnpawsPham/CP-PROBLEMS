#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int t, n;

string sol() {
    int k = n + 35;
    int a[k] = {0}, b[k] = {0};

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    for(int i = 0; i < k - 1; ++i) {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;
    }
    for(int i = 0; i < k - 1; ++i) {
        b[i + 1] += b[i] / 2;
        b[i] %= 2;
    }

    for(int i = k - 1; i >= 0; --i) {
        if (a[i] > b[i]) return "YES";
        else if (a[i] < b[i]) return "NO";
    }

    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        cout<<sol()<<el;
    }
   
    return 0;
}