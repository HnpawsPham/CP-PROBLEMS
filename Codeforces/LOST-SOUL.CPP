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

int sol(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    bool check[n + 1] = {0};
    if(a[n - 1] == b[n - 1]) return n;

    int res = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || check[a[i]] || check[b[i]]) {
            res = i;
            break;
        }
        check[a[i + 1]] = check[b[i + 1]] = 1;
    }
	return res + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--) 
        cout<<sol()<<el;
    return 0;
}
