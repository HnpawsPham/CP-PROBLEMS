#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    bitset<5000005> nprime;

    for(int i = 2; i < sqrt(n); i++)
        if(!nprime[i])
            for(int j = i * i; j < n; j += i)
                nprime[j] = 1;

    int cnt = 0;
    for(int i = 2; i < n; i++) cnt += (!nprime[i]);
    cout<<cnt;
    return 0;
}