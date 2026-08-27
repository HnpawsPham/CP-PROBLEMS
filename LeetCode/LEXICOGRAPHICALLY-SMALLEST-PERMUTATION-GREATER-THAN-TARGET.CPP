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

bool sol(int i, bool ok, const string& s, const string& t, string& res){
    if(i == n) return ok;

    if(ok){
        for(int j = 0; j < 26; j++){
            while(cnt[j] > 0){
                cnt[j]--;
                res.push_back(j + 'a');
            }
        }
        return 1;
    }

    for(int x = t[i]; x <= 'z'; x++){
        if(!cnt[x - 'a']) continue;
        
        cnt[x - 'a']--;
        res.push_back(x);

        if(sol(i + 1, ok || x > t[i], s, t, res)) 
            return 1;

        res.pop_back();
        cnt[x - 'a']++;
    }
    return 0;
}

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

    int n = s.length();
    memset(cnt, 0, sizeof cnt);
    for(const char& x : s)
        cnt[x - 'a']++;

    string res = "";
    if(sol(0, 0, s, t, res))
        return cout<<res, 0;
    cout<<"";
    return 0;
}

// abc bba
// leet code
// baba bbaa