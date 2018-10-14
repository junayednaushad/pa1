#include "blockchain.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
using namespace junayed_naushad;

int main()
{
    int operation = 0;
    string response;
    string an_amount;
    int amount;
    string sender;
    string receiver;

    cout << "Welcome to the transaction-chain application\n";
    while(operation != 4)
    {
      cout << "Please enter the number corresponding to the function you would like to use:\n";
      cout << "1) Add a transaction to the chain\n";
      cout << "2) Find and print all transactions from a sender\n";
      cout << "3) Verify and print the chain\n";
      cout << "4) Quit\n";
      getline(cin, response);
      operation = stoi(response);

      //check for invalid input
      if(operation != 1 && operation != 2 && operation != 3 && operation != 4)
      {
        cout << "Please enter a valid number\n";
      }

      //add transaction
      else if(operation == 1)
      {
        cout << "Please enter the amount you would like to add:\n";
        getline(cin, an_amount);
        while(an_amount.find(".",0) != -1)
        {
          cout << "Please enter an integer amount:\n";
          getline(cin, an_amount);
        }
        amount = stoi(an_amount);
        cout << "Please enter the name of the sender:\n";
        getline(cin, sender);
        cout << "Plese enter the name of the receiver:\n";
        getline(cin, receiver);
        
      }

      //find transaction
      else if(operation == 2)
      {
        cout << "Finding transactions\n";
      }

      //verify and print
      else if(operation == 3)
      {
        cout << "Verifying chain\n";
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
