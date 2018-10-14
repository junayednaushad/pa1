#include "blockchain.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

namespace junayed_naushad
{
    void print_Transaction(Transaction block)
    {

    }

    void Blockchain::add(int an_amount, string a_sender, string a_receiver)
    {
        //adding first transaction
        if(head->get_prev() == NULL)
        {
          head->set_amount(an_amount);
          head->set_sender(a_sender);
          head->set_receiver(a_receiver);
        }
    }

    void Blockchain::find(string a_sender) const
    {

    }

    void Blockchain::verify_print() const
    {

    }
}
