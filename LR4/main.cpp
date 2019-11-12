#include <iostream>
#include "FuncArray.hpp"
using namespace std;

int main(void)
{
	cout << "0. Show array console." << endl
		<< "1. Create a rectangular matrix." << endl
		<< "2. Perform a cyclic shift of the matrix top by k elements." << endl
		<< "3. Determine the number of columns of a matrix with a positive sum of elements." << endl
		<< "4. Delete matrix" << endl
		<< "5. Exit programm" << endl << endl;

	int16_t ChoiceNumberMenu = NULL, lineArr = NULL, columnArr = NULL;
	float** pointArr = nullptr; float* StartAdressArr = nullptr;
	do
	{
		std::cout << "Make your choice: ";
		Try_Error_Cin(ChoiceNumberMenu);
		if ((ChoiceNumberMenu <= 5) && (ChoiceNumberMenu >= NULL)) {
			switch (ChoiceNumberMenu)
			{
			case 0:
				Show_Arr_Console(pointArr, lineArr, columnArr);
				break;
			case 1:
				pointArr = Great_Array_Dynamic_Memory(pointArr, lineArr, columnArr);
				break;
			case 2:

				Ñyclic_Shift_Arr(pointArr, lineArr);
				break;
			case 3:
				Search_ColumnArr_SumElement_Positive(pointArr, lineArr, columnArr);
				break;
			case 4:
				pointArr = Delete_Arr(pointArr);
				break;
			case 5:
				cout << "Program completion!";
				break;
			}
		}
		else cout << "Error. Repeat your choice " << endl << "Waiting : ";
	} while (ChoiceNumberMenu != 5);

	if (pointArr)
	{
		delete[] *pointArr;
		delete[] pointArr;
	}
	return 0;
}