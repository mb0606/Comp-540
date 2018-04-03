// Using exception handling 
// Try Catch
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    int a,b;
    bool tryAgain;
    
    do {
        tryAgain = false;
        try {
            cout << "Enter two number to be divided."<< endl;
            cin >> a >> b;
            if(b == 0){
                throw runtime_error("Cannot divide by 0.");
            }
            cout << (float)a / (float)b << endl;
        } catch(runtime_error err){
            cout << err.what() << "\nTry Again? (y/n)." << endl;
            char c;
            if(cin >> c && (c == 'y' || c == 'Y')){
                tryAgain = true;
            }
        }
        
    } while(tryAgain);
}