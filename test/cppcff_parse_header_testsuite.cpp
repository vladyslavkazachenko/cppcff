#include "header.h"

#include "gtest/gtest.h"

TEST(cppcff_parse_header, success_version10_hdrSize100_offSize1) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		0,       //minor
        100,     //hdrSize
		1        //offSize
	};
	int result = cppcff::ParseHeader(data, sizeof(data), header);
    ASSERT_EQ(0, result);
	ASSERT_EQ(header.major_, 1);
	ASSERT_EQ(header.minor_, 0);
	ASSERT_EQ(header.hdrSize_, 100);
	ASSERT_EQ(static_cast<std::uint8_t>(header.offSize_), 1);
}

TEST(cppcff_parse_header, success_version11_hdrSize100_offSize1) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		1,       //minor
        100,     //hdrSize
		1        //offSize
	};
	int result = cppcff::ParseHeader(data, sizeof(data), header);
    ASSERT_EQ(0, result);
	ASSERT_EQ(header.major_, 1);
	ASSERT_EQ(header.minor_, 1);
	ASSERT_EQ(header.hdrSize_, 100);
	ASSERT_EQ(static_cast<std::uint8_t>(header.offSize_), 1);
}

TEST(cppcff_parse_header, success_version11_hdrSize101_offSize1) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		1,       //minor
        101,     //hdrSize
		1        //offSize
	};
	int result = cppcff::ParseHeader(data, sizeof(data), header);
    ASSERT_EQ(0, result);
	ASSERT_EQ(header.major_, 1);
	ASSERT_EQ(header.minor_, 1);
	ASSERT_EQ(header.hdrSize_, 101);
	ASSERT_EQ(static_cast<std::uint8_t>(header.offSize_), 1);
}

TEST(cppcff_parse_header, success_version11_hdrSize101_offSize2) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		1,       //minor
        101,     //hdrSize
		2        //offSize
	};
	int result = cppcff::ParseHeader(data, sizeof(data), header);
    ASSERT_EQ(0, result);
	ASSERT_EQ(header.major_, 1);
	ASSERT_EQ(header.minor_, 1);
	ASSERT_EQ(header.hdrSize_, 101);
	ASSERT_EQ(static_cast<std::uint8_t>(header.offSize_), 2);
}

TEST(cppcff_parse_header, failed_nullptr) 
{
	cppcff::Header header;
	int result = cppcff::ParseHeader(nullptr, 0, header);
    ASSERT_EQ(cppcff::parse_header::kErrorData, result);
}

TEST(cppcff_parse_header, failed_dataSize0) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		1,       //minor
        101,     //hdrSize
		2        //offSize
	};
	int result = cppcff::ParseHeader(data, 0, header);
    ASSERT_EQ(cppcff::parse_header::kErrorDataSize, result);
}

TEST(cppcff_parse_header, failed_dataSize1) 
{
	cppcff::Header header;
	const std::uint8_t data[] = {
		1,       //major
		1,       //minor
        101,     //hdrSize
		2        //offSize
	};
	int result = cppcff::ParseHeader(data, 1, header);
    ASSERT_EQ(cppcff::parse_header::kErrorDataSize, result);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}