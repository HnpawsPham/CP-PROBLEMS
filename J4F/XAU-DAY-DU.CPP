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
ll res = 0;
vector<string> a;

bool check(const string& s){
    bitset<26> cnt;
    for(const char& x : s)
        cnt[x - 'a'] = 1;

    return cnt.all();
}

void sol(int i, string s){
    if(check(s)){
        res += (1LL << (n - i));
        return; 
    }
    if(i == n) return;

    sol(i + 1, s);
    sol(i + 1, s + a[i]);
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

    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        a.push_back(s);
    }

    sol(0, "");
    cout<<res;
    return 0;
}