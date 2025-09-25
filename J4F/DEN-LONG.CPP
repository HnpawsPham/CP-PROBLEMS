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
    // freopen("DL.INP", "r", stdin);
    // freopen("DL.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    int a[n] = {0};
    for(int i = 0; i < n; i++){
        if(s[i] == 'V') a[i] = 1;
        else a[i] = -2;
    }

    int sum = 0, res = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for(int i = 0; i < n; i++){
        sum += a[i];
        if(mp.count(sum))
            res = max(res, i - mp[sum]);
        else mp[sum] = i;
    }
    cout<<res;
    return 0;
}
// VDVVDDVVD