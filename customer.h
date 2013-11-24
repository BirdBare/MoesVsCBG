//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: customer.h
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

//-----------------CLASS MEMBER FUNCTION DESCRIPTIONS IN ORDER------------------

//Description: customer default constructor

//Description: This function simulates a customer choosing 50/50 if they want
// to buy said random item they chose. then returns if they successfully 
// purchased something
// pre: must have atleast one item in itemsToSell array

//Description: This Function Simulates a customer throwing something at another
// customer
//pre: none
//Post: returns something if possible and if not

//Description: This function simulates a customer taking something from another
// customer
//pre: none
//Post: returns something if possible and if not

//Description: returns inclination i>0=moes i<0=cbg of calling customer
//pre: must run FillCustData to set inclination first
//Post: return inclination

//Description: This function returns happiness of calling customer
//pre: none
//Post: returns happiness

//Description: This Function returns name of calling customer
//pre: must run FillCustData to set name first
//post: returns name

//Description: This function takes a file of customer names and inclinations and
// puts them into a seperate customer each call.
//pre: file must be like "customer_name, inclination(moes<0<cbg), 
// number of names in file must be same number of MAXCUSTOMERS
//Post: takes each name and inclination in list and assigns to customer object

#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;

#include <string>
#include "struct.h"
#include "function.hpp"
#include <iostream>

const short MAXHAPPY=100, MINHAPPY=0, MAXPURCHASES=20, MAXCASH=250, MINCASH=4;
const int POCKETSIZE=10, YESPURCHHAPPINESS=15, NOPURCHHAPPINESS=-10;
const int VICHITHAPPINESS=-20, THRHITHAPPINESS=5, NOTHRHAPPINESS=-25;
const int ROBYESHAPPINESS=25, VICSTEALHAPPINESS=-20, ROBNOHAPPINESS=-5;
const int MAXCUSTOMERS=20;
//CONSTANTS

class business;

class customer
{
 private:
  product purchases[MAXPURCHASES];
  short numPurchases;
  float cash;
  int inclination;
  short happiness;
  string name;
  
 public:
  customer();
  bool buy_something(product& ToBuy, const product Items[], const int NumItems);
  void throw_stuff(customer& victim);
  void rob_someone(customer& victim);
  int get_inclination(){return inclination;};
  short get_happiness(){return happiness;};
  string get_name(){return name;};
  bool FillCustData(const string file);
  friend ostream& operator<<(ostream& os, const customer& source);
  friend ostream& operator<<(ostream& os, const business& source);
 };
#endif