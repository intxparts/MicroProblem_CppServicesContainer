#pragma once
#include <vector>
#include <memory>
#include <string>

namespace Services {
	struct PrinterRecord
	{
		std::string name;
	};

	class IPrintDBService
	{
	public:
		virtual std::vector<std::shared_ptr<PrinterRecord>> GetPrinters() = 0;
	};

	class IComplexService {
	public:
		virtual int ComputeResult() = 0;
	};
}

namespace Framework {

	class IContainer {

	public:
		virtual std::shared_ptr<Services::IPrintDBService> GetPrintDBService() = 0;
		virtual std::shared_ptr<Services::IComplexService> GetComplexService() = 0;
	};
}