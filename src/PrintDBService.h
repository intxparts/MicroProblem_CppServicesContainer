#pragma once

#include <vector>
#include <memory>
#include <string>

#include "IContainer.h"

namespace Services {

	class PrintDBService : public IPrintDBService
	{
	public:
		std::vector<std::shared_ptr<PrinterRecord>> GetPrinters() override
		{
			std::vector<std::shared_ptr<PrinterRecord>> list;
			auto record = std::make_shared<PrinterRecord>();
			record->name = "XeroX";

			list.push_back(record);
			return list;
		}
	};

}