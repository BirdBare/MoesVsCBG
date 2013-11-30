//-----------------------------------------------------------------------------
// Programmer : Bradley Bare          Student ID: 12363780
// Homework: #10 , Simulate Madness   Filename: product.h
// Due Date: xx/xx/xx                 Class: CS53, Section B
//-----------------------------------------------------------------------------
// Program Description: This program simulates two competing businesses trying
// to sell to 10 people. it simulates a decision of sales and other things like
// that. Happiness level determines where they end up and the simulation runs
// every key click till one person is left or 20 clicks have passed. Ending 
// stats are shown of the winner business with a smart ass comment of the world.

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

struct product
{
  string name;
  float price;
};
#endif