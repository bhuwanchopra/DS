/*
 * BitVector.h
 *
 *  Created on: Mar 22, 2014
 *      Author: bhuwan
 */

#ifndef BITVECTOR_H_
#define BITVECTOR_H_

#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>

#define SHIFT 5   // This is the number of bits in word size(32)
#define MASK 0x1F // SHIFT bits all one.

class BitVector {
	size_t size_;
	std::vector<uint32_t> container_;
public:
	explicit BitVector(size_t size) :
		size_(size),
		container_(1 + (size>>SHIFT))
	{}
	void set(size_t element_position);
	void clear(size_t element_position);
	uint32_t get(size_t element_position);
};

#endif /* BITVECTOR_H_ */
