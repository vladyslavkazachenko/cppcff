#include "header.h"

#include <iostream>
#include <cstring>

namespace cppcff
{
	int ParseHeader(const std::uint8_t * const data, size_t dataSize, Header &header)
	{
		int result = 0;
		if(!data)
		{
			std::wclog << "data is nullptr" << std::endl;
			result = 1;
		}
		else
		{
			if(dataSize < sizeof(header))
			{
				std::wclog << "dataSize is too small" << std::endl;
				result = 2;
			}
			else
			{
				memcpy(&header.major_, data, sizeof(header.major_));
				size_t dataOffset = sizeof(header.major_);
				memcpy(&header.minor_, data + dataOffset, sizeof(header.minor_));
				dataOffset += sizeof(header.minor_);
				memcpy(&header.hdrSize_, data + dataOffset, sizeof(header.hdrSize_));
				dataOffset += sizeof(header.hdrSize_);
				memcpy(&header.offSize_, data + dataOffset, sizeof(header.offSize_));
			}
		}
		return result;
	}
}