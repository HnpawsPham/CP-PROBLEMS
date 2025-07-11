#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    ll cnt1 = 0, cnt2 = 0;
    
    int odd = 1, even = 2, cnt_odd = 0, cnt_even = 0, x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x & 1) {
            cnt1 += abs(i - odd);
            odd += 2;
            cnt_odd++;
        }
        else{
            cnt2 += abs(i - even);
            even += 2;
            cnt_even++;
        }
    }
    cout<<(cnt_even == n / 2 && cnt_odd == (n + 1) / 2 ? cnt1 : -1);
    return 0;
}