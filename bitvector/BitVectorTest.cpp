/*
 * BitVectorTest.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: bhuwan
 */

#include "BitVector.h"
#include "gtest/gtest.h"

TEST(BitVectorTest, Setters) {
	{
		const size_t size = 128;
		BitVector bv(size);

		for(size_t i = 0 ; i < size ; ++i) {
			EXPECT_FALSE(bv.get(i));
		}

		bv.set(0);
		EXPECT_TRUE(bv.get(0));

		bv.set(31);
		EXPECT_TRUE(bv.get(31));

		bv.set(32);
		EXPECT_TRUE(bv.get(32));

		bv.set(100);
		EXPECT_TRUE(bv.get(100));

		bv.set(127);
		EXPECT_TRUE(bv.get(127));
	}

	{
		const size_t size = 1280000;
		BitVector bv(size);

		for(size_t i = 0 ; i < size ; ++i) {
			bv.set(i);
		}

		for(size_t i = 0 ; i < size ; ++i) {
			EXPECT_TRUE(bv.get(i));
		}
	}
}

TEST(BitVectorTest, Clearer) {
	{
		const size_t size = 128;
		BitVector bv(size);

		for(size_t i = 0 ; i < size ; ++i) {
			bv.set(i);
		}

		bv.clear(0);
		EXPECT_FALSE(bv.get(0));

		bv.clear(31);
		EXPECT_FALSE(bv.get(31));

		bv.clear(32);
		EXPECT_FALSE(bv.get(32));

		bv.clear(100);
		EXPECT_FALSE(bv.get(100));

		bv.clear(127);
		EXPECT_FALSE(bv.get(127));
	}

	{
		const size_t size = 1280000;
		BitVector bv(size);

		for(size_t i = 0 ; i < size ; ++i) {
			bv.set(i);
		}

		for(size_t i = 0 ; i < size ; ++i) {
			bv.clear(i);
			EXPECT_FALSE(bv.get(i));
		}
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
