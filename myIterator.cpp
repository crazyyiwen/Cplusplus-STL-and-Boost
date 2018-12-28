// std::iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

using namespace std;

class MyIterator : public iterator<forward_iterator_tag, int>
{
  int *p;
public:
  MyIterator(int *x) :p(x) {}
  //MyIterator(const MyIterator& mit) : p(mit.p) {}
  MyIterator &operator++() {++p;return *this;}
  MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
  bool operator==(const MyIterator &rhs) const {return p==rhs.p;}
  bool operator!=(const MyIterator &rhs) const {return p!=rhs.p;}
  int &operator=(int *pass){this->p = pass; return *(this->p);}
  int &operator*() {return *p;}
};

int main () {
  int numbers[]={10,20,30,40,50};
  int num = 100;
  MyIterator from(numbers);
  MyIterator until(numbers+5);
  for (MyIterator it=from; it!=until; it++)
    cout << *it << ' ';
  cout << '\n';
  from = &num;
  num = *(from);

  return 0;
}
