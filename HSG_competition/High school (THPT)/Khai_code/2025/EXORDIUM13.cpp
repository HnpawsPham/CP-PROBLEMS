#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    
    int cnt = 0;
    for(int c = 5; c<=n; c++)
        for(int b = 4; b < c; b++)
            for(int a = 3; a < b; a++)
                if(a * a + b * b == c * c) cnt++;
    cout<<cnt;

    return 0;
}
