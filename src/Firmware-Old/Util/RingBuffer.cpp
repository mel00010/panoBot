/*******************************************************************************
 * RingBuffer.cpp
 * Copyright (C) 2018  Mel McCalla <melmccalla@gmail.com>
 *
 * This file is part of panoBot.
 *
 * panoBot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * panoBot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with panoBot.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

#include "../../Firmware-Old/Util/RingBuffer.hpp"

#include <stdlib.h>

RingBuffer::RingBuffer(size_t size) : size(size), head(0), tail(0) {
	memory = static_cast<uint8_t*>(malloc(size)); // Only using malloc because of AVR weirdness
}

RingBuffer::~RingBuffer() {
	free(memory);
}
bool RingBuffer::empty() {
	return head == tail;
}
bool RingBuffer::full() {
	return ((head + 1) % size) == tail;
}
void RingBuffer::reset() {
	head=0;
	tail=0;
}
void RingBuffer::push_back(uint8_t data) {

	memory[head] = data;
	head = (head + 1) % size;

	if(head == tail)
	{
		tail = (tail + 1) % size;
	}
}
uint8_t RingBuffer::pop_front() {
	if(!empty()){
		tail = (tail + 1) % size;
		return memory[tail];
	}
	return 0;
}

extern "C" {
	bool RingBuffer_empty(RingBuffer* buffer) {
		return buffer->empty();
	}
	bool RingBuffer_full(RingBuffer* buffer) {
		return buffer->full();
	}
	void RingBuffer_reset(RingBuffer* buffer) {
		buffer->reset();
	}
	void RingBuffer_push_back(RingBuffer* buffer, uint8_t data) {
		buffer->push_back(data);
	}
	uint8_t RingBuffer_pop_front(RingBuffer* buffer) {
		return buffer->pop_front();
	}
}
