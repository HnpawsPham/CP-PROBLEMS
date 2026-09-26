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
#define vs vector<string>
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    string s;
    cin>>s>>m;
    vector<vs> a(m, vs(2));

    for(int i = 0; i < m; i++)
        cin>>a[i][0]>>a[i][1];

    unordered_map<string, string> mp;
    for(const vs& x : a)
        mp[x[0]] = x[1];

    string res = "", tmp = "";
    bool inbracket = 0;
    for(const char& x : s){
        if(x == '(') inbracket = 1;
        else if(x == ')'){
            if(!tmp.empty()){
                if(mp.count(tmp))
                    res += mp[tmp];
                else res.push_back('?');
                tmp = "";
            }
            inbracket = 0;
        }

        if('a' <= x && x <= 'z'){
            if(inbracket) tmp.push_back(x);
            else res.push_back(x);
        }
    }
    cout<<res;
    return 0;
}

// (name)is(age)yearsold
// 2
// name bob
// age two