#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e6 + 5;;
bool nprime[maxn];

void sieve(){
    for(int i = 2 ; i < sqrt(maxn); i++){
        if(!nprime[i])
        for(int j = i + i; j < maxn; j+=i) nprime[j] = 1;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    sieve();
    
    int i = 0, j = 2;
    while(i < n){
        if(!nprime[j]){
            cout<<j<<" ";
            i++;
        }
        j++;
    }

    return 0;
}