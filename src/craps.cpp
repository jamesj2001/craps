#include <iostream>
#include <cstdlib>
#include <dice.h>
#include <table.h>

using namespace std;

void printOptions()
{
  cout << "\nChoose an option..." << endl << "\ta. Roll" << endl << 
                                           "\tb. Place Bet" << endl <<
                                           "\tc. Print Table" << endl <<
                                           "\td. Print Last Dice Roll" << endl <<
                                           "\n\tq. Quit" << endl;
  cout << "\nOption:";
}

void printAvailableBets()
{
  cout << "\nSelect a type of bet..." << endl << "\t1. Pass" << endl <<
                                               "\t2. Don't Pass" << endl; 
}

int main(int argc, char* argv[])
{
  srand(time(0));  
  char option = ' ';
  Dice* dice = new Dice();
  int roll;
  bool pointOn = 0;
  int point;
  float bank;
  float amt;
  int betOption;
  Table* table = new Table();
  enum BET {passLine = 0, 
            dontPassBar = 1};

  cout << "Enter starting amount for bank: ";
  cin >> bank;
 
  while(option != 'q' && option != 'Q')
  {
    cout << "\nBank is $" << bank;
    printOptions();

    cin >> option;

    switch(option)
    {
      case 'a':
      case 'A':
        dice -> roll();
        roll = dice -> getDice();

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
              pointOn = false;
              point = 0;

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
               {table -> clear(0);}

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
        printAvailableBets();
        cout << "Bet Type:";
        cin >> betOption;

        switch(betOption)
        {
          case 1: //Pass bet
            cout << "Amount: ";
            cin >> amt;
            bank -= amt;
            table -> betPassLine(amt);
            break;

          case 2:  //Don't pass bet
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
          {cout << "\nPoint is " << point << endl;}
        else
          {cout << "\nPoint is off" << endl;}
        table -> printTable();
        break;
    }
  }

  return 0;

}
