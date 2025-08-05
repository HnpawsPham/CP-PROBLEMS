#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int t, n, x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        ll cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            cin>>x;
            
            if(x == 1) cnt1++;
            else {
                cnt1 += x - 2;
                cnt2 ++;
            }
        }
        cout<<1LL * cnt1 / 2 +  1LL * cnt2 / 2<<el;
    }
    return 0;
}