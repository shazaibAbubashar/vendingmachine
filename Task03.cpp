#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class VendingMachine
{
private:
    int currentbalance;

public:
    VendingMachine()
    {
        currentbalance = 0;
    }
    void AcceptMoney(T amount)
    {
        currentbalance += amount;
    }
    T getcurrent_balance()
    {
        return currentbalance;
    }
    bool dispenseitem(T price, std::string name)
    {
        if (currentbalance > price)
        {
            currentbalance -= price;
            cout << "**************************" << endl;

            cout << "Name  " << name << endl
                 << "price " << price << endl;
            return true;
        }
        else
        {

            return false;
        }
    }
};
int main()
{
    VendingMachine<int> obj;
    int money;
    int choice = 0;
    do
    {
        cout << "1. Accept money\n";
        cout << "2. Display Current balance\n";
        cout << "3. Dispense an item\n";
        cout << "4. See Current balance\n";
        cout << "-1 Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            int amount;
            cout << "Enter amount : ";
            cin >> amount;
            obj.AcceptMoney(amount);
            cout << "*********************************************" << endl;
            cout << "Amount is added to the currenet balance\n";
            cout << "*********************************************" << endl;
        }
        else if (choice == 2)
        {
            cout << "*********************************" << endl;
            cout << "\tBalance : " << obj.getcurrent_balance() << endl;
            cout << "*********************************" << endl;
        }
        else if (choice == 3)
        {
            string name;
            int price;
            bool buy;
            cout << "Enter price of the item : ";
            cin >> price;
            cout << "Enter item name : ";
            fflush(stdin);
            getline(cin, name);
            cout << "Successfully!!!Item is dispensed\n";
            buy = obj.dispenseitem(price, name);
            if (buy == 1)
            {
                cout << "You can buy\t\n\n";
                cout << "**************************" << endl;
            }
            else
            {
                cout << "******************************************" << endl;
                cout << "You can't buy because of less money\n";
                cout << "******************************************" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "*************************************************" << endl;
            cout << "After updation\n";
            cout << "Balance : " << obj.getcurrent_balance() << endl;
            cout << "*************************************************" << endl;
        }
    } while (choice = -1);

    return 0;
}