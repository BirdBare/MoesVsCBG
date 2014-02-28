//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: customer.cpp
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

using namespace std;

#include "customer.h"
#include "business.h"
#include <iostream>
#include <fstream>

ostream& operator<<(ostream& os, const customer& source)
{
  os << source.name << " has $" << source.cash << " with Happiness "
     << source.happiness;
  if(source.numPurchases > 0) {
    os << " and has " << source.purchases[0].name;
    
    for(int i=1; i<source.numPurchases; i++) {
      os << ", " << source.purchases[i].name ;
    };
  }
  os << ".";
  return os;
}

customer::customer()
{
  numPurchases=0;
  happiness=RanInt(MAXHAPPY);
  cash=MINCASH+RanInt(MAXCASH-MINCASH);
}

bool customer::buy_something(product& ToBuy, const product Items[],
                                             const int NumItems)
{
  bool success=false;
  int BuySomething;
  //variables
  
  BuySomething=RanInt(1);
  //zero=yes 1=no //desicion maker
  
  if(BuySomething == 0) {
  
    ToBuy=Items[RanInt(NumItems-1)];
    //picks random item to buy
      
    if(ToBuy.price <= cash && numPurchases < MAXPURCHASES) {
      cash-=ToBuy.price;
      purchases[numPurchases]=ToBuy;
      numPurchases++;
      success=true;
      happiness+=YESPURCHHAPPINESS;
      
      //cout << endl << name << " purchases a " << ToBuy.name << " for $"
        //   << ToBuy.price << ".";
    }
    //if statement which checks pocket space and amount of cash then does the
    //customer part of the exchange
    
  }
  else
    happiness+=NOPURCHHAPPINESS;
  return success;
}

void customer::throw_stuff(customer& victim)
{
  product item;
  int itemNum;
  //variables
  
  if(numPurchases > 0) {
    item=purchases[itemNum=RanInt(numPurchases-1)];
    purchases[itemNum]=purchases[numPurchases-1];
    //Because I have an array the real last item is num-1 as arrays start at 0
    //picks item out of pocket and switches with last item(gets ready to throw)
    
    cout << endl << name << " throws a " << item.name << " at " 
         << victim.name << ".";
    numPurchases--;
    //output as success and decrement numpurchases to get rid of item(throw).
  
    happiness+=THRHITHAPPINESS;
    victim.happiness+=VICHITHAPPINESS;
  
  }
  else {
    cout << endl << name << " was unable to throw something at " 
         << victim.name << ". He has nothing to throw.";
    happiness+=NOTHRHAPPINESS;
  }
  return;
}

void customer::rob_someone(customer& victim)
{
  product item;
  int itemNum;
  
  if(victim.numPurchases > 0 && numPurchases < MAXPURCHASES) {
    item=victim.purchases[itemNum=RanInt(victim.numPurchases-1)];
    //Picks item out of victims pocket
    
    cout << endl << name << " steals a " << item.name << " from " 
         << victim.name << ".";
    victim.purchases[itemNum]=victim.purchases[victim.numPurchases-1];
    victim.numPurchases--;
    victim.happiness+=VICSTEALHAPPINESS;
    //officially steals item

    purchases[numPurchases]=item;
    numPurchases++;
    happiness+=ROBYESHAPPINESS;
    //puts into pocket
  }
  else {
    cout << endl << name << " was unable to steal something from " 
         << victim.name << ". ";
    
    if(!(victim.numPurchases > 0))
      cout << victim.name << " does not have any items.";
    if(!(numPurchases < MAXPURCHASES))
      cout << name << " does not have pocket space.";
    //switches statement depending on situation
    
    happiness+=ROBNOHAPPINESS;
  }
  return;
}

bool customer::FillCustData(const string file)
{
  static ifstream fin(file.c_str());
  //streams
  
  static int count=0;
  //count line number in stream
  
  if(!fin)
    cout << endl << "ERROR: Could not open file " << file << ".";
  else {
    getline(fin,name,',');
    fin >> inclination;
    fin.ignore(8000,'\n');
    count++;
    if(count==MAXCUSTOMERS)
      fin.close();
    //close stream after last name is picked up
  }
  return true;
}