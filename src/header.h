#pragma once

#include <cstdint>
#include <cstdlib>

#include "typedefs.h"

namespace cppcff
{
	struct Header
	{
		Card8 major_;
		Card8 minor_;
		Card8 hdrSize_;
		OffSize offSize_;
	};
	int ParseHeader(const std::uint8_t * const data, size_t dataSize, Header &header);
}