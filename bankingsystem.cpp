
//    . *Basic: Simple Banking System*
//    - *Objective*: Implement a basic banking system that allows users to create accounts, deposit money, withdraw money, and check balances.
//    - *Key Concepts*: Classes, objects, constructors, methods, and encapsulation.
//    - *Tasks*:
//      - Create a BankAccount class with attributes like accountNumber, accountHolder, and balance.
//      - Implement methods for deposit, withdrawal, and checking the balance.
//      - Ensure balance cannot go negative.


#include<iostream>
using namespace std;
   class bankAccount
   {
   private:
    string name ;
    double balance=0.0 ;
    int accountNumber;
   public:

    bankAccount(string your_name , int your_accountNO){
        name=your_name;
        accountNumber=your_accountNO;
    }

    void deposit_money(int amount){
        if(amount>0){
            balance=balance+amount;
            cout<<"amount deposited is "<<amount<<endl;
            cout<<"your current balance is "<<balance<<endl;
        }
       else{
           cout<<"invalid amount! please give a valid amount."<<endl;
       }
    }
    void withdraw_money(int amount){
        if (amount>0){
            if (balance<amount){
                 cout<<"you are trying to withdraw "<<amount<<" but you dont have enough cash "<<endl;
                     }
             else {
                cout<<"withdrawl amount:"<<amount<<endl;
                balance=balance-amount;
                cout<<"remaning balance:"<<balance<<endl;
        }
        }
        else{
            cout<<"enter valid amount"<<endl;
        }
       
    }
     void check_balance(){
        cout<<"account holder name:"<<name<<endl;
        cout<<"account number:"<<accountNumber<<endl;
         cout<<"your balance is "<<balance<<endl;
     }
        };
   


int main(){
   
     bankAccount A1("prashant",410);

     A1.deposit_money(500);
     
     while(true){
                cout<<"Press 1 to deposit money"<<endl;
                cout<<"Press 2 to withdraw money"<<endl;
                cout<<"Press 3 to check balance "<<endl;
             int n;
             int amount;
                cin>> n ;
                switch(n){
                    case 1 :
                    cout<<"enter the amount you want to deposit "<<endl;
                    cin>>amount;
                    A1.deposit_money(amount);
                    break;
                    case 2 :
                    cout<<"enter the amount you want to withdraw "<<endl;
                    cin>>amount;
                    A1.withdraw_money(amount);
                    break;
                    case 3:
                    A1.check_balance();
                    break;
                    default:
                    cout<<"invalid option chosen. please choose a valid option "<<endl;
                    break;
                }
             }
        
    return 0;
}