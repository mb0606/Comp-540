#include <vector>
#include <iostream>

using namespace std;

int foo(int, int);
int bar(int, int);

int main() {
  //
  vector<int (*)(int, int)> vf;

  vf.push_back(foo);
  vf.push_back(bar);

  vf[0](1, 2);
  vf[1](3, 4);

  for (const auto &index : vf)
    index(9, 9);

  return 0;
}

int foo(int a, int b) {
  cout << "Called foo(" << a << ", " << b << ")" << endl;
  return 0;
}

int bar(int a, int b) {
  cout << "Called bar(" << a << ", " << b << ")" << endl;
  return 0;
}
