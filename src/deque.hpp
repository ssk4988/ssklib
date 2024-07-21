#pragma once
#include <vector>

#define SCALING_FACTOR 2

/*
* Deque
* Iterators may get invalidated on insertion and deletion from front and back
*/

namespace ssk {
    template<typename T>
    class deque
    {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = std::size_t;
    private:
        std::vector<value_type> buffer;

        size_type beginIndex = 0; // index to first element in deque
        size_type endIndex = 0; // index beyond last element in deque
        size_type size = 0; // number of elements currently in deque

        void rescale() {
            std::vector<value_type> newBuffer(buffer.size() * SCALING_FACTOR + 1);
            size_type index = beginIndex;
            for(size_type newIndex = 0; newIndex < size; newIndex++) {
                newBuffer[newIndex] = std::move(buffer[index]);
                index++;
                if (index == buffer.size()) {
                    index = 0;
                }
            }
            std::swap(newBuffer, buffer);
            beginIndex = 0;
            endIndex = size;
        }
    public:
        reference front() {
            return buffer[beginIndex];
        }

        reference back() {
            return endIndex == 0 ? buffer.back() : buffer[endIndex - 1];
        }

        void push_back(const_reference x) {
            if (size == buffer.size()) rescale();
            buffer[endIndex++] = x;
            if (endIndex == buffer.size()) endIndex = 0;
            size++;
        }

        void push_back(T&& x) {
            if (size == buffer.size()) rescale();
            buffer[endIndex++] = x;
            if (endIndex == buffer.size()) endIndex = 0;
            size++;
        }

        void push_front(const_reference x) {
            if (size == buffer.size()) rescale();
            if (beginIndex == 0) beginIndex = buffer.size();
            buffer[--beginIndex] = x;
            size++;
        }

        void push_front(T&& x) {
            if (size == buffer.size()) rescale();
            if (beginIndex == 0) beginIndex = buffer.size();
            buffer[--beginIndex] = x;
            size++;
        }

        reference operator[](size_type index) {
            return buffer[beginIndex + index - buffer.size() * (beginIndex + index >= buffer.size())];
        }

        const_reference operator[](size_type index) const {
            return buffer[beginIndex + index - buffer.size() * (beginIndex + index >= buffer.size())];
        }
    };
}
