#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const string SPECIES_T[] = {
  "milk",
  "water",
  "not-milk",
  "not-milk not-even-water"
};

class Product {
public:
  Product() {
    int rng = rand();
    species = SPECIES_T[rng%4];
    prodYear = 2000 + (rng % 16);
    quantity = 1 + (rng % 100);
  }
  Product(int _quantity) {
    int rng = rand();
    species = SPECIES_T[rng%4];
    prodYear = 2000 + (rng % 15);
    quantity = _quantity;
  }
  void describe() const {
    cout << species << "; quantity: " << quantity << ", prodYear: " << prodYear;
  }
  bool operator==(Product other) const {
    return prodYear == other.prodYear;
  }
  friend bool cmp(Product a, Product b);
  friend bool predFind(Product &t);
  friend bool predCountIf(Product &t);
  friend bool predUnique(const Product &a, const Product &b);
  friend bool cmpSort(const Product &a, const Product &b);
  void setProdYear(int _prodYear) { prodYear = _prodYear; };
  int getProdYear() { return prodYear; };
private:
  string species;
  int prodYear;
  int quantity;
};

bool cmp(Product a, Product b) {
  bool result;
  a.quantity < b.quantity ? result = true :
    a.species < b.species ? result = true : result = false;
  return result;
}

int COUNTER = 9;

Product mygen() {
  Product t(++COUNTER);
  return t;
}

int howManyQuantity;

bool predFind(Product &t) {
  bool result = (t.prodYear == 2010);
  return result;
}

bool predCountIf(Product &t) {
  bool result = (t.prodYear == howManyQuantity);
  return result;
}

bool cmpSort(const Product &a, const Product &b) {
  if(a.prodYear < b.prodYear)
    return true;
  if(a.prodYear == b.prodYear && a.species < b.species)
    return true;
  return false;
}

bool predUnique(const Product &a, const Product &b) {
  cout << (a.species == b.species) << endl;
  return a.species == b.species;
}

int main() {
  srand(time(NULL));
  cin >> howManyQuantity;
  /* First part of the exercise */
  /* Vector operations */
  cout << endl << "Vector operations" << endl;
  vector<Product> v;
  for(int i = 0; i < 25; i ++) {
    Product t;
    v.push_back(t);
  }
  /* Iterate through vector using iterator */
  for(Product t : v) {
    t.describe();
    cout << endl;
  }


  /* Set operations */
  cout << endl << "Set operations" << endl;
  std::pair<std::set<Product>::iterator,bool> ret;
  set<Product, bool (*)(Product, Product)> s(cmp);
  for(Product t : v) {
    ret = s.insert(t);
    if(ret.second == false) {
      t.describe();
      cout << endl;
    }
  }

  /* Map operations */
  cout << endl << "Map operations" << endl;
  map<Product, int, bool(*)(Product, Product)> m(cmp);
  std::map<Product,int>::iterator it = m.begin();
  for(int i = 0; i < 25; i ++) {
    Product t;
    m.insert(std::pair<Product, int>(t, rand()%10));
  }
  for (it=m.begin(); it!=m.end(); ++it) {
    it->first.describe();
    cout << " => " << it->second << '\n';
  }

  /* Second part of the exercise */
  cout << endl << "Second part of the exercise" << endl;
  /* generate */
  cout << endl << "generate" << endl;
  vector<Product> v2(30);
  generate(v2.begin(), v2.end(), mygen);
  COUNTER = 0;
  for(Product t : v2) {
    t.describe();
    cout << endl;
  }

  /* find */
  cout << endl << "find" << endl;
  Product t2;
  t2.setProdYear(2010);
  vector<Product>::iterator result = find(begin(v2), end(v2), t2);
  if(result != end(v2)) {
    result -> describe();
    cout << endl;
  }
  else {
    cout << "There is none product made in 2010" << endl;
  }

  /* count_if */
  cout << endl << "count_if" << endl;
  int number = count_if(v2.begin(), v2.end(), predCountIf);
  cout << number << endl;

  /* sort */
  cout << endl << "sort" << endl;
  sort(v2.begin(), v2.end(), cmpSort);
  for(Product t : v2) {
    t.describe();
    cout << endl;
  }

  /* unique */
  cout << endl << "unique" << endl;
  // vector<Product>::iterator result2 = unique(v2.begin(), v2.end(), predUnique);
  auto end = unique(v2.begin(), v2.end(), predUnique);
  for(Product t : v2) {
    t.describe();
    cout << endl;
  }


  return 0;
}
