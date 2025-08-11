#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int neg = 0, cnt0 = 0;
    ll res = 0;
    while(n--){
        int x;
        cin>>x;
        
        if(x < 0) neg++;
        if(x == 0) cnt0++;
        res += llabs(llabs(x) - 1);
    }
    if(neg % 2 && cnt0 == 0) res += 2;
    cout<<res;
    return 0;
}