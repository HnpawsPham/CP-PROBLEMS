#include<bits/stdc++.h>
using namespace std;
#define el "\n"

string str;
int p[] = {9, 7 , 3};
int sum = 0, pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    int n = str.length();

    for(int i = 0;i<n;i++){
        int d = (i + 3) % 3;
        if(str[i] == '?') pos = d;
        else sum += int(str[i] - '0') * p[d];
    }

    for(int i = 0; i<10;i++){
        int t = sum + i * p[pos];
        if(t % 10 == 0){
            cout<<t<<el;
            break;
        }
    }

    return 0;
}