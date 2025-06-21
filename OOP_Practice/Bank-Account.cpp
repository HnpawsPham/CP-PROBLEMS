#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string unit = "USD";

class Account{
    private:
        int PIN;
        string id;
        vector<ll> exchange_history;

        void showExchangeHistory(){
            for(const ll& amount : exchange_history){
                if(amount > 0)
                    cout<<"Your bank account received "<<amount<<unit<<el;

                else cout<<"Your bank account decreased "<<-amount<<unit<<el;
            }
            return;
        }

    public:
        ll balance = 0;
        string name;

        void showBalance(){
            cout<<"Your balance: "<<balance<<unit<<el;
            return;
        }

        void addMoney(ll amount){
            balance += amount;
            exchange_history.push_back(amount);

            cout<<"Added "<<amount<<unit<<" to your account"<<el;
            showBalance();
            return;
        }

        void getMoney(ll amount){
            if(amount > balance){
                cout<<"You don't have enough money!"<<el;
                return;
            }

            balance -= amount;
            exchange_history.push_back(-amount);

            cout<<"Get "<<amount<<unit<<" successfully!"<<el;
            showBalance();
            return;
        }

        void changePIN(){
            int new_pin;
            cout<<"Your new PIN (6 digits): ";
            cin>>new_pin;

            if(new_pin >= 100000 && new_pin <= 999999){
                PIN = new_pin;
                cout<<"Your PIN is: "<<PIN<<el;
            }
            else cout<<"Your new PIN is invalid!";

            return;
        }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Account user_account;

    string username;
    cin>>username;
    user_account.name = username;

    user_account.showBalance();
    user_account.addMoney(1000);

    // user_account.changePIN();
    return 0;
}