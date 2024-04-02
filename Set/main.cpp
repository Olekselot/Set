#include <iostream>
#include "Set.h"

using namespace std;
int main()
{
	Set<int> A;
	Set<int> B;
	A.add_element(1).add_element(3);
	cout << A << endl;
	/* system("pause");*/
	return 0;
}
