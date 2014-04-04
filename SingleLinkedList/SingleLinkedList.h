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
	SingleLinkedListNode* next;
	DataType data;
public:
	inline DataType getData() {
		return data;
	}
	inline SingleLinkedListNode* getNext() {
		return next;
	}
	explicit SingleLinkedListNode(DataType value) :
			SingleLinkedListNode(nullptr, value) {
	}
	SingleLinkedListNode(SingleLinkedListNode* head, DataType value) :
			next(head), data(value) {}
};

template<class DataType>
class SingleLinkedList {
public:
	SingleLinkedListNode<DataType>* head;

	explicit SingleLinkedList(DataType value);

	void insert(DataType value);

	vector<DataType> traversal();

	~SingleLinkedList();
};

template<class DataType>
SingleLinkedList<DataType>::SingleLinkedList(DataType value) {
	head = new SingleLinkedListNode<DataType>(value);
}

template<class DataType>
void SingleLinkedList<DataType>::insert(DataType value) {
	head = new SingleLinkedListNode<DataType>(head, value);
}

template<class DataType>
vector<DataType> SingleLinkedList<DataType>::traversal() {
	if (nullptr == head) {
		return vector<DataType>();
	}
	vector<DataType> ret;

	for(auto n = head; nullptr != n; n = n->getNext()) {
		ret.emplace_back(n->getData());
	}
	return ret;
}

template<class DataType>
SingleLinkedList<DataType>::~SingleLinkedList() {
	for(auto p = head; nullptr != p;) {
		auto nextp = p->getNext();
		delete p;
		p = nextp;
	}
}

#endif /* SINGLELINKEDLIST_H_ */
