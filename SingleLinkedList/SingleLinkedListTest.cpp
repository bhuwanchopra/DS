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
		SingleLinkedList<int> list;
		list.insert(0);
		list.insert(0);
		EXPECT_EQ(vector<int>({0,0}), list.traversal());
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

TEST(SingleLinkedListFind, Find) {
	// Empty list case.
	{
		SingleLinkedList<int> list;
		EXPECT_EQ(nullptr, list.find(1));
		EXPECT_EQ(nullptr, list.find(0));
	}

	// Single element case.
	{
		SingleLinkedList<int> list(1);
		EXPECT_NE(nullptr, list.find(1));
		EXPECT_EQ(1, list.find(1)->getData());
		EXPECT_EQ(nullptr, list.find(0));
	}

	// Long list case.
	{
		SingleLinkedList<int> list(1);
		list.insert(2);
		list.insert(4);
		list.insert(3);
		list.insert(10);
		list.insert(50);
		list.insert(6);

		EXPECT_NE(nullptr, list.find(1));
		EXPECT_EQ(1, list.find(1)->getData());

		EXPECT_NE(nullptr, list.find(6));
		EXPECT_EQ(6, list.find(6)->getData());

		EXPECT_NE(nullptr, list.find(10));
		EXPECT_EQ(10, list.find(10)->getData());
	}
}

TEST(SingleLinkedListRemove, Remove) {
	// Empty list case.
	{
		SingleLinkedList<int> list;
		EXPECT_FALSE(list.remove(1));
		EXPECT_FALSE(list.remove(0));
	}

	// Single element case.
	{
		SingleLinkedList<int> list(1);
		EXPECT_TRUE(list.remove(1));
		EXPECT_EQ(vector<int>(), list.traversal());
	}

	// Long list case.
	{
		SingleLinkedList<int> list(1);
		list.insert(2);
		list.insert(4);
		list.insert(3);
		list.insert(10);
		list.insert(50);
		list.insert(6);

		EXPECT_TRUE(list.remove(1));
		EXPECT_EQ(vector<int>({6,50,10,3,4,2}), list.traversal());

		EXPECT_TRUE(list.remove(6));
		EXPECT_EQ(vector<int>({50,10,3,4,2}), list.traversal());

		EXPECT_TRUE(list.remove(3));
		EXPECT_EQ(vector<int>({50,10,4,2}), list.traversal());

		EXPECT_FALSE(list.remove(1));
	}
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
