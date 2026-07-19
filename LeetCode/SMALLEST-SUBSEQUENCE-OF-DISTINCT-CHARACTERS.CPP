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

    int n = s.length();
    int cnt[26] = {0};
    bool check[26] = {0};

    for(const char& x : s)
        cnt[x - 'a']++;

    string res;
    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        cnt[x]--;

        if(check[x]) continue;

        while(!res.empty() && s[i] < res.back() && cnt[res.back() - 'a'] > 0){
            check[res.back() - 'a'] = 0;
            res.pop_back();
        }
        res.push_back(s[i]);
        check[x] = 1;
    }
    cout<<res;        
    return 0;
}