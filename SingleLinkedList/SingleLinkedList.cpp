/*
 * SingleLinkedListTraversal.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: bhuwan
 */

#include "SingleLinkedList.h"

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
