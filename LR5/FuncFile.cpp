#include "FuncFile.hpp"
#include "Windows.h"

static int checkFile = NULL;

void GreateNameFile(char* fileName, const size_t &size = 21)
{
	if (!checkFile) {
		int scanName = 1;
		printf("%s", "Please enter a text file name. Max line char 20. Example YourFile.txt : ");
		while (scanName)
		{
			if (scanf_s("%s", fileName, size))
			{
				--scanName;
			}
			else { rewind(stdin); }
		}
	} else printf("%s%s%s", "File open is ", fileName, " Please close this file!");	
};

FILE* ConnectFile(FILE* fileX, char* filename)
{
	if (!checkFile) {
		while (!(fileX = fopen(filename, "r")))
		{
			printf("%s\n", "Error opening file! Change name, file path.");
			GreateNameFile(filename);		 
		}
		checkFile = 1;
		printf("%s", "OK! File is open.");
	} else printf("%s", "File is alredy open!");

	return fileX;
};

char* SearchSuggestionsAndGreateDynamicMemory(FILE* fileX, char* filename, char* ArrText)
{
	SetConsoleOutputCP(1251);
	if ((checkFile) && (!ArrText))
	{
		fseek(fileX, 0, SEEK_END);
		size_t lenText = (ftell(fileX));
		ArrText = new char[lenText];
		char ChoiceYesOrNo = NULL;
		do {
			size_t shiftIndex = NULL, resultFscanfCode = NULL, countLen = NULL, count = NULL, 
			tempLen = NULL, numberWord = NULL, counterSearching = NULL;
		
			printf("%s", "Enter number word, for search to text File = ");
			Try_Error_Scan(numberWord);
			fseek(fileX, 0, SEEK_SET);
			while ((resultFscanfCode = fscanf(fileX, "%[^.!?]", ArrText + (countLen + shiftIndex))) != EOF)
			{
				fseek(fileX, 1, SEEK_CUR);
				if (resultFscanfCode) 
				{
					tempLen = (countLen + shiftIndex);
					countLen += (strlen(ArrText + (countLen + shiftIndex))) + shiftIndex;
					count = 1 ? ((*(ArrText + tempLen) != ' ')) : count = NULL;
					for (size_t i = tempLen; i < countLen; i++)
					{
						if (*(ArrText + i) == ' ' && *(ArrText + (i + 1)) != '-')
							count++;
					}
					shiftIndex = 1;
				}
				if (count == numberWord) 
				{
					counterSearching++;
					printf("%s\n\r", (ArrText + (tempLen)));
				}
			}
			if (!counterSearching)
				printf("%s\n\r", "No sentences found in the text.");
			else printf("%s%d\n\r", "The number of sentences found = ", counterSearching);

			printf("%s", "Continue searching? (y/n) : ");
		} while (Try_Error_Scan(ChoiceYesOrNo));
	} 
	delete[] ArrText;
	CloseFile(fileX);
	return nullptr;
};

void CloseFile(FILE* fileX)
{
	if (checkFile) {
		fclose(fileX);
		printf("%s", "File is close.");
		checkFile = NULL;
	} else printf("%s", "Nothing to close.");
};
