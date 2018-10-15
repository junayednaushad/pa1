#include "blockchain.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "picosha2.h"
using namespace std;

namespace junayed_naushad
{
    void Blockchain::set_next_hash(string hash)
    {
        next_hash = hash;
    }

    string Blockchain::get_next_hash() const
    {
        return next_hash;
    }

    void print_Transaction(Transaction* t_ptr)
    {
        cout << "Amount: " + to_string(t_ptr->get_amount()) << endl;
        cout << "Sender: " + t_ptr->get_sender() << endl;
        cout << "Receiver: " + t_ptr->get_receiver() << endl;
        cout << "Nonce: " + t_ptr->get_nonce() << endl;
        cout << "Hash: " + t_ptr->get_hash() << endl;
    }

    void Blockchain::add(int an_amount, string a_sender, string a_receiver)
    {
        //adding first transaction
        if(chain_size == 0)
        {
          head->set_amount(an_amount);
          head->set_sender(a_sender);
          head->set_receiver(a_receiver);
          chain_size++;
        }
        //adding following transactions
        else
        {
            Transaction* t1 = new Transaction(an_amount, a_sender, a_receiver);
            t1->set_prev(head);
            t1->set_hash(next_hash);
            head = t1;
            chain_size++;
        }

        string amount = to_string(an_amount);
        string hash = "5";
        string nonce;
        while(hash.at(hash.length()-1) != '0' && hash.at(hash.length()-1) != '1' && hash.at(hash.length()-1) != '2' && hash.at(hash.length()-1) != '3' && hash.at(hash.length()-1) != '4')
        {
            srand(time(NULL));
            nonce = "";
            for(int i = 0; i < 5; i++)
            {
                nonce += char(rand() % 26 +97);
            }
            string str = amount + a_sender + a_receiver + nonce;
            hash = picosha2::hash256_hex_string(str);
        }
        head->set_nonce(nonce);
        next_hash = hash;

        cout << "Transaction has been added\n";
        cout << "The hash value calculated based on the previous transaction is: " << head->get_hash() << endl;
    }

    void Blockchain::find(string a_sender) const
    {
        cout << "Finding all transactions for " << a_sender << endl;
        int matches = 0;
        Transaction* t_ptr = head;
        while(t_ptr->get_prev() != NULL)
        {
            if(t_ptr->get_sender().compare(a_sender) == 0)
            {
              matches++;
              cout << "\nTransaction " << to_string(matches) << endl;
              print_Transaction(t_ptr);
            }
            t_ptr = t_ptr->get_prev();
        }
        if(t_ptr->get_prev() == NULL)
        {
          if(t_ptr->get_sender().compare(a_sender) == 0)
          {
            matches++;
            cout << "\nTransaction " << matches << endl;
            print_Transaction(t_ptr);
          }
        }
        if(matches == 0)
          cout << "No transactions with the given sender were found\n";
    }

    void Blockchain::verify_print() const
    {
        bool test = true;
        Transaction* t1 = head;
        Transaction* t2;
        //case where there is only one transaction
        if(t1->get_prev() == NULL)
        {
          cout << "The transaction-chain is valid\n";
          print_Transaction(t1);
        }
        else
        {
          string expected_hash;
          string actual_hash;
          string src;
          while(test == true && t1->get_prev() != NULL)
          {
            t2 = t1->get_prev();
            actual_hash = t1->get_hash();
            src = to_string(t2->get_amount()) + t2->get_sender() + t2->get_receiver() + t2->get_nonce();
            expected_hash = picosha2::hash256_hex_string(src);
            if(actual_hash.compare(expected_hash) == 0)
              t1 = t1->get_prev();
            else
              test == false;
          }
          if(test == false)
          {
            cout << "Invalid transactions have been found\n";
            print_Transaction(t1);
            print_Transaction(t2);
          }
          else
          {
            cout << "The transaction-chain is valid\n";
            cout << "Printing all transactions\n";
            t1 = head;
            while(t1->get_prev() != NULL)
            {
              print_Transaction(t1);
              t1 = t1->get_prev();
            }
            print_Transaction(t1);
          }
        }
    }
}
