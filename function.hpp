//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: function.hpp
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

//Description: This fuction is designed to take any number type and get a random
// integer up to that number.
//pre; none
//post: return a random int between 0 and number passed
template <typename T>
T RanInt(const T max)
{
  static T RanNum=0;
  static int count=0;
  
  count++;
  srand(time(NULL)+(RanNum+=count));

  RanNum = (rand() % (max+1) );
  
  return RanNum;
}

//Description: This function takes an type of array and just randomly shuffles it
//pre: RanInt generator must be included, otherwise none
//Post: shuffled array is returned by reference
template <typename T>
void ShuffleArray(T array[], const int arraySize)
{
  T temp;
  int num;
  
  for(int i=0; i<arraySize; i++) {
    num = RanInt(arraySize-1);
    temp = array[i];
    array[i] = array[num];
    array[num] = temp;  
  };
  return;
}

//Decsription: This function takes any number and newline the output that many
// times
//pre: none
//Post: new lines
template <typename T>
void NewLiner(const T lines)
{
  for(int i=0; i<lines; i++) {
    cout << endl;
  };
  return;
}
#endif