#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string s;
int n;

int main(){
    // freopen("AF20.inp", "r", stdin);
    // freopen("AF20.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n = s.length();

    int pa[n + 1] = {0}, 
    pb[n + 1] = {0}, 
    pc[n + 1] = {0};

    for(int i = 0; i < n; i++){
        pa[i + 1] = pa[i] + (s[i] == 'A');
        pb[i + 1] = pb[i] + (s[i] == 'B');
        pc[i + 1] = pc[i] + (s[i] == 'C');
    }

    // sub1
    ll cnt = 0;
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;

    for(int i = 0; i < n; i++){
        int d1 = pa[i + 1] - pb[i + 1];
        int d2 = pa[i + 1] - pc[i + 1];

        cnt += mp[{d1, d2}];
        mp[{d1, d2}]++;
    }
    cout<<cnt;
    return 0;
}