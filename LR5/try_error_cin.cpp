#include <stdio.h>
#include "try_error_cin.hpp"

bool Try_Error_Cin(char& ChoiceYesOrNo)
{
	while (ChoiceYesOrNo != 'y' || ChoiceYesOrNo != 'n')
	{
		scanf(" %c", &ChoiceYesOrNo);
		if (ChoiceYesOrNo == 'y' || ChoiceYesOrNo == 'n')
			return (ChoiceYesOrNo == 'y');
		else
		{
			printf("%s", "Invalid character! Repeat: ");
			rewind(stdin);
		}
	}
};

void Try_Error_Cin(size_t& ChoiceNumber)
{
	while (!(scanf("%d", &ChoiceNumber)))
	{
		printf("%s", "Invalid value! Repeat: ");
		rewind(stdin);
	}
};