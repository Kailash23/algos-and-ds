#include <iostream>
using namespace std;
int main()
{
  float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
  float *ptr1 = &arr[0];
  float *ptr2 = ptr1 + 3;
  cout<<*ptr2<<endl;    //90.5
  cout<< ptr2-ptr1<<endl;   //3
  cout<<ptr1<<endl;   //0x61ff04
  cout<<ptr2<<endl;   //0x61ff10
  return 0;
}
