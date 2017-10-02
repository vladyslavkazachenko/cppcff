#pragma once

#include <cstdint>

namespace cppcff
{
	typedef std::uint8_t Card8;
	typedef std::uint16_t Card16;
	enum class OffSize : std::uint8_t
	{
		k1 = 1,
		k2 = 2,
		k3 = 3,
		k4 = 4,
	};
	template <OffSize _OffSize>
	struct Offset
	{
		
	};
	
	template <>
	struct Offset<OffSize::k1>
	{
		struct 
		{
			std::uint8_t byte1_;
		} value_;
	};
	
	template <>
	struct Offset<OffSize::k2>
	{
		struct 
		{
			std::uint8_t byte2_;
			std::uint8_t byte1_;
		} value_;
	};
	
	template <>
	struct Offset<OffSize::k3>
	{
		struct 
		{
			std::uint8_t byte3_;
			std::uint8_t byte2_;
			std::uint8_t byte1_;
		} value_;
	};
	
	template <>
	struct Offset<OffSize::k4>
	{
		struct 
		{
			std::uint8_t byte4_;
			std::uint8_t byte3_;
			std::uint8_t byte2_;
			std::uint8_t byte1_;
		} value_;
	};
}