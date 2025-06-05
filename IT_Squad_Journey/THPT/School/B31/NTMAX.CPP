#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
const int maxn = 5e6 + 5;
bool nprime[maxn] = {0};

void sieve(){
    nprime[1] = nprime[0] = 1;

    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i + i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);
    sieve();
    
    int num = 0, res = 0;
    
    for(char x : s)
        if('0' <= x && x <= '9') 
            num = num * 10 + (x - '0');
        else {
            if(!nprime[num] && num > res)
                res = num;

            num = 0;
        }
    
    if(!nprime[num] && num > res)
        res = num;
        
    cout<<res;
    return 0;
}
// Tin011hoc230lop124muoi17