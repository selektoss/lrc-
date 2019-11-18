#include <stdio.h>
#include "FuncFile.hpp"

int main(void)
{
	printf_s("%s", "0. Enter name txt file.  \r\n1. Open file to process.\
				  \r\n2. Enter the number K to search for sentences consisting of a given number of words.\
				  \r\n3. Close File.\
				  \r\n4. Exit program.");
	size_t ChoiceNumberMenu = NULL;
	const size_t MaxChar = 21;
	char fileName[MaxChar];
	FILE* fileX = nullptr;
	char* ArrText = nullptr;

	do
	{
		printf("%s", "\r\nMake your choice: ");
		Try_Error_Scan(ChoiceNumberMenu);

		if ((ChoiceNumberMenu <= 4) && (ChoiceNumberMenu >= NULL)) {
			switch (ChoiceNumberMenu)
			{
			case 0:
				GreateNameFile(fileName, MaxChar);
				break;
			case 1:
				fileX = ConnectFile(fileX, fileName);
				break;
			case 2:
				ArrText = SearchSuggestionsAndGreateDynamicMemory(fileX, fileName, ArrText);
				break;
			case 3:
				fileX = CloseFile(fileX);
				break;
			case 4:
				break;
			}
		}
		else printf("%s", "Error. Repeat your choice  Waiting : ");
	} while (ChoiceNumberMenu != 4);
	
	
	return 0;
}
