#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const string SPECIES_T[] = {
  "oak",
  "maple",
  "elm",
  "willow"
};

class Tree {
public:
  Tree() {
    int rng = rand();
    species = SPECIES_T[rng%4];
    diameter = 1.05;
    double variation = 0.95 / (double)(rng % 16 + 1);
    rng = rand();
    rng % 2 == 0 ? diameter += variation : diameter -= variation;
    age = 1 + (rng % 100);
  }
  Tree(int _age) {
    int rng = rand();
    species = SPECIES_T[rng%4];
    diameter = 1.05;
    double variation = 0.95 / (double)(rng % 16 + 1);
    rng = rand();
    rng % 2 == 0 ? diameter += variation : diameter -= variation;
    age = _age;
  }
  void describe() const {
    cout << species << "; age: " << age << ", d: " << diameter;
  }
  bool operator==(Tree other) const {
    bool result;
    age == other.age ? result = true :
      species == other.species ? result = true : result = false;
    return result;
  }
  friend bool cmp(Tree a, Tree b);
  friend bool cmpDiameter(Tree a, Tree b);
  friend void increaseDiameter(Tree &t);
  friend bool pred(Tree &t);
  string getName() { return species; };
private:
  string species;
  double diameter;
  int age;
};

bool cmp(Tree a, Tree b) {
  bool result;
  a.age < b.age ? result = true :
    a.species < b.species ? result = true : result = false;
  return result;
}

bool cmpDiameter(Tree a, Tree b) {
  return a.diameter < b.diameter;
}

int COUNTER = 0;

Tree mygen() {
  Tree t(++COUNTER);
  return t;
}

void increaseDiameter(Tree &t) {
  t.diameter += 0.1;
}

bool pred(Tree &t) {
  bool result = (t.diameter < (double)1);
  cout << result << endl;
  return result;
  // return (t.diameter > 1);
}

int main() {
  srand(time(NULL));
  /* First part of the exercise */
  /* Vector operations */
  cout << endl << "Vector operations" << endl;
  vector<Tree> v;
  for(int i = 0; i < 25; i ++) {
    Tree t;
    v.push_back(t);
  }
  /* Iterate through vector using iterator */
  for(Tree t : v) {
    t.describe();
    cout << endl;
  }


  /* Set operations */
  cout << endl << "Set operations" << endl;
  std::pair<std::set<Tree>::iterator,bool> ret;
  set<Tree, bool (*)(Tree, Tree)> s(cmp);
  for(Tree t : v) {
    ret = s.insert(t);
    if(ret.second == false) {
      t.describe();
      cout << endl;
    }
  }

  /* Map operations */
  cout << endl << "Map operations" << endl;
  map<Tree, int, bool(*)(Tree, Tree)> m(cmp);
  std::map<Tree,int>::iterator it = m.begin();
  for(int i = 0; i < 25; i ++) {
    Tree t;
    m.insert(std::pair<Tree, int>(t, rand()%10));
  }
  for (it=m.begin(); it!=m.end(); ++it) {
    it->first.describe();
    cout << " => " << it->second << '\n';  
  }

  /* Second part of the exercise */
  cout << endl << "Second part of the exercise" << endl;
  /* generate */
  cout << endl << "generate" << endl;  
  vector<Tree> v2(25);
  generate(v2.begin(), v2.end(), mygen);
  COUNTER = 0;
  for(Tree t : v2) {
    t.describe();
    cout << endl;
  }

  /* min_element */
  cout << endl << "min_element" << endl;  
  vector<Tree>::iterator result = min_element(begin(v2), end(v2), cmpDiameter);
  result -> describe();
  cout << endl;

  /* count_if */
  cout << endl << "count_if" << endl;
  int number = count_if(v2.begin(), v2.end(), [](Tree t){ return t.getName() == "oak"; });
  cout << number << endl;

  /* for_each */
  cout << endl << "for_each" << endl;
  for_each(v2.begin(), v2.end(), increaseDiameter);
  for(Tree t : v2) {
    t.describe();
    cout << endl;
  }

  /* remove_if */
  cout << endl << "remove_if" << endl;
  remove_if(v2.begin(), v2.end(), pred);
  for(Tree t : v2) {
    t.describe();
    cout << endl;
  }

  return 0;
}