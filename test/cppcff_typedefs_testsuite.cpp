#include "typedefs.h"

#include "gtest/gtest.h"

TEST(cppcff_typedefs, Card8) 
{
	ASSERT_EQ(sizeof(cppcff::Card8), 1);
	cppcff::Card8 testCard8;
	ASSERT_EQ(sizeof(testCard8), 1);
}

TEST(cppcff_typedefs, Card16) 
{
	ASSERT_EQ(sizeof(cppcff::Card16), 2);
	cppcff::Card16 testCard16;
	ASSERT_EQ(sizeof(testCard16), 2);
}

TEST(cppcff_typedefs, OffSize) 
{
	ASSERT_EQ(sizeof(cppcff::OffSize), 1);
	cppcff::OffSize testOffSize;
	ASSERT_EQ(sizeof(testOffSize), 1);
	ASSERT_EQ(static_cast<std::uint8_t>(cppcff::OffSize::k1), 1);
	ASSERT_EQ(static_cast<std::uint8_t>(cppcff::OffSize::k2), 2);
	ASSERT_EQ(static_cast<std::uint8_t>(cppcff::OffSize::k3), 3);
	ASSERT_EQ(static_cast<std::uint8_t>(cppcff::OffSize::k4), 4);
}

TEST(cppcff_typedefs, Offset)
{
	ASSERT_EQ(sizeof(cppcff::Offset<cppcff::OffSize::k1>), 1);
	ASSERT_EQ(sizeof(cppcff::Offset<cppcff::OffSize::k2>), 2);
	ASSERT_EQ(sizeof(cppcff::Offset<cppcff::OffSize::k3>), 3);
	ASSERT_EQ(sizeof(cppcff::Offset<cppcff::OffSize::k4>), 4);
	
	cppcff::Offset<cppcff::OffSize::k1> offset1;
	ASSERT_EQ(sizeof(offset1), 1);
	ASSERT_EQ(static_cast<void*>(&offset1), static_cast<void*>(&offset1.value_));
	ASSERT_EQ(static_cast<void*>(&offset1.value_), static_cast<void*>(&offset1.value_.byte1_));
	
	cppcff::Offset<cppcff::OffSize::k2> offset2;
	ASSERT_EQ(sizeof(offset2), 2);
	ASSERT_EQ(static_cast<void*>(&offset2), static_cast<void*>(&offset2.value_));
	ASSERT_EQ(static_cast<void*>(&offset2.value_), static_cast<void*>(&offset2.value_.byte2_));
	ASSERT_TRUE(&offset2.value_.byte2_ < &offset2.value_.byte1_);
	
	cppcff::Offset<cppcff::OffSize::k3> offset3;
	ASSERT_EQ(sizeof(offset3), 3);
	ASSERT_EQ(static_cast<void*>(&offset3), static_cast<void*>(&offset3.value_));
	ASSERT_EQ(static_cast<void*>(&offset3.value_), static_cast<void*>(&offset3.value_.byte3_));
	ASSERT_TRUE(&offset3.value_.byte3_ < &offset3.value_.byte2_);
	ASSERT_TRUE(&offset3.value_.byte2_ < &offset3.value_.byte1_);
	ASSERT_TRUE(&offset3.value_.byte3_ < &offset3.value_.byte1_);
	
	cppcff::Offset<cppcff::OffSize::k4> offset4;
	ASSERT_EQ(sizeof(offset4), 4);
	ASSERT_EQ(static_cast<void*>(&offset4), static_cast<void*>(&offset4.value_));
	ASSERT_EQ(static_cast<void*>(&offset4.value_), static_cast<void*>(&offset4.value_.byte4_));
	ASSERT_TRUE(&offset4.value_.byte4_ < &offset4.value_.byte3_);
	ASSERT_TRUE(&offset4.value_.byte4_ < &offset4.value_.byte2_);
	ASSERT_TRUE(&offset4.value_.byte4_ < &offset4.value_.byte1_);
	ASSERT_TRUE(&offset4.value_.byte3_ < &offset4.value_.byte2_);
	ASSERT_TRUE(&offset4.value_.byte3_ < &offset4.value_.byte1_);
	ASSERT_TRUE(&offset4.value_.byte2_ < &offset4.value_.byte1_);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}