#include <iostream>

using namespace std;

class Table
{
  float passLine;
  float dontPassBar;

public:
  float getPassLine();
  void betPassLine(float);
  float getDontPassBar();
  void betDontPassBar(float);
  void printTable();
  void clear(int);
};