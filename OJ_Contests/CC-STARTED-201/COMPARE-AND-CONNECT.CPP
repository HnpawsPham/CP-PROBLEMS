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

string sol(){
    int n, m;
    cin>>n>>m;
    string res = "";
    
    if(n == 0){
        res += '>';
        for(int i = 0; i < m - 2; i++) res += "<>";
        res += "=>";
    }
    else if(m == 0){
        for(int i = 0; i < 2 * n - 3; i++)
            res += '<';
        res += "=<";
    }
    else{
        for(int i = 0; i < 2 * n; i++)
            res += '<';
        for(int i = 1; i < m; i++)
            res += "><";
        res += '>';
    }
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
