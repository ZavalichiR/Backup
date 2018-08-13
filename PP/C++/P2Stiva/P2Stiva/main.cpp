#include"Header.h"
int main()
{

	stiva<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << "POP: " << st.pop() << endl;
	cout << "TOP: " << st.top() << endl;



	system("pause");
	return 0;
}