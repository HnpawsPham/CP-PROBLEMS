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

int n, cnt = 0;
const int maxn = 105;
bitset<maxn> nprime;
int a[25];
bool check[25] = {0};
vector<string> res;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

void sol(int i){
    if(i == n){
        if(nprime[a[n - 1] + 1]) return;
        cnt++;

        if(res.size() == 10000) return;
        string s;
        for(int i = 0; i < n; i++){
            s = s + to_string(a[i]);
            s.push_back(' ');
        }
        res.push_back(s);
        return;
    }

    for(int j = 2; j <= n; j++){
        if(!check[j] && !nprime[j + a[i - 1]]){
            check[j] = 1;
            a[i] = j;
            sol(i + 1);
            check[j] = 0;
        }
    }
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

    cin>>n;
    n <<= 1;
    sieve();

    a[0] = 1;
    sol(1);

    cout<<cnt<<el;
    for(const string& s : res) cout<<s<<el;
    return 0;
}