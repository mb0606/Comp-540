
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    string last, curr;
    bool repeated = false;
    while(cin >> curr){
        if(curr[0] < 'A' || curr[0] > 'Z'){
            cout << curr << " is not capitalized." << endl;
            continue;
        }  
        if(curr == last){
            cout << "You have repeated the word: " << curr << endl;
            repeated = true;
            break;
        }
        last = curr;
    }
    if(!repeated){
       cout << "No words where repeated. " << endl; 
    }
    return 0;
}
