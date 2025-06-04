#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    unordered_map<int, int> mp;

    while(n != 1 && n != 7){
        if(mp[n]) return cout<<false, 0;

        mp[n]++;

        int sum = 0;
        int x = n;
        while(x > 0){
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        n = sum;
    }
    cout<<true;
    return 0;
}