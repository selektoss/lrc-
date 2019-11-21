#include <random>
#include "FuncArr.hpp"
float* Great_Array_Dynamic_Memory(float* pArr, uint16_t& size)
{
	const int16_t MinSizeArr = 5, MaxSizeArr = 100;
	char ChoiceYesOrNo;

	if (pArr)
	{
		std::cout << "Array already created! " << "Delete it? (y/n): ";
		if (Try_Error_Cin(ChoiceYesOrNo))
		{
			pArr = Delete_Arr(pArr);
		}
	}
	else 
	{
		do
		{
			std::cout << "Enter an array size from 5 to 100: ";
			Try_Error_Cin(size);
		} while ((size < MinSizeArr) || (size > MaxSizeArr));

		pArr = new float[size];
		std::cout << "The array will be filled with random R numbers? (y/n): ";

		if (Try_Error_Cin(ChoiceYesOrNo))
		{
			float start_number_random = 0;
			float end_number_random = 3;
			std::uniform_real_distribution<float> un_real(start_number_random, end_number_random);
			std::default_random_engine mtDefault;
			for (size_t i = 0; i < size; i++)
			{
				float random_double_result = un_real(mtDefault);
				*(pArr + i) = random_double_result;
			}
		}
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				float ElementNumberInsertArray;
				std::cout << "Enter a real number ¹" << i + 1 << " : ";
				*(pArr + i) = Try_Error_Cin(ElementNumberInsertArray);
			}
		}
		if (pArr)
		{
			std::cout << "Array created successfully!" << std::endl;
		} else std::cout << "Array was not created!";
	}
	return pArr;
};

void Sort_Arr_Descending_InsertMethod(float* PointArr, const int16_t const &SizeArr)
{
	if (PointArr)
	{
		uint16_t p, q;
		std::cout << "Enter the neighborhood range of a series of numbers to sort 1 < p < q < " << SizeArr << std::endl;
		do 
		{
			std::cout << "p = ";
			Try_Error_Cin(p);
		} while ((p <= 1) || (p >= SizeArr - 1));

		do 
		{
			std::cout << "q = "; 
			Try_Error_Cin(q);
		} while ((q <= p) || (q >= SizeArr));
				
		const uint16_t RangeStartIndex = p;
		for (p; p <= q-1; p++)
		{
			for (size_t i = p; i >= RangeStartIndex; i--)
			{
				if (*(PointArr + (i + 1)) > * (PointArr + (i)))
				{
					*(PointArr + (i + 1)) += *(PointArr + (i));
					*(PointArr + (i)) = *(PointArr + (i + 1)) - *(PointArr + (i));
					*(PointArr + (i + 1)) = *(PointArr + (i + 1)) - *(PointArr + (i));
					
				}
			}			
		}		
		std::cout << "Sort completed!" << std::endl;
	} else { std::cout << "Nothing to Sort! Create an array!" << std::endl; }	
};

void Show_Arr_Console(const float *PointArr, const uint16_t &SizeArr)
{
	if (PointArr) 
	{
		for (size_t i = 0; i < SizeArr; i++)
		{
			std::cout << " | " << *(PointArr + i) << " | ";
		}
		std::cout << std::endl;
	}
	else std::cout << "Nothing to print! Create an array!" << std::endl;
};

void Swap_Element_Arr(float* PointArr, const uint16_t const &SizeArr)
{
	if (PointArr)
	{
		for (size_t i = 0; i < SizeArr / 2; i++)
		{
			*(PointArr + (i + i)) += *(PointArr + (i + (i + 1)));
			*(PointArr + (i + (i + 1))) = *(PointArr + (i + i)) - *(PointArr + (i + (i + 1)));
			*(PointArr + (i + i)) = *(PointArr + (i + i)) - *(PointArr + (i + (i + 1)));
		}
		std::cout << "Changed the elements of even and odd indices!" << std::endl;
	} else std::cout << "Nothing to change! Array not found." << std::endl;
};

float* Delete_Arr(float* PointerArr)
{
	if (PointerArr) 
	{
		delete[] PointerArr;
		std::cout << "The array was successfully deleted!" << std::endl;
		PointerArr = nullptr;
	}
	else std::cout << "Nothing to delete!" << std::endl;

	return nullptr;
};
