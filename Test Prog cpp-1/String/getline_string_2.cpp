#include <iostream>
using namespace std;
int main() {
    char name[20];                   //declaring string 'name'
    cin.getline(name, sizeof(name)); //taking string input
    cout << name << endl;            //printing string
    return 0;
}
