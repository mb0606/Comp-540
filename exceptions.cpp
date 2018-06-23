#include <iostream>
using namespace std;

class wrongClass{
  public:
  wrongClass(){
    int * arrInt = new int[99999999999999];
    delete [] arrInt;
  }

};

int main() {
  try{
  wrongClass wrong;

  }catch(bad_alloc &e){
    cout << e.what() << " is an error " << endl;
  }

}
