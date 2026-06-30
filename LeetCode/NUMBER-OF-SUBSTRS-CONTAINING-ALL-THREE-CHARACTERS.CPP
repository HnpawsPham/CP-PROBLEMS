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

int cnt[3];

bool check(){
    for(int i = 0; i < 3; i++)
        if(!cnt[i]) return 0;
    return 1;
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

    memset(cnt, 0, sizeof cnt);
    int n = s.length(), l = 0, res = 0;
    for(int r = 0; r < n; r++){
        cnt[s[r] - 'a']++;

        while(l <= r && check()){
            cnt[s[l] - 'a']--;
            l++;
        }

        res += l;
    }
    cout<<res;
    return 0;
}