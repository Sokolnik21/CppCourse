#include "DynamicContent.h"
#include <iostream>
using namespace std;

Person::Person(string name, int birth) {
  this -> name = name;
  this -> birth = birth;
}

/* Constructors */
Group::Group(int storage) {
  this -> storage = storage;
  array = new Person[storage];
  actualSize = 0;
}

Group::Group(const Group &group) {
  this -> storage = group.storage;
  array = new Person[group.storage];
  for(int i = 0; i < group.actualSize; i++)
    array[i] = group.array[i];
  this -> actualSize = group.actualSize;
}

Group::Group(Group &&group) :
  /* Steal variables */
  storage(group.storage),
  actualSize(group.actualSize),
  array(group.array) {
  /* Reset previous one */
  group.storage = 20;
  group.actualSize = 0;
  group.array = new Person[20];
}

/* Destructor */
Group::~Group() {
  // /* Delete Persons */
  // for(int i = 0; i < actualSize; i++)
  //   delete array[i];
  /* Delete array */
  delete[] array;
}

/* Operators */
Group& Group::operator=(const Group &group) {
  if (this != &group) // protect against invalid self-assignment
  {
    // 1: allocate new memory and copy the elements
    int tmpStorage = group.storage;
    Person *tmpArray = new Person[group.storage];
    for(int i = 0; i < group.actualSize; i++)
      tmpArray[i] = group.array[i];
    int tmpActualSize = group.actualSize;

    // 2: deallocate old memory
    delete [] array;

    // 3: assign the new memory to the object
    storage = tmpStorage;
    array = tmpArray;
    actualSize = tmpActualSize;
  }
  return * this;
}

// Operator przenoszący:
// https://msdn.microsoft.com/pl-pl/library/dd293665.aspx

/* Getter */
int Group::getElementsQuantity() {
  return this -> actualSize;
}

int main() {
  Person p("Ala");
  cout << p.name << endl;
  cout << p.birth << endl;

  Group g(12);
  cout << g.storage << endl;
  cout << g.actualSize << endl;

  Group g2(move(g));
  cout << g.storage << endl;
  cout << g2.storage << endl;

  cout << g.getElementsQuantity() << endl;


  return 0;
}
