#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k;

    char ch = 'a';
    int len = 1, d = 0;

    while(len < k)
        len *= 2;
    
    while(k != 1){
        len /= 2;

        if(k > len) {
            d++;
            k -= len;
        }
    }
    
    cout<<char((d % 26) + 'a');
    return 0;
}