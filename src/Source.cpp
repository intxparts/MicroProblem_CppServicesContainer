#include <iostream>


#include "Container.h"

class FakeComplexService : public Services::IComplexService
{
public:
	int ComputeResult() override
	{
		return -1;
	}
};

class TestContainer : public Framework::IContainer
{
public:
	std::shared_ptr<Services::IPrintDBService> GetPrintDBService() override
	{
		return std::make_shared<Services::PrintDBService>();
	}
	std::shared_ptr<Services::IComplexService> GetComplexService() override
	{
		return std::make_shared<FakeComplexService>();
	}
};


int main()
{
	auto container = std::make_shared<TestContainer>();
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