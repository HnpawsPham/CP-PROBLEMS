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

    int l, r;
    cin>>l>>r;
    l += 1 - (l % 2);
    r -= 1 - (r % 2);
    cout<<(r - l) / 2 + 1;
    return 0;
}