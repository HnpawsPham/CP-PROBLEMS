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
    int l = 0, res = 0, maxx = 0;

    for(int r = 0; r < n; r++){
        maxx = max(maxx, ++cnt[s[r] - 'A']);

        while(r - l + 1 - maxx > k){
            cnt[s[l] - 'A']--;
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}