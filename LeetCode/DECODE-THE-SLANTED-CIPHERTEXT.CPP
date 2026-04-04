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

int n, m;

int id(int i, int j){
    return i * m + j;
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
    getline(cin, s);
    cin>>n;

    m = s.length() / n;
    string res;
    for(int st = 0; st < m; st++){
        int i = 0, j = st;

        while(i < n && j < m){
            res.push_back(s[id(i, j)]);
            i++;
            j++;
        }
    }
    while(!res.empty() && res.back() == ' ') res.pop_back();
    cout<<res;
    return 0;
}

// ch   ie   pr
// 3

// iveo    eed   l te   olc
// 4

// coding
// 1