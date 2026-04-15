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

int n, k;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s;
    if(25 * n < k) return cout<<-1, 0;

    string res;
    int kk = k;
    for(const char& x :s){
        int i = x - 'a', d;
        if(i > 25 - i){
            res.push_back(char(i - min(i, k) + 'a'));
            d = min(i, k);
        }
        else{
            res.push_back(char(i + min(k, 25 - i) + 'a'));
            d = min(k, 25 - i);
        }
        k -= d;
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += abs((s[i] - 'a') - (res[i] - 'a'));

    if(sum < kk) cout<<-1;
    else cout<<res;
    return 0;
}