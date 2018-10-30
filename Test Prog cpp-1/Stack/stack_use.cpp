#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> S)
{
	stack <int> s = S;
	while (!s.empty())
	{
		cout <<s.top()<<" ";
		s.pop();
	}
	cout << '\n';
}

int main ()
{
	stack <int> S;
	S.push(10);
	S.push(30);
	S.push(20);
	S.push(5);
	S.push(1);

	cout << "The stack S is : ";
	showstack(S);

	cout << "\nS.size() : " << S.size();
	cout << "\nS.top() : " << S.top();

	cout << "\nS.pop() : ";
	S.pop();
	showstack(S);
	return 0;
}
