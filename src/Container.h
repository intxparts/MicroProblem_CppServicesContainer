#pragma once

#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <memory>
#include <string>

#include "IContainer.h"
#include "PrintDBService.h"
#include "ComplexService.h"

namespace Framework {

	class Container : public IContainer
	{
	private:
		Container(){}

	public:
		Container(const Container&) = delete;
		Container& operator=(const Container&) = delete;

		static std::shared_ptr<Container> instance()
		{
			static std::shared_ptr<Container> inst{ new Container };
			return inst;
		}

		std::shared_ptr<Services::IPrintDBService> GetPrintDBService() override
		{
			return std::make_shared<Services::PrintDBService>();
		}

		std::shared_ptr<Services::IComplexService> GetComplexService() override 
		{
			return std::make_shared<Services::ComplexService>(instance());
		}
	};
}




#endif // CONTAINER_H