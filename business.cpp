//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: business.cpp
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

using namespace std;

//#include "customer.h"
#include "business.h"
#include <iostream>
#include <fstream>

ostream& operator<<(ostream& os, const business& source)
{
  os << "--------" << source.name << "--------" << endl;

  os << "--------Items For Sale--------";
  for(int i=0; i<source.numItems; i++) {
    if(i%2==0)
     os << endl;
    os << i+1 << ". " << source.itemsToSell[i].name << "    ";
  };
  os << endl << endl << "Total Money Made: $" 
     << source.registerMoney-STARTINGCASH;
  return os;
}

business::business(const string bizName, const float cash, 
                   const string file, const int Items)
{
  ifstream fin(file.c_str());
  //stream

  name = bizName;
  registerMoney = cash;
  numCustomers=0;
  //set things
  
  if(!fin)
    cout << endl << "ERROR: Could not open file " << file << ".";
  
  else
    for(numItems=0; numItems < Items; numItems++){
      getline(fin,itemsToSell[numItems].name,',');
      fin >> itemsToSell[numItems].price;
      fin.ignore(8000,'\n');
    };
  fin.close();
}

void business::addCustomer(const customer source)
{
  if(numCustomers < MAXOCCUPANCY) {
    customers[numCustomers]=source;
    numCustomers++;
  }
  else
    cout << "WARNING: Maximum occupancy reached, customer denied entry." << endl;
  return;
}

void business::customers_leave(customer street[], int& streetSize)
{
  for(int i=0; i<numCustomers; i++) {
    street[streetSize]=customers[i];
    streetSize++;
  };
  numCustomers=0;
  return;
}

void business::sell_stuff()
{
  bool purchased=false;
  product checkoutItem;

  for(int i=0; i<numCustomers; i++) {
    purchased=customers[i].buy_something(checkoutItem, itemsToSell, numItems);
    if(purchased==true) {
      registerMoney+=checkoutItem.price;
    }
    //simulates a potential transaction
  };
  return;
}