#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    deque<int> inc, dec;
    int l = 0, res = 0;

    for(int r = 0; r < n; r++){
        while(!inc.empty() && a[inc.back()] < a[r])
            inc.pop_back();
        
        while(!dec.empty() && a[dec.back()] > a[r])
            dec.pop_back();

        inc.push_back(r);
        dec.push_back(r);

        while(a[inc.front()] - a[dec.front()] > k){
            l = min(dec.front(), inc.front()) + 1;

            while(dec.front() < l) dec.pop_front();
            while(inc.front() < l) inc.pop_front();
        }
        res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}