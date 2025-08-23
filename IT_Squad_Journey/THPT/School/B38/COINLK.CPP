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
    freopen("COINLK.INP", "r", stdin);
    freopen("COINLK.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int cnts = 0, cntn = 0;
        for(const char& x : s){
            cnts += (x == 'S');
            cntn += (x == 'N');
        }

        int gcd = __gcd(cnts, cntn);
        cnts /= gcd;
        cntn /= gcd;

        cout<<cnts<<"/"<<cntn<<el;
    }

    return 0;
}