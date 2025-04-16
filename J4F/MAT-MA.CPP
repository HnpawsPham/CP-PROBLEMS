#include <iostream>
#include <algorithm>
#include <vector>
#pragma GCC optimize("O2,Ofast,unroll-loops")
using namespace std;
using ll = long long;
#define el "\n"

string s;

int main(){
    // freopen("MATMA.INP", "r", stdin);
    // freopen("MATMA.OUT", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int sum = 0;
    bool found0 = 0;
    vector<int> num;

    for(char ch : s){
        int x = ch - '0';

        sum += x;
        if(x == 0) found0 = 1;
        num.push_back(x);
    }

    if(!found0 || sum % 3 != 0) return cout << -1, 0;

    sort(num.begin(), num.end(), greater<int>());
    for(int x : num) cout<<x;

    return 0;
}