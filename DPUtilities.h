#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <utility>
#include <memory>
#include <stdexcept>
#include <unordered_map>

namespace za
{
	namespace dp
	{
		namespace com
		{
			bool inArray(const std::string& val, const std::vector<std::string>& arr);
			std::string vectorToString(std::vector<std::string> v);
		}
	}

}

