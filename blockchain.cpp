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

    void print_Transaction(Transaction block)
    {

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

    }

    void Blockchain::verify_print() const
    {

    }
}
