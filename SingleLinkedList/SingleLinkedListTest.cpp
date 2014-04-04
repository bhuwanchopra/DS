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
		EXPECT_EQ(vector<int>({1}), list.traversal());
	}
	{
		SingleLinkedList<int> list(1);
		list.insert(2);
		EXPECT_EQ(vector<int>({2,1}), list.traversal());
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
