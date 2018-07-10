#include <iostream>
using namespace std;

int main(){
    int p = 5;
    int const * const q = &p;
	//q++;     error
    //(*q)++;       error

}
