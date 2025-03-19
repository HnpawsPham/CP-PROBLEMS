#include <iostream>
#include <string>
using namespace std;
#define el "\n"

int n; 
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>str;
    string s = "";
    for(int i = 0; i < n; i++) s = s + '|' + str[i];
    s += '|';
    n = s.length();

    int p[n] = {};
    int r = 0, c = 0, res = 0;
    for(int i = 1; i < n; i++){
        if(i < r)
            p[i] = min(p[2 * c - i], r - i);

        while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) 
            p[i]++;

        if(i + p[i] >= r){
            r = i + p[i];
            c = i;
        }

        res = max(res, p[i] - 1);
    }
    cout<<res;

    return 0;
}