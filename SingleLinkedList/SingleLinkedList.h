/*
 * SingleLinkedList.h
 *
 *  Created on: Mar 28, 2014
 *      Author: bhuwan
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include <cstddef>
#include <cassert>
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

template<class DataType>
class SingleLinkedListNode {
	shared_ptr<SingleLinkedListNode<DataType>> next_;
	DataType data_;
public:
	inline DataType getData() {
		return data_;
	}
	inline shared_ptr<SingleLinkedListNode<DataType>> getNext() {
		return next_;
	}
	inline void setNext(shared_ptr<SingleLinkedListNode<DataType>> ptr) {
		next_ = ptr;
	}
	explicit SingleLinkedListNode(DataType value) :
		next_(nullptr), data_(value) {}

	SingleLinkedListNode(shared_ptr<SingleLinkedListNode<DataType>> head, 
		DataType value) :
			next_(head), data_(value) {}
};

template<class DataType>
class SingleLinkedList {
public:
	shared_ptr<SingleLinkedListNode<DataType>> head_;

	SingleLinkedList(DataType value);

	SingleLinkedList();

	void insert(DataType value);

	bool remove(DataType value);

	shared_ptr<SingleLinkedListNode<DataType>> find(DataType value);

	vector<DataType> traversal();

	~SingleLinkedList();
};

template<class DataType>
SingleLinkedList<DataType>::SingleLinkedList(DataType value) :
	head_(new SingleLinkedListNode<DataType>(value)) {}

template<class DataType>
SingleLinkedList<DataType>::SingleLinkedList() :
	head_(nullptr) {}

template<class DataType>
void SingleLinkedList<DataType>::insert(DataType value) {
	head_.reset(new SingleLinkedListNode<DataType>(head_, value));
}

template<class DataType>
bool SingleLinkedList<DataType>::remove(DataType value) {
	shared_ptr<SingleLinkedListNode<DataType>> node_to_delete = find(value);
	if (nullptr == node_to_delete) {
		return false;
	}

	if (node_to_delete == head_) {
		head_ = head_->getNext();
		return true;
	}

	shared_ptr<SingleLinkedListNode<DataType>> prev_ptr;
	for (prev_ptr = head_;
		 nullptr != prev_ptr->getNext() && node_to_delete != prev_ptr->getNext();
		 prev_ptr = prev_ptr->getNext())
		;

	if (nullptr == prev_ptr->getNext()) {
		return false;
	} else {
		prev_ptr->setNext(prev_ptr->getNext()->getNext());
		return true;
	}
	assert(0);
}

template<class DataType>
shared_ptr<SingleLinkedListNode<DataType>> SingleLinkedList<DataType>::find(
		DataType value) {
	shared_ptr<SingleLinkedListNode<DataType>> p;
	for (p = head_;
		 nullptr != p && p->getData() != value;
		 p = p->getNext())
		;
	return p;
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
		p = nextp;
	}
}

#endif /* SINGLELINKEDLIST_H_ */
