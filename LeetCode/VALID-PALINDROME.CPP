#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    string str = "";

    for(char x : s){
        x = tolower(x);
        if(('a' <= x && x <= 'z') || ('0' <= x && x <= '9'))
            str += x;
    }
    int n = str.length();
    for(int i = 0; i < n / 2; i++)
        if(str[i] != str[n - i - 1]) return cout<<"False", 0;

    cout<<"True";
    return 0;
}