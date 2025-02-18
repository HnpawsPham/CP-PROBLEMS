#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
void move(int i, char a, char b, char c){
    if(i < 1) return;

    move(i - 1, a, c, b);
    cout<<i<<" "<<a<<" "<<b<<el;
    move(i - 1, c, b, a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    move(n, 'A', 'B', 'C');

    return 0;
}