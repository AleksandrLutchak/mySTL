#include <iostream>
#include "Vector.h"
//#include <vector>

using namespace std;

void main()
{
	Vector<int>myVec(10);

	cout << "Size: " << myVec.size() << endl;
	cout << "Cap: " << myVec.capacity() << endl;
	for (size_t i = 0; i < myVec.size(); i++)
	{
		myVec[i] = i;
		cout << myVec[i] << endl;
	}
	
	myVec.resize(20, 13);
	cout << endl;

	cout << "Size: " << myVec.size() << endl;
	cout << "Cap: " << myVec.capacity() << endl;
	for (size_t i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl ;
	}

	cout << endl;

	myVec.clear();
	cout << "Size: " << myVec.size() << endl;
	cout << "Cap: " << myVec.capacity() << endl;
	for (size_t i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}


	system("pause");
}