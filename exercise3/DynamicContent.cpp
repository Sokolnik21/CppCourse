#include "DynamicContent.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Person::Person(string name, int birth) {
  this -> name = name;
  this -> birth = birth;
}

void inline Person::describePerson() {
  cout << name << ", " << birth << endl;
}

/* Constructors */
/* Basic constructor */
Group::Group(int storage) {
  if(storage <= 0)
    throw std::invalid_argument("Storage must be higher than 0");
  this -> storage = storage;
  array = new Person[storage];
  actualSize = 0;
}
/* Copy constructor */
Group::Group(const Group &group) {
  this -> storage = group.storage;
  array = new Person[group.storage];
  for(int i = 0; i < group.actualSize; i++)
    array[i] = group.array[i];
  this -> actualSize = group.actualSize;
}
/* Move constructor */
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
  /* Delete array */
  delete[] array;
}

// Operator przenoszący:
// https://msdn.microsoft.com/pl-pl/library/dd293665.aspx
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
/* Move assignment operator */
Group& Group::operator=(Group &&group) {
  if(this != &group) {
    /* Clear current memory allocation */
    delete[] array;
    /* Copy values */
    storage = group.storage;
    array = group.array;
    actualSize = group.actualSize;
    /* Free memory allocation from source object */
    group.storage = 20;
    group.array = nullptr;
    group.actualSize = 0;
  }
  return *this;
}

/* Getter */
int Group::getElementsQuantity() {
  return this -> actualSize;
}

int Group::getStorage() {
  return this -> storage;
}

void Group::addPerson(Person p) {
  if(actualSize < storage) {
    array[actualSize] = p;
    actualSize++;
  }
  else {
    throw std::invalid_argument("Not enough space");
  }
}

/**
 * Tests
 */
int main() {
  /* Constructors */
  cout << "__Basic constructors__" << endl;
  cout << "__Person__" << endl;
  Person pConstr;
  pConstr.describePerson();
  Person pConstr1("Ola");
  pConstr1.describePerson();
  Person pConstr2("Ula", 19);
  pConstr2.describePerson();
  cout << "__Group__" << endl;
  Group gConstr;
  cout << gConstr.getStorage() << endl;
  Group gConstr1(15);
  cout << gConstr1.getStorage() << endl;

  /* Supporting objects */
  Person p1("Anna", 21);
  Person p2("Maria", 31);
  Person p3("Pawel", 25);

  /* Adding Person to Group */
  cout << endl << "__Adding Person to Group and testing getElementsQuantity()__" << endl;
  Group gBase(3);
  cout << "Before " << gBase.getElementsQuantity() << endl;
  gBase.addPerson(p1);
  gBase.addPerson(p2);
  gBase.addPerson(p3);
  cout << "After " << gBase.getElementsQuantity() << endl;

  /* Copy constructor and move constructor - based on gBase */
  cout << endl << "__Copy and move constructor__" << endl;
  /* Copy constructor */
  cout << "__Copy constructor__" << endl;
  Group gCopy(gBase);
  cout << "Base " << gBase.getElementsQuantity() << endl;
  cout << "Copy " << gCopy.getElementsQuantity() << endl;
  cout << "__Move constructor__" << endl;
  /* Move constructor */
  Group gMove(move(gBase));
  cout << "Base " << gBase.getElementsQuantity() << endl;
  cout << "Move " << gMove.getElementsQuantity() << endl;

  /* Assignment and move assignment operators */
  cout << endl << "__Assignment and move assignment operators__" << endl;
  /* Assignment operator */
  cout << "__Assignment operator__" << endl;
  Group gBaseOp(3);
  gBaseOp.addPerson(p1);
  gBaseOp.addPerson(p2);
  gBaseOp.addPerson(p3);
  Group gAssign = gBaseOp;
  cout << "Base " << gBaseOp.getElementsQuantity() << endl;
  cout << "Assign " << gAssign.getElementsQuantity() << endl;
  /* Move assignment operator */
  cout << "__Move assignment operator__" << endl;
  Group gMoveAssign = move(gBaseOp);
  cout << "Base " << gBaseOp.getElementsQuantity() << endl;
  cout << "MoveAssign " << gMoveAssign.getElementsQuantity() << endl;



  /* Exceptions */
  try {
    Group tryG(0);
  }
  catch(const std::invalid_argument& e) {
    cout << endl << "Cought exception!" << endl;
  }

  return 0;
}
