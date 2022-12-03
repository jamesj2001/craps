#include <iostream>
#include <table.h>

using namespace std;

Table::Table() 
{
  passLine = 0;
  dontPassBar = 0;
}

float Table::getPassLine()
{
  return passLine;
}

void Table::betPassLine(float amt)
{
  passLine += amt;
}

float Table::getDontPassBar()
{
  return dontPassBar;
}

void Table::betDontPassBar(float amt)
{
  dontPassBar += amt;
}

void Table::printTable()
{
  float total = 0;
  cout << "Pass Line:\t$" << passLine << endl;
  total += passLine;
  cout << "Don't Pass Bar:\t$" << dontPassBar << endl << endl;
  cout << "Total bets in play:\t$" << total << endl;
}

void Table::clear(int a)
{
  switch (a)
  {
    case 0: 
      passLine = 0;
      break;

    case 1:
      dontPassBar = 0;
      break;
  }
}