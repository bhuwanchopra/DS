/*
 * SingleLinkedListTest.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: bhuwan
 */
#include "SingleLinkedList.h"
#include "gtest/gtest.h"

TEST(SingleLinkedListTraversal, Traversal) {
	{
		SingleLinkedList<int> list(1);
		vector<int> e = {1};
		vector<int> f = list.traversal();
		EXPECT_EQ(f, e);
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
