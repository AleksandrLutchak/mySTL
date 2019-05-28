#include <iostream>
#include "Vector.h"
//#include <vector>

using namespace std;

void main()
{
	Vector<int>myVec(10, 2);

	for (size_t i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

	myVec.resize(5);

	for (size_t i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	system("pause");

}