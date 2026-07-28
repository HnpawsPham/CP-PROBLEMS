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
    int cnt[26] = {0};
    for(const char& x : s)
        cnt[x - 'a']++;

    string l, r;
    int mid = -1;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < cnt[i] / 2; j++){
            l.push_back(i + 'a');
            r.push_back(i + 'a');
        }
        if(cnt[i] % 2)
            mid = i;
    }

    if(mid != -1)
        l.push_back(mid + 'a');

    reverse(r.begin(), r.end());

    cout<<l<<r;
    return 0;
}