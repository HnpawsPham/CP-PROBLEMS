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

int cnt[26];

ll cntpos(){
    ll res = 1;
    int fact = 1;

    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= cnt[i]; j++){
            res = res * fact / j;
            fact++;

            if(res > 1000000) res = 1000001;
        }
    }
    return res;
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

    int n = s.length();
    memset(cnt, 0, sizeof cnt);

    for(const char& x : s)
        cnt[x - 'a']++;

    char mid = '\0';
    for(int i = 0; i < 26; i++){
        if(cnt[i] % 2) mid = i + 'a';
        cnt[i] /= 2;
    }

    if(k > cntpos()) 
        return cout<<"", 0;

    string res = "";
    for(int i = 0; i < n / 2; i++)
        for(int j = 0; j < 26; j++){
            if(cnt[j] == 0) continue;

            cnt[j]--;
            ll way = cntpos();
            if(way >= k){
                res.push_back(j + 'a');
                break;
            }

            k -= way;
            cnt[j]++;
        }

    string rs = res;
    reverse(rs.begin(), rs.end());
    cout<<res + mid + rs;
    return 0;
}