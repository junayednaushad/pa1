#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdlib>
#include <iostream>
#include <string>

namespace junayed_naushad
{
    class transaction
    {
    public:
        //constructor
        transaction(
            transaction* init_prev = NULL,
            int init_amount = 0,
            string init_sender = "",
            string init_receiver = "",
            string init_nonce = "",
            string init_hash = ""
            )
            {
                prev = init_prev;
                amount = init_amount;
                sender = init_sender;
                receiver = init_receiver;
                nonce = init_nonce;
                hash = init_hash;
            }

        //Setters
        void set_prev(transaction* new_prev)
        {prev = new_prev;}
        void set_amount(int new_amount)
        {amount = new_amount;}
        void set_sender(string new_sender)
        {sender = new_sender;}
        void set_receiver(string new_receiver)
        {receiver = new_receiver;}
        void set_nonce(string new_nonce)
        {nonce = new_nonce;}
        void set_hash(string new_hash)
        {hash = new_hash;}

        //Getters
        void get_amount

        void print_transaction(transaction block)
        {

        }

    private:
        transaction* prev;
        int amount;
        string sender;
        string receiver;
        string nonce;
        string hash;
    };


    class blockchain
    {

    };
}

#endif
