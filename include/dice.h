#ifndef DICE_H
#define DICE_H

class Dice
{
    int die1;
    int die2;

  public:
    Dice();
    void roll();
    void printDice();
    int getDice();
    int getDie1();
    int getDie2();
};

#endif