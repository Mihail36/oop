#include "CController.h"

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	std::vector<std::shared_ptr<CBody>> bodies;
	CController controller(std::cin, std::cout, bodies);
	controller.ProcessInput();

	return 0;
}