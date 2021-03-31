#pragma once

#include <memory>

#include "IContainer.h"

namespace Services {

    class ComplexService : public IComplexService
    {
    private:
        std::shared_ptr<Services::IPrintDBService> _dbService;

    public:
        ComplexService(const std::shared_ptr<Framework::IContainer> container)
            : _dbService(container->GetPrintDBService())
        {
        }

        int ComputeResult() override
        {
            auto printers = _dbService->GetPrinters();
            bool isFound = false;
            for (auto& p : printers)
            {
                if (p->name == "XeroX")
                {
                    isFound = true;
                    break;
                }
            }

            return isFound ? 1 : -1;
        }
    };

}