#include <string>
using namespace std;

class Group;

class Person {
public:
  /* Constructor */
  Person(string name = "Jan", int birth = 31);

  // /* Destructor */
  // ~Person();
// private:
  string name;
  int birth;
};

class Group {
public:
  /* Constructors */
  Group(int storage = 20);
  /* Copy constructor */
  Group(const Group &group);
  /* Move constructor */ // - konstruktor przenoszenia (C++ 11)
  Group(Group &&group);

  /* Destructor */
  ~Group();

  /* Operators */
  Group& operator=(const Group &group);

  /* Getter */
  int getElementsQuantity();

// private:
  Person *array;
  int storage;
  int actualSize;
};
