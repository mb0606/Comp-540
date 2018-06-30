#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void encrypt_file(ifstream& in, ofstream& out, int k){
  char ch;
  while(in.get(ch)){
    out.put(ch + k);
  }
};


int main(int argc, char* argv[]) {
  int key = 3;
  int file_count = 0;
  ifstream in_file;
  ofstream out_file;

  for(int i = 1; i < argc; ++i){
    string arg = argv[i];
    if (arg == "-d"){
      key = -3;
    }
    else {
      ++file_count;
      if(file_count == 1){
        in_file.open(arg.c_str());
        if(in_file.fail()){
          cout << "Error opening input file " << arg << endl;
          return 1;
        }
      }
      else if (file_count == 2){
        out_file.open(arg.c_str());
        if(out_file.fail()){
          cout << "Error opening output file " << arg << endl;
          return 1;
        }
      }
    }
  }
  if(file_count != 2){
    cout << "Usage: " << argv[0] << " [-d] infile outfile " << endl;
    return 1;
  }
  encrypt_file(in_file, out_file, key);
  return 0;

}
