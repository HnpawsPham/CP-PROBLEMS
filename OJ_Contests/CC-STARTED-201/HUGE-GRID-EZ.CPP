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

ll sol(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    if(n == 1) return (s[0] - '0');
    
    ll res = 0;
    res += 2 * (s[0] - '0');
    res += 2 * (s[n - 1] -'0');
    for(int i = 1; i < n - 1; i++)
        res += 3 * (s[i] - '0');
    
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin>>tc;
	while(tc--){
        cout<<sol()<<el;
	}
    return 0;
}
