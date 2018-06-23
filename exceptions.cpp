#include <iostream>
using namespace std;

class wrongClass{
  public:
  wrongClass(){
    int * arrInt = new int[99999999999999];
    delete [] arrInt;
  }

};
class MyException: public exception {
  public: 
    virtual const char* what() const throw(){
      return "Something Bad Happened";
    }

};
class Test {
  public: 
  void goesWrong() {
    throw MyException();
  }
  void wrongNum() {
    throw 10;
  }
};

int main() {
  try
  {
  wrongClass wrong;
  }
  catch(bad_alloc &e)
  {
    cout << e.what() << " is an error " << endl;
  }
  // Create new object.
  Test test;
  try 
  {
    // test.goesWrong(); 
    test.wrongNum();
  } 
  catch (MyException &e)
  {
    cout << e.what() << endl;
  }
  catch (int num)
  {
    cout << "Error code : " << num << endl;
  }

}
