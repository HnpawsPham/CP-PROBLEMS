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

int n;
unordered_map<string, int> mp, id = {
    {"S", 0},
    {"M", 1},
    {"L", 2},
    {"XL", 3},
    {"XXL", 4}
};
string sz[5] = {"S", "M", "L", "XL", "XXL"};

bool check(int i){
    if(0 <= i && i < 5) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>mp["S"]>>mp["M"]>>mp["L"]>>mp["XL"]>>mp["XXL"]>>n;

    while(n--){
        string s;
        cin>>s;
        for(int i = 0; i < 5; i++)
            for(int j : {1, -1}){
                int cur = id[s] + i * j;
                if(check(cur) && mp[sz[cur]]) {
                    cout<<sz[cur]<<el;
                    mp[sz[cur]]--;
                    goto here;
                }
            }
        here:
    }
    return 0;
}