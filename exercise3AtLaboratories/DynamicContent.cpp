#include "DynamicContent.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Data::Data(int day, int month) {
  /* Simple day exceptions */
  if(day < 1 || day > 31)
    throw std::invalid_argument("Invalid day");
  if(month < 1 || month > 12)
    throw std::invalid_argument("Invalid month");
  this -> day = day;
  this -> month = month;
}

void inline Data::describeData() {
  cout << day << ", " << month << endl;
}

/* Constructors */
/* Basic constructor */
Agenda::Agenda(int storage) {
  if(storage <= 0)
    throw std::invalid_argument("Storage must be higher than 0");
  this -> storage = storage;
  array = new Data[storage];
  actualSize = 0;
}
/* Copy constructor */
Agenda::Agenda(const Agenda &agenda) {
  this -> storage = agenda.storage;
  array = new Data[agenda.storage];
  for(int i = 0; i < agenda.actualSize; i++)
    array[i] = agenda.array[i];
  this -> actualSize = agenda.actualSize;
}
/* Move constructor */
Agenda::Agenda(Agenda &&agenda) :
  /* Steal variables */
  storage(agenda.storage),
  actualSize(agenda.actualSize),
  array(agenda.array) {
  /* Reset previous one */
  agenda.storage = 0;
  agenda.actualSize = 0;
  agenda.array = nullptr;
}

/* Destructor */
inline Agenda::~Agenda() {
  /* Delete array */
  delete[] array;
}

// Operator przenoszący:
// https://msdn.microsoft.com/pl-pl/library/dd293665.aspx
/* Operators */
Agenda& Agenda::operator=(const Agenda &agenda) {
  if (this != &agenda) // protect against invalid self-assignment
  {
    // 1: allocate new memory and copy the elements
    int tmpStorage = agenda.storage;
    Data *tmpArray = new Data[agenda.storage];
    for(int i = 0; i < agenda.actualSize; i++)
      tmpArray[i] = agenda.array[i];
    int tmpActualSize = agenda.actualSize;

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
Agenda& Agenda::operator=(Agenda &&agenda) {
  if(this != &agenda) {
    /* Clear current memory allocation */
    delete[] array;
    /* Copy values */
    storage = agenda.storage;
    array = agenda.array;
    actualSize = agenda.actualSize;
    /* Free memory allocation from source object */
    agenda.storage = 20;
    agenda.array = nullptr;
    agenda.actualSize = 0;
  }
  return *this;
}

/* Getter */
int inline Agenda::getElementsQuantity() {
  return this -> actualSize;
}

int inline Agenda::getStorage() const {
  return this -> storage;
}

void Agenda::addData(Data p) {
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
  cout << "__Data__" << endl;
  Data pConstr;
  pConstr.describeData();
  Data pConstr1(5);
  pConstr1.describeData();
  Data pConstr2(2, 11);
  pConstr2.describeData();
  cout << "__Agenda__" << endl;
  Agenda gConstr;
  cout << gConstr.getStorage() << endl;
  Agenda gConstr1(15);
  cout << gConstr1.getStorage() << endl;

  /* Supporting objects */
  Data p1(21, 5);
  Data p2(31, 12);
  Data p3(25, 4);

  /* Adding Data to Agenda */
  cout << endl << "__Adding Data to Agenda and testing getElementsQuantity()__" << endl;
  Agenda gBase(3);
  cout << "Before " << gBase.getElementsQuantity() << endl;
  gBase.addData(p1);
  gBase.addData(p2);
  gBase.addData(p3);
  cout << "After " << gBase.getElementsQuantity() << endl;

  /* Copy constructor and move constructor - based on gBase */
  cout << endl << "__Copy and move constructor__" << endl;
  /* Copy constructor */
  cout << "__Copy constructor__" << endl;
  Agenda gCopy(gBase);
  cout << "Base " << gBase.getElementsQuantity() << endl;
  cout << "Copy " << gCopy.getElementsQuantity() << endl;
  cout << "__Move constructor__" << endl;
  /* Move constructor */
  Agenda gMove(move(gBase));
  cout << "Base " << gBase.getElementsQuantity() << endl;
  cout << "Move " << gMove.getElementsQuantity() << endl;

  /* Assignment and move assignment operators */
  cout << endl << "__Assignment and move assignment operators__" << endl;
  /* Assignment operator */
  cout << "__Assignment operator__" << endl;
  Agenda gBaseOp(3);
  gBaseOp.addData(p1);
  gBaseOp.addData(p2);
  gBaseOp.addData(p3);
  Agenda gAssign = gBaseOp;
  cout << "Base " << gBaseOp.getElementsQuantity() << endl;
  cout << "Assign " << gAssign.getElementsQuantity() << endl;
  /* Move assignment operator */
  cout << "__Move assignment operator__" << endl;
  Agenda gMoveAssign = move(gBaseOp);
  cout << "Base " << gBaseOp.getElementsQuantity() << endl;
  cout << "MoveAssign " << gMoveAssign.getElementsQuantity() << endl;



  /* Exceptions */
  try {
    Agenda tryG(0);
  }
  catch(const std::invalid_argument& e) {
    cout << endl << "Cought exception!" << endl;
  }

  return 0;
}
