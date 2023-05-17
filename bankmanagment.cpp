// BANK MANAGEMENT PROJECT
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class bank
{
   char y, name[100], add[100];

   bool flag = false;
   int balance = 0;
    long long int adhar_no;
    long long int mob_no;
public:
   void open_account();
   void deposite_money();
   void withdraw_money();
   void display_account();
};

void bank::open_account()
{
   flag = true;
   cout << "enter your full name -> "<<endl;
   cin.ignore();
   // to frtch string 1

   cin.getline(name, 100);
   // to fr\etch address string2
   cout << "enter your full address -> "<<endl;
   // cin.ignore();
   // cin>>std::ws;
   cin.ignore();
   cin.getline(add, 100);

   // to get adhar no.
   
   cout << "Right down your 16 digit Adhar no->"<<endl;
   cin>>adhar_no;
    
    cout<<" Enter your mobile number-> "<<endl;
    cin>>mob_no;

   cout << "what type of account you want to open press-> s for saving  or press-> c for current\n";
   cin >> y;
   while ((y != 's' && y != 'c'))
   {
      cout << "press right key \n";
      cin >> y;
   }

   cout << "enter amount for deposite :\n";
   cin >> balance;

   while (balance < 0)
   {
      cout << "enter a valid amount" << endl;

      cin >> balance;
   }

   std::cout << "your account has been created \n";
}
void bank ::deposite_money()
{
   int a;
   if (flag == false)
   {
      cout << "you  have'nt still create any account \n ";
   }
   cout << "enter money to deposite : ";
   cin >> a;

   balance += a;

   cout << "total balance is :" << balance << "$";
}
void bank ::display_account()
{
   if (flag)
   {
      cout << " your full name is : " << name;
      //
      cout << "\n your full address is :";

      cout<<"\n your adhar number is :" << adhar_no;
      cout<<"\n your mobile number is :"<<mob_no;

      cout << "\n type of account that you opened :";
      if (y == 's')
      {
         cout << "Saving \n";
      }
      else if (y == 'c')
      {
         cout << "Current \n";
      }

      cout << " total balance : " << balance << "$\n";
   }
   else
   {
      cout << "you  have'nt still create any account \n";
   }
}
void bank ::withdraw_money()
{
   int x;
   char ch;
   if (flag == false)
   {

      cout << "you  have'nt still create any account \n for creating account press y and for exit press n : ";
      cin >> ch;
      if (ch == 'y' || ch == 'Y')
      {
         open_account();
      }
      else if (ch == 'n' || ch == 'N')
      {
         exit(0);
      }
   }
   cout << "enter money to withdraw : ";
   cin >> x;
   if (x > balance)
   {
      cout << " insufficient balance \n";
      withdraw_money();
   }

   else
   {
      balance -= x;
      cout << "withdraw sucessfull your total money after deduction : " << balance << "$\n";
   }
}

int main()
{
   int ch;
   char x;
   bank obj;
   do
   {
      cout << "\n 1) open account \n";
      cout << "2) deposite money \n";
      cout << "3) withdraw money \n";
      cout << "4) display account details \n";
      cout << "5) exist \n";
      cout << "select option \t";
      cin >> ch;
      switch (ch)
      {
      case 1:
         std::cout << "1) open account \n";
         obj.open_account();
         break;
      case 2:
         std::cout << "2) deposite money \n";
         obj.deposite_money();
         break;
      case 3:
         std::cout << "3) withdraw money \n";
         obj.withdraw_money();
         break;
      case 4:
         std::cout << "4) display money \n";
         obj.display_account();
         break;
      case 5:
         if (ch == 5)
         {
            exit(1);
         }
      default:
         std::cout << "try again \n";
      }
      std::cout << "\n do you want to select next option if yes then press : y \n";
      std::cout << "if you want to exit then press : n ";

      x = getch();

      if (x == 'n' || x == 'N')
      {
         exit(0);
      }

   } while (x <= 'z' && x >= 'a');

   getch();
   return 0;
}
