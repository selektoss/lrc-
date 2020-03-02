#include <random>
#include <iomanip>
#include "FuncArray.hpp"

float** Great_Array_Dynamic_Memory(float **pArr, uint16_t &lineArr, uint16_t &columnArr)
{
	const int16_t minLine = 2;
	char ChoiceYesOrNo;
	if (pArr)
	{
		std::cout << "The matrix is already! Delete? (y/n): ";
		if (Try_Error_Cin(ChoiceYesOrNo))
		{
			pArr = Delete_Arr(pArr);
		}
	}
	else
	{
		do
		{
			std::cout << "Enter the number of rows of the matrix : ";
			Try_Error_Cin(lineArr);
		} while ((lineArr < minLine));

		pArr = new float *[lineArr];
		do
		{
			std::cout << "Enter the number of matrix columns : ";
			Try_Error_Cin(columnArr);
		} while ((columnArr == lineArr) || (columnArr < minLine));
		*pArr = new float[lineArr * columnArr];

		for (size_t i = 0; i < lineArr; i++)
		{
			*(pArr + i) = *(pArr) + (i * columnArr);
		}

		std::cout << "Will the matrix be filled with random R numbers? (y/n): ";

		if (Try_Error_Cin(ChoiceYesOrNo))
		{
			float start_number_random = -3;
			float end_number_random = 3;
			std::uniform_real_distribution<float> un_real(start_number_random, end_number_random);
			std::default_random_engine mtDefault;
			for (size_t i = 0; i < lineArr; i++)
			{
				for (size_t j = 0; j < columnArr; j++)
				{
					float random_double_result = un_real(mtDefault);
					*(*(pArr + i)+j) = random_double_result;
				}	
			}
		}
		else
		{
			float ElementNumberInsertArray;
			for (size_t i = 0; i < lineArr; i++)
			{
				std::cout << "Fill in the line №" << i + 1 << std::endl;
				for (size_t j = 0; j < columnArr; j++)
				{
					std::cout << "Enter a real number №" << j + 1 << " : ";
					*(*(pArr + i)+j) = Try_Error_Cin(ElementNumberInsertArray);
				}
			}
		}
		if (pArr)
		{
			std::cout << "Array created successfully!" << std::endl;
		} else std::cout << "The array was not created!";
	}
	return pArr;
};

static uint16_t FixedIndexAdress = NULL;

float** Delete_Arr(float **PointerArr)
{	
	if (PointerArr)
	{	
		delete[] *(PointerArr+FixedIndexAdress);
		delete[] PointerArr;		
		std::cout << "Matrix deleted successfully!" << std::endl;
		PointerArr = nullptr;
		FixedIndexAdress = NULL;
	} else std::cout << "Nothing to delete!" << std::endl;

	return nullptr;
};

void Show_Arr_Console(float** PointArr, const uint16_t& lineArr, const uint16_t& columnArr)
{
	if (PointArr)
	{
		for (size_t i = 0; i < lineArr; i++)
		{
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);

			for (size_t j = 0; j < columnArr; j++)
			{
				std::cout << " | " << std::setw(6) << *(*(PointArr + i) + j) << " | ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	} else std::cout << "Nothing to print! Create an array" << std::endl;
};

void Search_ColumnArr_SumElement_Positive(float** pointArr, const uint16_t& lineArr, const uint16_t& columnArr)
{
	if (pointArr)
	{
		float temp = NULL;
		uint16_t countColumn = NULL;
		for (size_t j = 0; j < columnArr; j++)
		{
			temp = NULL;
			for (size_t i = 0; i < lineArr; i++)
			{
				temp += *(*(pointArr + i) + j);
			}
			if (temp > 0) ++countColumn;
		}
		std::cout << "Positive Matrix Columns = " << countColumn << std::endl;
	} else { std::cout << "Matrix not found! Create her." << std::endl; }
};

void Cyclic_Shift_Arr(float** pointArr, const uint16_t& lineArr)
{
	if (pointArr)
	{
		uint16_t k, iterK;
		std::cout << "Enter an integer to shift up = ";
		Try_Error_Cin(k);
		uint16_t FixedIndexTemp = NULL;

		if ((k % (lineArr)) == 0)
		{
			std::cout << "Why not move. The resulting matrix will be equal to the original." << std::endl;
		}
		else
		{
			iterK = k % (lineArr);
			FixedIndexTemp = ((lineArr)-(k % lineArr)) + FixedIndexAdress;

			if (FixedIndexTemp == lineArr)
			{
				FixedIndexTemp = NULL;
			} 
			else if (FixedIndexTemp > lineArr)
			{
				FixedIndexTemp -= lineArr;
			}

			for (size_t j = 0; j < iterK; j++)
			{
				float* temp = *(pointArr);
				for (size_t i = 0; i < lineArr - 1; i++)
				{
					*(pointArr + i) = *(pointArr + (i + 1));
				}
				*(pointArr + (lineArr - 1)) = temp;
			}
			FixedIndexAdress = FixedIndexTemp;
		}
	} else { std::cout << "Nothing to shift. Create matrix!" << std::endl; }
};
