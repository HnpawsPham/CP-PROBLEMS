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

vector<string> a;

void sol(int i, int k, string s){
    if(i == k){
        a.push_back(s);
        return;
    }

    sol(i + 1, k, s + '1');
    sol(i + 1, k, s + '0');
    return;
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
    int k;
    cin>>s>>k;

    sol(0, k, "");
    int n = s.length();
    unordered_set<string> us;
    for(int i = 0; i <= n - k; i++)
        us.insert(s.substr(i, k));

    for(const string& x : a)
        if(us.find(x) == us.end())
            return cout<<0, 0;
    cout<<1;
    return 0;
}

// 00110110
// 2