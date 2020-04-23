#include "__LoadObjectForm__.hpp"
#include <iostream>

int main(void)
{	
	ModelOBJ* objForm(LoadObjectForm());
	int chois(0);
	while ((chois = ChoisMenu(objForm)) < objForm->sizeMenu - 1)
	{
		switch (chois)
		{
		case 0:
		{
			std::cout << "\n\n\n1 Function";

		} break;
		case 1:
		{
			std::cout << "\n\n\n2 Function";

		} break;
		case 2:
		{
			std::cout << "\n\n\n3 Function";
		} break;
		case 3:
		{
			std::cout << "\n\n\n4 Function";
		} break;
		case 4:
		{
			std::cout << "\n\n\n5 Function";
		} break;
		case 5:
		{
			std::cout << "\n\n\n6 Function";
		} break;
		case 6:
		{
			std::cout << "\n\n\n7 Function";
		} break;
		}
	}
	return 0;
};