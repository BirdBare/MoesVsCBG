//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: business.h
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

//-----------------CLASS MEMBER FUNCTION DESCRIPTIONS IN ORDER------------------

//Description: business default constructor

//Description: business constructor takes a filename biz name and other things
// to put the business class together
//pre: file must be like "item, price\n"
//Post: business class is made with all information

//Description: Adds a single customer to the business customer array
//pre: none
//Post: customer in business customer array

//Definition: This function makes all the customers leave the business 
//pre: must have added atleast one customer 
//Post: all customers are emptied from array into another array

//Defintion: this function calls a function in the customer class to transfer
// goods and take the money. it then accepts the money if it was successful
//pre: itemsToSell array must have atleast one item
//Post: if transaction is successful the money is transfered. if not nothing
// happens

//Definition: This function returns the money in the register
//pre: none
//post: returns money as type

#ifndef BUSINESS_H
#define BUSINESS_H

using namespace std;
#include "customer.h"

const int MAXITEMS=10, MAXOCCUPANCY=10, STARTINGCASH=10;

class business
{
 private:
  string name;
  float registerMoney;
  product itemsToSell[MAXITEMS];
  short numItems;
  customer customers[MAXOCCUPANCY];
  short numCustomers;
 
 public:
  business():name(""), registerMoney(0), numItems(0), numCustomers(0){};
  business(const string Sname, const float cash, 
           const string file, const int Items);
  void addCustomer(const customer source);
  void customers_leave(customer street[], int& streetSize);
  void sell_stuff();
  float get_money(){return registerMoney;};
  short get_numCustomers(){return numCustomers;};
  friend ostream& operator<<(ostream& os, const business& source);
};
#endif