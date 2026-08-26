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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin>>s>>k;

    int n = s.length();
    int cnt1[n + 1];
    cnt1[0] = 0;
    for(int i = 1; i <= n; i++)
        cnt1[i] = cnt1[i - 1] + (s[i - 1] == '1');

    string oo = string(n + 1, 'z');
    string res = oo;
    for(int i = 0; i < n; i++)
        for(int j = i + k - 1; j < n; j++)
            if(cnt1[j + 1] - cnt1[i] == k){
                string t = s.substr(i, j - i + 1);

                if(t.size() < res.size())
                    res = t;
                else if(res.size() == t.size())
                    res = min(res, t);
            }
    cout<<(res == oo ? "" : res);
    return 0;
}

// 100011001 3