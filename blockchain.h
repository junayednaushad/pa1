#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "picosha2.h"

namespace junayed_naushad
{
    class Transaction
    {
    public:
        //default constructor
        Transaction() : amount(0), sender(""), receiver(""), nonce(""), hash(""), prev(NULL){}
        //constructor
        Transaction(int an_amount, std::string a_sender, std::string a_receiver)
        {
          amount = an_amount;
          sender = a_sender;
          receiver = a_receiver;
          nonce = "";
          hash = "";
          prev = NULL;
        }

        //Setters
        void set_amount(int new_amount)
        {amount = new_amount;}
        void set_sender(std::string new_sender)
        {sender = new_sender;}
        void set_receiver(std::string new_receiver)
        {receiver = new_receiver;}
        void set_nonce(std::string new_nonce)
        {nonce = new_nonce;}
        void set_hash(std::string new_hash)
        {hash = new_hash;}
        void set_prev(Transaction* new_prev)
        {prev = new_prev;}

        //Getters
        int get_amount() const {return amount;}
        std::string get_sender() const {return sender;}
        std::string get_receiver() const {return receiver;}
        std::string get_nonce() const {return nonce;}
        std::string get_hash() const {return hash;}
        Transaction* get_prev() const {return prev;}

    private:
        int amount;
        std::string sender;
        std::string receiver;
        std::string nonce;
        std::string hash;
        Transaction* prev;
    };

    void print_Transaction(Transaction block);

    class Blockchain
    {
    public:
      //default constructor
      Blockchain()
      {
        head = new Transaction();
        next_hash = "";
        chain_size = 0;
      }

      void set_next_hash(std::string hash);
      std::string get_next_hash() const;


      void add(int an_amount, std::string a_sender, std::string a_receiver);
      void find(std::string a_sender) const;
      void verify_print() const;

    private:
       Transaction* head;
       std::string next_hash;
       int chain_size;
    };

}

#endif
