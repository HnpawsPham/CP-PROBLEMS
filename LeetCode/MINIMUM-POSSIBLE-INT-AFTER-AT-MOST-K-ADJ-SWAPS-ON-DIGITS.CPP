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

int n;
const int maxn = 3e4 + 5;
int bit[maxn];
deque<int> pos[10];

void update(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += (i & -i);
    }
}

int get(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
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
    string s;
    cin>>s>>k;
    n = s.length();

    for(int i = 0; i < n; i++)
        pos[s[i] - '0'].push_back(i + 1);

    string res;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 9; j++){
            if(pos[j].empty()) continue;
            int w = pos[j].front() - 1 - get(pos[j].front() - 1);

            if(w <= k){
                k -= w;
                update(pos[j].front(), 1);

                res.push_back(j + '0');
                pos[j].pop_front();
                break;
            }
        }
    cout<<res;
    return 0;
}