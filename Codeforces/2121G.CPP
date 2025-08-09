#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, n;
ll sum;
string s;

void sol(){
    sum = 0;

    for(int i = 1; i <= n; i++)
        sum += 1LL * i * (n - i + 1);

    int p[n] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (s[i - 1] == '0') - (s[i - 1] == '1');

    sort(p, p + n + 1);

    for(int i = 0; i <= n; i++)
        sum += 1LL * p[i] * (2 * i - n);

    sum /= 2;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>s;
        sol();
        cout<<sum<<el;
    }

    return 0;
}