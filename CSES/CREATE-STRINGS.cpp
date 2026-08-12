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
    cin>>s;
    sort(s.begin(), s.end());

    vector<string> a;
    do{
        a.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout<<a.size()<<el;
    for(const string& x : a)
        cout<<x<<el;
    return 0;
}