#include <iostream>
using namespace std;
#include "student.cpp"

int main(){
	char name[] = "abcd";
	Student s1(20, name);
	s1.display();

	Student s2(s1);		//copy constructor will do shallow copy

	s2.name[0] = 'x';
	s1.display();
	s2.display();
}
/* If inbuild copy constructor is used. It will do shallow copy.
   abcd 20
   xbcd 20
   xbcd 20
 */

 /* If own copy constructor is used. It will do deep copy.
    abcd 20
    abcd 20
    xbcd 20
  */
