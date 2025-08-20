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

int tc;

int sol(){
    int n, x, y;
    cin>>n>>x>>y;
    return (n + y / x - 1) / (y /x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	tc = 1;
	while(tc--){
        cout<<sol()<<el;
	}
    return 0;
}
