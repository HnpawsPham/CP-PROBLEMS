#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n < 0 || (n % 10 == 0 && n != 0)) return cout<<"false", 0;

    int half = 0;
    while(n > half){
        half = half * 10 + n % 10;
        n/=10; 
    }
    return cout<<(half == n || half / 10 == n ? "true": "false"), 0;
}