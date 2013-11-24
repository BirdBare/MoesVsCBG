//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: Driver.cpp
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
#include "function.hpp"
#include <iostream>

//Description: Overloading insertion operator for business class.
//pre: none......USE: cout << business object
//Post: cout business object in overloaded format
ostream& operator<<(ostream& os, const business& source);

//Description: Overloading insertion operator for customer class.
//pre: none......USE: cout << customer object
//Post: cout customer object in overloaded format
ostream& operator<<(ostream& os, const customer& source);

const int MAXREPEATS=20;

int main()
{
  int repeat=0, StreetIdentitySize=0;
  string trash;
  //variables

  business Moes("Moe's Bar",STARTINGCASH,"MoeSell.dat",7);
  business CBG("Comic Book Guy's Store",STARTINGCASH,"CBGSell.dat",7);
  customer Street[MAXCUSTOMERS];
  //Define Objects
  
  for(int i=0; i<MAXCUSTOMERS; i++) {
    if(Street[i].FillCustData("Customers.dat")==true)
      StreetIdentitySize++;
  };
  //gets customer names and inclinations
  
  while(repeat < MAXREPEATS && StreetIdentitySize > 1) {
    
    if(repeat != 0) {
      cout << endl << "Press any key followed by enter to start next round: ";
      cin >> trash;
    }
  
    cout << endl << endl <<"----------Customer Information----------";
    for(int i=0; i<StreetIdentitySize; i++) {
      cout << endl << Street[i];
    };
    
    NewLiner(2);

    for(StreetIdentitySize-=1; 0<=StreetIdentitySize; StreetIdentitySize--) {
      if((Street[StreetIdentitySize].get_happiness()>=90 ||
          Street[StreetIdentitySize].get_happiness()<10) && repeat!=0) {
      
        cout << endl <<Street[StreetIdentitySize].get_name() << " is " ;
        if(Street[StreetIdentitySize].get_happiness()>=90)
          cout << "experiencing Nirvana";
        else
          cout << "desperately unhappy";
        cout << " and has gone to the House of Desperation ";
        if(Street[StreetIdentitySize].get_happiness()>=90)
          cout << "to lord over the depairati";
        else
          cout << "to undergo giggle therapy";
        cout << ".";
      }
      //output block to output message specific to happiness level
      else {
        if(Street[StreetIdentitySize].get_inclination()>0)
          Moes.addCustomer(Street[StreetIdentitySize]);
        if(Street[StreetIdentitySize].get_inclination()<0)
          CBG.addCustomer(Street[StreetIdentitySize]);
      }
      if(StreetIdentitySize==0 && repeat!=0)
        NewLiner(2);
    };
    //Walks down cust array Street[] and assigns to store by inclination but 
    //if happiness is not in correct range they are remove from array
    //MOES=+nums CBG=-nums
  
    StreetIdentitySize=0;
    //Street Empty
    
    cout << endl << "----------Customer Purchases----------";
    Moes.sell_stuff();
    CBG.sell_stuff();
    Businesses try to push product
    
    NewLiner(2);
  
    Moes.customers_leave(Street,StreetIdentitySize);
    CBG.customers_leave(Street,StreetIdentitySize);
    //Customers come back out into the street
  
    cout << endl << "----------Customer Interactions----------";
    for(int i=0; i<2; i++) {
      if(i==0)
        ShuffleArray(Street,StreetIdentitySize); 
      if(i==1) {
        for(int j=0; j<StreetIdentitySize; j++) {
          i = RanInt(StreetIdentitySize-1);
          if(Street[j].get_inclination()==Street[i].get_inclination())
            Street[j].rob_someone(Street[i]);
          else
            Street[j].throw_stuff(Street[i]);
          //Picks random number as i to be number of victim
          //decides what to do base on inclination
        };
        i=1;
        //sets i to prev value for loop
      }
    };
    //Shuffles cust array first then does interaction between customers
    
    NewLiner(2);
    repeat++;
  }
  //While loop to run for MAXREPEATS number of times or 
  //until num customers is 1 or less
  
  cout << "The Winning Business is: *****DRUMMMMMMROOLLLLLLLL***** " << endl ;
  
  Moes.get_money()>CBG.get_money() ?
  cout << Moes :
  cout << CBG;
  cout << endl << "Because of this the retail industry has been turned on ear."
       << " NOTHING will ever be the same.";
  NewLiner(2);
  
  

return 0;
}