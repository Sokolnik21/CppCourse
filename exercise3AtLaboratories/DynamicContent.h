#include <string>
using namespace std;

class Data {
public:
  /* Constructor */
  Data(int day = 1, int month = 1);

  /* Describe */
  void describeData();

private:
  int day;
  int month;
};

class Agenda {
public:
  /* Constructors */
  /* Basic constructor */
  Agenda(int storage = 6);
  /* Copy constructor */
  Agenda(const Agenda &agenda);
  /* Move constructor */ // - konstruktor przenoszenia (C++ 11)
  Agenda(Agenda &&agenda);

  /* Destructor */
  ~Agenda();

  /* Operators */
  Agenda& operator=(const Agenda &agenda);
  /* Move assignment operator */
  Agenda& operator=(Agenda &&agenda);

  /* Getter */
  int getElementsQuantity();
  int getStorage();

  void addData(Data p);

private:
  Data *array;
  int storage;
  int actualSize;
};
