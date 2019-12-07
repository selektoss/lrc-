#include "FuncArr.hpp"
using namespace std;
// Точка входа в программу. Начало.
int main(void)
{
	cout << "0. Show array to console." << endl
	<< "1. Create a sequence of real numbers." << endl
	<< "2. Swap elements with even and odd index." << endl
	<< "3. Sort element in descending order using the insertion sorting algorithm." << endl
	<< "4. Delete array." << endl
	<< "5. Exit program." << endl << endl;

	uint16_t ChoiceNumberMenu = NULL, sizeArr = NULL;
	float* pointArr = nullptr;	
	// Зацикливаем программу.
	do
	{
		std::cout << "Make your choice: ";
		Try_Error_Cin(ChoiceNumberMenu);
		if (ChoiceNumberMenu <= 5) {
			switch (ChoiceNumberMenu)
			{
			case 0:
				// Вызов функции вывода на консоль
				Show_Arr_Console(pointArr, sizeArr);
				break;
			case 1:
				// Вызов функции создания массива
				pointArr = Great_Array_Dynamic_Memory(pointArr,sizeArr);
				break;
			case 2:
				// Проверяем на четность размер массива
				if (sizeArr % 2 == NULL)
				// Меняем элементы местами (чет.нечет)
				Swap_Element_Arr(pointArr, sizeArr);
				else Swap_Element_Arr(pointArr, sizeArr - 1);
				break;
			case 3:
				// Вызов функции сортировки мет. прямого выбора
				Sort_Arr_Descending_InsertMethod(pointArr, sizeArr - 1);
				break;
			case 4:
				// Удаление массива
				pointArr = Delete_Arr(pointArr);
				break;
			case 5:
				cout << "Program completion!";
				break;
			}
				} 
			else cout << "Error. Repeat your choice " << endl << "Waiting : ";
		}
		while (ChoiceNumberMenu != 5);

		if (pointArr)
		{
			delete[] pointArr;
		}
	// Завершение программы
	return 0;
}