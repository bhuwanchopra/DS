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
	{
		SingleLinkedList<int> list(2);
		list.insert(1);
		list.insert(0);
		EXPECT_EQ(vector<int>({0,1,2}), list.traversal());
	}
	{
		SingleLinkedList<int> list(0);
		list.insert(0);
		list.insert(0);
		EXPECT_EQ(vector<int>({0,0,0}), list.traversal());
	}
	{
		struct Mystruct {
			int val_;
			Mystruct(int val) :
				val_ (val) {}
			bool operator==(const Mystruct& comp) const {
				return comp.val_ == val_;
			}
		};
		SingleLinkedList<Mystruct> list(Mystruct(1));
		EXPECT_EQ(vector<Mystruct>({Mystruct(1)}), list.traversal());
		list.insert(Mystruct(2));
		EXPECT_EQ(vector<Mystruct>({Mystruct(2),Mystruct(1)}), list.traversal());
		list.insert(Mystruct(3));
		EXPECT_EQ(vector<Mystruct>({Mystruct(3),Mystruct(2),Mystruct(1)}),
				list.traversal());
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
