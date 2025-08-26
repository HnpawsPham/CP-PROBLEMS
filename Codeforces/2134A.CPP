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

bool sol(){
    int n, a, b;
    cin>>n>>a>>b;
    if(a < b) return (n - b) % 2 == 0;
    if((n - a) % 2 == 0 && (a - b) % 2 == 0) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<(sol() ? "YES" : "NO")<<el;
    }

    return 0;
}