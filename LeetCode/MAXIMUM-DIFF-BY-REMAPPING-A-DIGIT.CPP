#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string s = to_string(n);

    int minn = 0, maxx = 0;
    char min_char = s[0], max_char;

    for(char x : s)
        if(x != '9'){
            max_char = x;
            break;
        }

    for(char x : s){
        maxx = maxx * 10 + (x != max_char ? (x - '0') : 9);
        minn = minn * 10 + (x != min_char ? (x - '0') : 0);
    }
    cout<<maxx - minn;

    return 0; 
}