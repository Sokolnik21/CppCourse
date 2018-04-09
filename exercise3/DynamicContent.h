#include <string>
using namespace std;

class Group;

class Person {
public:
  /* Constructor */
  Person(string name = "Ala", int birth = 31);

  /* Describe */
  void describePerson();

private:
  string name;
  int birth;
};

class Group {
public:
  /* Constructors */
  /* Basic constructor */
  Group(int storage = 20);
  /* Copy constructor */
  Group(const Group &group);
  /* Move constructor */ // - konstruktor przenoszenia (C++ 11)
  Group(Group &&group);

  /* Destructor */
  ~Group();

  /* Operators */
  Group& operator=(const Group &group);
  /* Move assignment operator */
  Group& operator=(Group &&group);

  /* Getter */
  int getElementsQuantity();
  int getStorage();

  void addPerson(Person p);

private:
  Person *array;
  int storage;
  int actualSize;
};
