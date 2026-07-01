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

int n, res = 0;
int cnt[26] = {0};

void dfs(int i, int sum, const vector<string>& word, const vector<int>& w){
    if(i == n){
        res = max(res, sum);
        return;
    }

    dfs(i + 1, sum, word, w);

    bool ok = 1;
    int d = 0;
    vector<int> check;
    
    for(const char& x : word[i]){
        if(cnt[x - 'a'] > 0){
            d += w[x - 'a'];
            cnt[x - 'a']--;
            check.push_back(x - 'a');
        }
        else{
            ok = 0;
            break;
        }
    }

    if(ok) dfs(i + 1, sum + d, word, w);
    for(int x : check) cnt[x]++;
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

    int k;
    cin>>n>>k;
    vector<string> word(n);
    for(int i = 0; i < n; i++) cin>>word[i];

    vector<char> a(k);
    vi w(26);
    for(int i = 0; i < k; i++) cin>>a[i];
    for(int i = 0; i < 26; i++) cin>>w[i];

    for(const char& x : a)
        cnt[x - 'a']++;

    dfs(0, 0, word, w);
    cout<<res;
    return 0;
}

// 4 9
// dog cat dad good
// a a c d d d g o o 
// 1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0