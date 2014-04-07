/*
 * SingleLinkedList.h
 *
 *  Created on: Mar 28, 2014
 *      Author: bhuwan
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include <cstddef>
#include <vector>

using std::vector;

template<class DataType>
class SingleLinkedListNode {
	SingleLinkedListNode* next_;
	DataType data_;
public:
	inline DataType getData() {
		return data_;
	}
	inline SingleLinkedListNode* getNext() {
		return next_;
	}
	explicit SingleLinkedListNode(DataType value) :
			SingleLinkedListNode(nullptr, value) {
	}
	SingleLinkedListNode(SingleLinkedListNode* head, DataType value) :
			next_(head), data_(value) {}
};

template<class DataType>
class SingleLinkedList {
public:
	SingleLinkedListNode<DataType>* head_;

	explicit SingleLinkedList(DataType value);

	void insert(DataType value);

	vector<DataType> traversal();

	~SingleLinkedList();
};

template<class DataType>
SingleLinkedList<DataType>::SingleLinkedList(DataType value) {
	head_ = new SingleLinkedListNode<DataType>(value);
}

template<class DataType>
void SingleLinkedList<DataType>::insert(DataType value) {
	head_ = new SingleLinkedListNode<DataType>(head_, value);
}

template<class DataType>
vector<DataType> SingleLinkedList<DataType>::traversal() {
	if (nullptr == head_) {
		return vector<DataType>();
	}
	vector<DataType> ret;

	for(auto n = head_; nullptr != n; n = n->getNext()) {
		ret.emplace_back(n->getData());
	}
	return ret;
}

template<class DataType>
SingleLinkedList<DataType>::~SingleLinkedList() {
	for(auto p = head_; nullptr != p;) {
		auto nextp = p->getNext();
		delete p;
		p = nextp;
	}
}

#endif /* SINGLELINKEDLIST_H_ */
