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

    string s, t;
    cin>>s>>t;

    vector<vi> cnt(2, vi(26, 0));
    int n = s.length();
    for(int i = 0 ; i < n; i++)
        cnt[i % 2][s[i] - 'a']++;

    for(int i = 0; i < n; i++){
        if(cnt[i % 2][t[i] - 'a'] > 0)
            cnt[i % 2][t[i] - 'a']--;
        else return cout<<0, 0;
    }
    cout<<1;
    return 0;
}

// abcdba
// cabdab

// abe
// bea

// iovkcosxlypaqaaco
// ioaxvyaclaqkocsop

// fbrsoqfavcbliooinbezgxzdnzsrbdskntew
// gobtbbnkscbreovqnlszzdfsodrwiinxfzea