#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

#include "BitVector.h"

void BitVector::set(size_t element_position) {
	container_[element_position>>SHIFT] |= (1 << (MASK & element_position));
}

void BitVector::clear(size_t element_position) {
	container_[element_position>>SHIFT] &= ~(1 << (MASK & element_position));
}

uint32_t BitVector::get(size_t element_position) {
	return container_[element_position>>SHIFT] & (1 << (MASK & element_position));
}
