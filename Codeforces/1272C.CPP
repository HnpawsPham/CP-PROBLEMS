#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin>>n>>k>>s;
    int cnt[26] = {0};

    while(k--){
        char x;
        cin>>x;
        cnt[x - 'a']++;
    }

    int l = -1;
    ll res = 0;
    for(int r = 0; r < n; r++){
        if(cnt[s[r] - 'a']){
            if(l == -1) l = r;
            res += r - l + 1;
        }
        else l = -1;
    }
    cout<<res;
    return 0;
}