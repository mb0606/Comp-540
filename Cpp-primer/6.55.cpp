#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main() {
  vector<int (*)(int, int)> vf;

  vf.push_back(add);
  vf.push_back(subtract);
  vf.push_back(multiply);
  vf.push_back(divide);

  int a, b;
  cin >> a >> b;
  for (const auto &index : vf) {
    cout << index(a, b) << endl;
  }

  return 0;
}

int add(int a, int b) {
  cout << "Called add(" << a << ", " << b << ")" << endl;
  return a + b;
}

int subtract(int a, int b) {
  cout << "Called subtract(" << a << ", " << b << ")" << endl;
  return a - b;
}

int multiply(int a, int b) {
  cout << "Called multiply(" << a << ", " << b << ")" << endl;
  return a * b;
}

int divide(int a, int b) {
  cout << "Called divide(" << a << ", " << b << ")" << endl;
  try {
    if (b == 0)
      throw runtime_error("Cannot divide by 0.");
    return (float)a / (float)b;
  } catch (runtime_error err) {
    cerr << err.what() << endl;
    return 0;
  }
}
