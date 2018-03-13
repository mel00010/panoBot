/*******************************************************************************
 * RingBuffer.hpp
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
#ifndef SRC_FIRMWARE_UTIL_RINGBUFFER_HPP_
#define SRC_FIRMWARE_UTIL_RINGBUFFER_HPP_

#include <stddef.h>
#include <stdint.h>

class RingBuffer {
	public:
		RingBuffer(size_t size);
		~RingBuffer();
	public:
		bool empty();
		bool full();
		void reset();
		void push_back(uint8_t data);
		uint8_t pop_front();
	private:
		uint8_t* memory = nullptr;
		size_t size;
		size_t head;
		size_t tail;
};
extern "C" {
	bool RingBuffer_empty(RingBuffer* buffer);
	bool RingBuffer_full(RingBuffer* buffer);
	void RingBuffer_reset(RingBuffer* buffer);
	void RingBuffer_push_back(RingBuffer* buffer, uint8_t data);
	uint8_t RingBuffer_pop_front(RingBuffer* buffer);
}



#endif /* SRC_FIRMWARE_UTIL_RINGBUFFER_HPP_ */
