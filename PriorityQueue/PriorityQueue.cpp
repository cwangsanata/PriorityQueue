/*
* Author: Christopher Wangsanata
* Implementation of a priority queue using a call-center example.
*/

#include <iostream>
#include <string>
using namespace std; 

class Caller
{
private:
  string ID;
  int priority;

public:
  // Fix default constructor
  Caller()
  {
    ID = to_string(1 + (rand() % 99999));
    priority = 1 + (rand() % 10);
  }

  Caller(string ID_, int priority_)
  {
    ID = ID_;
    priority = priority_;
  }

  // make protected underneath here
  void printCaller()
  {
    cout << "ID: " << ID << endl;
    cout << "Priority Level: " << priority << endl << endl;
  }

  int getPriority()
  {
    return priority;
  }
};

class CallerDatabase
{
private:
  const int MAX_CALLERS = 10;
  Caller* callers;

public:
  CallerDatabase()
  {
    callers = new Caller[MAX_CALLERS];
  }

  void enqueue(Caller);
  Caller dequeue(Caller);
  Caller peek();
  bool isEmpty();
  bool getLength();

  void printAllCallers()
  {
    for (int i = 0; i < sizeof(callers); i++)
      callers[i].printCaller();
  }
};

int main()
{
  // Testing funcitonality
  Caller myGuy;
  myGuy.printCaller();
}

void CallerDatabase::enqueue(Caller temp)
{
  if (sizeof(callers) == MAX_CALLERS)
  {
    cout << "Sorry. All agents are currently helping other customers. Please try again later.";
    return;
  }

  else if (sizeof(callers) == 0)
    callers[0] = temp;

  else
  {
    for (int i = 0; i < MAX_CALLERS; i++)
    {
      if (temp.getPriority() < callers[i].getPriority())
        callers[i + 1] = callers[i];
      else
        break;

      callers[i + 1] = temp;
    } 
  }
}

Caller CallerDatabase::dequeue(Caller temp)
{
  return CallerDatabase
}
