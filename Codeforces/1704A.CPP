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
//#define taskname ""

int tc = 1;

string sol(){
    int n, m;
    string a, b;
    cin>>n>>m>>a>>b;
    
    for(int i = 1; - m + i < 0; i++)
        if(a[n - m + i] != b[i]) return "NO";

    for(int i = 0; i < n - m + 1; i++)
        if(a[i] == b[0]) return "YES";
    return "NO";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}