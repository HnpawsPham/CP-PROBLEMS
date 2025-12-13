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

int n, s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    if((s > 9 * n) || (s == 0 && n > 1)) 
        return cout<<-1<<" "<<-1, 0;

    if(n == 1 && s == 0) return cout<<0<<" "<<0, 0;

    string small(n, '0'), big;
    int sum = s;
    for(int i = 0; i < n; i++){
        int x = min(sum, 9);
        big.push_back(x + '0');
        sum -= x;
    }

    sum = s - 1;
    small[0] = '1';
    for(int i = n - 1; i >= 0; i--){
        int tmp = small[i] - '0';
        int x = min(9 - tmp, sum);
        small[i] = tmp + x + '0';
        sum -= x;
    }
    cout<<small<<" "<<big;
    return 0;
}