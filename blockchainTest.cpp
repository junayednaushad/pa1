#include "blockchain.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "picosha2.h"
using namespace std;
using namespace junayed_naushad;

int main()
{
    Blockchain b1 = Blockchain();
    int operation = 0;
    string response;
    string an_amount;
    int amount;
    string sender;
    string receiver;

    cout << "\nWelcome to the transaction-chain application\n";
    while(operation != 4)
    {
      operation = 0;
      cout << "\nPlease enter the number corresponding to the operation you would like to use:\n";
      cout << "1) Add a transaction to the chain\n";
      cout << "2) Find and print all transactions from a sender\n";
      cout << "3) Verify and print the chain\n";
      cout << "4) Quit\n";
      getline(cin, response);
      for(int i = 0; i < response.length(); i++)
      {
        if(isdigit(response.at(i)) == 0)
        {
            operation = 5;
            i = response.length();
        }
      }
      if(operation != 5)
        operation = stoi(response);

      //check for invalid input
      if(operation != 1 && operation != 2 && operation != 3 && operation != 4)
      {
        cout << "Wrong operation, please enter a valid number\n";
      }

      //add transaction
      else if(operation == 1)
      {
        cout << "Please enter the amount you would like to add:\n";
        int check = 0;
        while(check != 1)
        {
          check = 0;
          getline(cin, an_amount);
          for(int i = 0; i < an_amount.length(); i++)
          {
            if(isdigit(an_amount.at(i)) == 0)
            {
                i = an_amount.length();
                check = 2;
                cout << "Please enter an integer amount:\n";
            }
          }
          if(check == 0)
            check = 1;
        }
        amount = stoi(an_amount);
        cout << "Please enter the name of the sender:\n";
        getline(cin, sender);
        cout << "Plese enter the name of the receiver:\n";
        getline(cin, receiver);
        b1.add(amount, sender, receiver);
      }

      //find transaction
      else if(operation == 2)
      {
        cout << "Please enter the name of the sender:\n";
        getline(cin, sender);
        b1.find(sender);
      }

      //verify and print
      else if(operation == 3)
      {
        cout << "Verifying chain\n";
        b1.verify_print();
      }

      //quit
      else
      {
        operation = 4;
      }
    }
    cout << "Thank you for using this application\n";
    return 0;
}
