#include <iostream>
#include <cstdlib>
#include <dice.h>
#include <table.h>

using namespace std;

void printOptions()
{
  cout << "Choose an option..." << endl << "a. Roll" << endl << 
                                           "b. Place Bet" << endl <<
                                           "c. Print Table" << endl <<
                                           "d. Print Last Dice Roll" << endl <<
                                           "q. Quit" << endl;
  cout << "Option:";
}

void printAvailableBets()
{
  cout << "Select a type of bet..." << endl << "1. Pass" << endl <<
                                               "2. Don't Pass" << endl; 
}

int main(int argc, char* argv[])
{
  srand(time(0));  
  char option = ' ';
  Dice* dice = new Dice();
  bool pointOn = 0;
  int point;
  float bank;
  Table* table = new Table();
  enum BET {passLine = 0, 
            dontPassBar = 1};

  cout << "Enter starting amount for bank: ";
  cin >> bank;
 
  while(option != 'q' && option != 'Q')
  {
    cout << "Bank is $" << bank;
    printOptions();

    cin >> option;

    switch(option)
    {
      case 'a':
      case 'A':
        dice -> roll();
        int roll = dice -> getDice();

        if (pointOn)
        {
           if (roll == point) 
           {
              pointOn = false;
              point = 0;

              if (table -> getPassLine() > 0)
              {
                 bank += table -> getPassLine() * 2;
                 table -> clear(0);
              }

              if (table -> getDontPassBar() > 0)
                {table -> clear(1);}
           }

           if (roll == 7)
           {
              if (table -> getPassLine() > 0)
                {table -> clear(0);}

              if (table -> getDontPassBar() > 0)
              {
                bank += table -> getDontPassBar() * 2;
                table -> clear(1);
              }
           }
        }
        else
        {
          if ((roll == 7) || (roll == 11))
          {
            if (table -> getPassLine() > 0)
            {
              bank += table -> getPassLine() * 2; 
              table -> clear(0);
            }

            if (table -> getDontPassBar() > 0)
              {table -> clear(1);}
          }
          else if ((roll == 2) || (roll == 3))
          {
             if (table -> getPassLine() > 0)
               {table -> clear(0);}
            
             if (table -> getDontPassBar() > 0)
             {
                bank += table -> getPassLine() * 2;
                table -> clear(1);
             }
          }
          else if (roll == 12)
          {
             if (table -> getPassLine() > 0)
               {table -> clear(0)}

             if (table -> getDontPassBar() > 0)
             {
                bank += table -> getDontPassBar();
                table -> clear(1);
             }
          }
          else
          {
             pointOn = true;
             point = roll;
          }
        }
        
        break;

      case 'b':
      case 'B':
        int betOption = 0;
        printAvailableBets();
        cout << "Bet Type:";
        cin >> betOption;

        switch(betOption)
        {
          case 1: //Pass bet
            float amt;
            cout << "Amount: ";
            cin >> amt;
            bank -= amt;
            table -> betPassLine(amt);
            break;

          case 2:  //Don't pass bet
            float amt;
            cout << "Amount: ";
            cin >> amt;
            bank -= amt;
            table -> betDontPassBar(amt);
            break;
        }
        break;

      case 'c':
      case 'C':
        if (pointOn)
          {cout << "Point is " << point << endl;}
        else
          {cout << "Point is off" << endl;}
        table -> printTable();
        break;
    }
  }

  return 0;

}
