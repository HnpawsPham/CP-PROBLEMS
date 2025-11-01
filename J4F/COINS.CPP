#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll n, k, a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>a>>b;
    while(n){
        if(a < b) a += k;
        else b += k;
        n--;
    }
    cout<<abs(a - b);
    return 0;
}

// 4 3 12 23