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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string f0, f1;
    int n;
    cin>>f0>>f1>>n;

    for(int i = 3; i <= n; i++){
        string tmp = f1 + f0;
        f0 = f1;
        f1 = tmp;
    }
    cout<<f1;
    return 0;
}

// a b 
// 6