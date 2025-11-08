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

string s, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;
    int n = s.length();
    int l = 0, r = 0;

    while(l < n - 1 && s[l] == t[l]) l++;
    while(r < n - 1 && s[n - r - 1] == t[n - r - 2]) r++;

    int st = max(n - r, 1), en = min(n, l + 1);
    cout<<max(0, en - st + 1)<<el;
    for(int i = st; i <= en; i++)
        cout<<i<<" ";
    return 0;
}