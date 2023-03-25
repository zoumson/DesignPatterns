#include "DPUtilities.h"

#pragma once

namespace za
{
	namespace dp
	{
		namespace com
		{
			bool inArray(const std::string& val, const std::vector<std::string>& arr)
			{
				return std::find(arr.begin(), arr.end(), val) != arr.end();
			}

			std::string vectorToString(std::vector<std::string> v) 
			{
				std::string result = "";
				for (int i = 0; i < v.size(); i++) 
				{
					result.append(v.at(i) + ", ");
				}
				return result;
			}

		}
	}

}
