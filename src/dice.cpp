#include <iostream>
#include <dice.h>

using namespace std;

Dice::Dice()
{}

void Dice::roll()
{
  die1 = rand() % 6 + 1;
  die2 = rand() % 6 + 1;

  printDice();
}

void Dice::printDice()
{
  cout << "Dice rolled are " << die1 << " and " << die2 << ".  Total is " << die1 + die2 << "." << endl;
}

int Dice::getDice()
{
  return die1 + die2;
}

int Dice::getDie1()
{
  return die1;
}

int Dice::getDie2()
{
  return die2;
}

