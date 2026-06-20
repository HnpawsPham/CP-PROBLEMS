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
//#define taskname ""

int n;
bool check[10005] = {0};

vi sol(int l, int r, const string& s){
    if(l > r) return {};

    vi res;
    bool ok = 1;
    int x = 0;

    for(int i = l; i <= r; i++)
        if('0' <= s[i] && s[i] <= '9')
            x = x * 10 + (s[i] - '0');
        else{
            ok = 0;
            vi hl = sol(l, i - 1, s);
            vi hr = sol(i + 1, r, s);

            for(const int& a : hl)
                for(const int& b : hr){
                    if(s[i] == '+') res.push_back(a + b);
                    else if(s[i] == '-') res.push_back(a - b);
                    else if(s[i] == '*') res.push_back(a * b);
                }
        }

    if(ok) res.push_back(x);
    return res;
}

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
    n = s.length();
    vi res = sol(0, n - 1, s);
    for(int x : res) cout<<x<<" ";
    return 0;
}