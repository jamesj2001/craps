#include <iostream>
#include <cstdlib>

using namespace std;

void printOptions()
{
  cout << "Choose an option..." << endl << "a. Roll" << endl << 
                                           "b. Place Bet" << endl <<
                                           "q. Quit" << endl;
}

array<int,2> roll(array<int,2>& dice)
{
  dice[0] = rand() % 6 + 1;
  dice[1] = rand() % 6 + 1;
  return dice;
}

int main(int argc, char* argv[])
{
  srand(time(0));  
  char option = '';
  array<int,2> dice;

  while(option != q && option != Q)
  {
    printOptions();

    cin >> option;

    switch(option)
    {
      case 'a':
        array<int,2> dice = roll();
    }
  }

  return 0;

}
