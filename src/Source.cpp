#include <iostream>


#include "Container.h"


int main()
{
	auto container = Framework::Container::instance();
	auto dbService = container->GetPrintDBService();
	auto records = dbService->GetPrinters();
	auto complexService = container->GetComplexService();

	auto s = complexService->ComputeResult();
	std::cout << s << std::endl;

	for (auto r : records)
	{
		std::cout << r->name << std::endl;
	}

	return 0;
}