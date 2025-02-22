#include <iostream>
using namespace std;

string str;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    n = str.length();
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if('0' <= str[i] && str[i] <= '9') cnt++;
    cout<<cnt;

    return 0;
}