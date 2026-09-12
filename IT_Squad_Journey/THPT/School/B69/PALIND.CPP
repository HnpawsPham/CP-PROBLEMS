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
#define taskname "PALIND"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    bool ok = 1;
    for(int i = 0; i < n / 2 && ok; i++)
        if(s[i] != s[n - i - 1]) ok = 0;
    if(ok) return cout<<s, 0;

    string hl = "", hr, mid;

    if(n & 1) mid.push_back(s[n / 2]);
    for(int i = 0; i < n / 2; i++)
        hl.push_back(s[i]);
    hr = hl;
    reverse(hr.begin(), hr.end());

    if(hl + mid + hr < s){
        int rem = 1;
        if(n & 1) {
            int x = (mid[0] - '0') + rem;
            mid[0] = (x % 10) + '0';
            rem = x / 10;
        }
        for(int i = n / 2 - 1; i >= 0 && rem; i--) {
            int x = (hl[i] - '0') + rem;
            hl[i] = (x % 10) + '0';
            rem = x / 10;
        }
        hr = hl;
        reverse(hr.begin(), hr.end());
    } 
    cout<<hl + mid + hr;
    return 0;
}