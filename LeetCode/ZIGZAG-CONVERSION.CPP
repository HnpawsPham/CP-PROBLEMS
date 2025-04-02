#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
int row;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str>>row;
    if(row == 1) return cout<<str, 0;

    string res = "";
    int n = str.length(), d = 2 * (row - 1);

    for(int i = 0; i < row; i++)
        for(int j = i; j < n; j+= d){
            res += str[j];
            
            if(i > 0 && i < row - 1 && j + d - 2 * i < n)
                res += str[j + d - 2 * i];
        }
    cout<<res;

    return 0;
}