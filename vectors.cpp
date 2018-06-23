#include <iostream>
#include <vector>

using namespace std;

double sum(vector<double> values);
void multiply(vector<double>& values, double factor);
vector<int> squares(int n);
void printDoub(const vector<double>& values);
void printInt(const vector<int>& values);
void remove(vector<double> & values, int pos);
void insert(vector<double> & values,int value ,int pos);

int main() {
  vector<double> v1 = {1,2,3,4,5};
  printDoub(v1);
  cout << "Sum function ----------" << endl;
  double total = sum(v1);
  cout << "Total : " << total << endl;
  cout << "Multiply function ----------" << endl;
  multiply(v1, 2);
  printDoub(v1);
  cout << "Factoring function ----------" << endl;
  printInt(squares(5));
  cout << "Remove at position function ----------" << endl;
  remove(v1, 1);
  printDoub(v1);
  cout << "Insert at position function ----------" << endl;
  insert(v1,888, 3);
  printDoub(v1); 




 
  return 0;
}

double sum(vector<double> values){
  double total = 0;
  for(int i = 0; i < values.size(); ++i){
    total += values[i];
  }
  return total;
};
void multiply(vector<double>& values, double factor){
  for(int i = 0; i < values.size(); ++i){
    values[i] *= factor;
  }
};
vector<int> squares(int n){
  vector<int> result;
  for(int i = 0; i < n; ++i){
    result.push_back(i*i);
  }
  return result;
};
void remove(vector<double> & values, int pos){
  for(int i = pos + 1; i < values.size(); ++i){
    values[i-1] = values[i];
  } 
  values.pop_back();
};
void insert(vector<double> & values,int value, int pos){
  int last_position = values.size() - 1;
  values.push_back(values[last_position]);
  for(int i = last_position; i > pos; --i){
    values[i] = values[i-1];
  } 
  values[pos] = value;

};
void printDoub(const vector<double>& values){

  for(int i = 0; i < values.size(); ++i){
    cout << values[i] << endl;
  }

};
void printInt(const vector<int>& values){

  for(int i = 0; i < values.size(); ++i){
    cout << values[i] << endl;
  }

};
