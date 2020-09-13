#include <iostream>
using namespace std;

//SINGLE-LINER
int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// **MULTY-LINER+
// int factorial1(int n){
//   if(n>=1){
//     return n*factorial(n-1);
//   } else {
//     return 1;
//   }
// }

int main() {
    cout << factorial(5);
}
