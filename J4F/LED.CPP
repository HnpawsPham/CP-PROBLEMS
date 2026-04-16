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

int q, sz = 0, cnt = 0;
ll n;
string s;

int mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vi g[10] = {
    {0, 8}, //0
    {0, 1, 3, 4, 7, 8, 9}, //1
    {2, 8}, //2
    {3, 8, 9}, //3
    {4, 8, 9}, //4
    {5, 6, 8, 9}, //5
    {6, 8}, //6
    {0, 3, 7, 8, 9}, //7
    {8}, //8
    {8, 9} //9
};

void sol(string& ss, int i, bool first, bool larger){
    if(i == sz){
        if(larger) cnt++;
        return;
    }

    for(const int& x : g[s[i] - '0']){
        if(first && x == 0) continue;
        if(!larger && x < s[i] - '0') continue;

        ss.push_back(x + '0');
        sol(ss, i + 1, 0, larger || (x > s[i] - '0'));
        ss.pop_back();
    }
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

    cin>>q>>n;
    s = to_string(n);
    sz = s.length();

    if(q == 1){
        for(const char& x : s)
            cnt += mp[x - '0'];
    }
    else{
        string tmp = "";
        sol(tmp, 0, 1, 0);
    }
    cout<<cnt;
    return 0;
}