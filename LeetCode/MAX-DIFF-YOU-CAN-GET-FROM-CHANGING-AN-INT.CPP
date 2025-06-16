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
    int maxx = 0, minn = 0;
    char max_char = s[0], min_char = 'a';

    for(char x : s)
        if(x > '1'){
            min_char = x;
            break;
        }

    for(char x : s)
        if(x != '9'){
            max_char = x;
            break;
        }
    
    int num = 0;
    if(min_char == 'a' || min_char == s[0]){
        num = 1;
        min_char = s[0];
    }

    for(char x : s){
        maxx = maxx * 10 + (x != max_char ? (x - '0') : 9);
        minn = minn * 10 + (x != min_char ? (x - '0') : num);
    }
    cout<<maxx - minn;
    cout<<el<<maxx<<" "<<minn;
    return 0;
}