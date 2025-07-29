#include <iostream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
#define el '\n'

const int maxn = 1e7;
bitset<maxn> nprime;

void sieve(){
    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, l, r;
    cin>>t;

    sieve();
    vector<double> p(maxn, 0);
    vector<int> cnt(maxn, 0);

    for(int i = 2; i < maxn; i++){
        p[i] = p[i - 1] + (nprime[i] ? 0 : i);
        cnt[i] = cnt[i - 1] + (!nprime[i]);
    }

    while(t--){
        cin>>l>>r;
        int qt = cnt[r] - cnt[l - 1];
        double avg = (p[r] - p[l - 1]);
        if(qt != 0) avg /= qt;

        cout<<fixed<<setprecision(2)<<avg<<el;
    }

    return 0;
}

// 2
// 1 10
// 10 20