#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

int main(){
    // freopen("BECA.INP", "r", stdin);
    // freopen("BECA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    deque<int> inc, dec;
    int l = 0, res = 0;

    for(int i = 0; i < n; i++){
        while(!inc.empty() && a[inc.back()] < a[i])
            inc.pop_back();

        while(!dec.empty() && a[dec.back()] > a[i])
            dec.pop_back();
        
        inc.push_back(i);
        dec.push_back(i);

        while(a[inc.front()] - a[dec.front()] > k){
            l = min(inc.front(), dec.front()) + 1;

            while(inc.front() < l) inc.pop_front();
            while(dec.front() < l) dec.pop_front();
        }
        res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}