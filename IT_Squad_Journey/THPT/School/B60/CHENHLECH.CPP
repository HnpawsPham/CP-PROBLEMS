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
#define taskname "CHENHLECH"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;

    vi pos[26];
    for(int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);

    int res = 0;
    for(char a = 0; a < 26; a++){
        if(pos[a].empty()) continue;

        for(char b = 0; b < 26; b++){
            if(a == b || pos[b].empty()) continue;

            int tmp = 0, sum = -n - 10;
            int i = 0, j = 0, m = pos[a].size(), k = pos[b].size();

            while(i < m || j < k){
                if(i < m && (j == k || pos[a][i] < pos[b][j])){
                    i++;
                    tmp++;
                    sum++;
                }
                else{
                    sum = max(sum - 1, tmp - 1);
                    tmp = 0;
                    j++;
                }
                res = max(res, sum);
            }
        }
    }
    cout<<res;
    return 0;
}