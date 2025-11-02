#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x1, x2, v1, v2;
    cin>>x1>>x2>>v1>>v2;
    if(v1 - v2 == 0) cout<<-1;
    else cout<<fixed<<setprecision(4)<<(db)(x2 - x1) / (db)(v1 - v2);
    return 0;
}

// -1 5 1 -2

// -1 5 1 1
