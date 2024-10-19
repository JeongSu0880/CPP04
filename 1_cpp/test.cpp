#include <iostream>
using namespace std;

class X {
public:
  int a;
  void f(int b) {
    cout << "The value of b is "<< b << endl;
  }
};

int main() {
	int	a;
	int &ref_a = a;

	cout << "a ::: " << a;
	cout << "ref_a ::: " << ref_a;
}