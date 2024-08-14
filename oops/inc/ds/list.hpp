/*
 * Created on 14-08-2024 by Ashif Zaman
 *
 * This file is part of zlib which is written as part of a university course and
 * is itself, free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.

 *    The following code is distributed in the hope that it will be useful, but
 WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 A
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.

 *    You should have received a copy of the GNU General Public License along
 with
 * Foobar. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ZL_DS_LIST_HPP
#define ZL_DS_LIST_HPP

#include <cstddef>
#include <cstdlib>
#include <functional>
#include <new>
#include <stdexcept>

#include "util/result.hpp"

using std::size_t;

namespace zl::ds {

constexpr size_t MIN_ALLOC = 6;

template <typename T>
class List {
   private:
    T* _data;
    size_t _len;
    size_t _cap;

   public:
    List() : _len(0), _cap(MIN_ALLOC) { _data = new T[MIN_ALLOC]; }
    List(const List& other) : _len(other._len), _cap(other._cap) {
        _data = new T[_cap];
        for (size_t i = 0; i < _len; i++) _data[i] = other[i++];
    }
    List(List&& other)
        : _len(other._len), _cap(other._cap), _data(other._data) {
        other = {0};
    }
    ~List() noexcept {
        delete[] _data;
        _len = _cap = 0;
        _data = 0;
    }

    List operator=(const List& rhs) {
        _cap = rhs._cap;
        _len = rhs._len;
        if (_data) delete[] _data;
        _data = new T[_cap];
        for (size_t i = 0; i < _len; i++) _data[i] = rhs[i++];
        return this;
    }
    List operator=(List&& rhs) {
        _cap = rhs._cap;
        _len = rhs._len;
        _data = rhs._data;
        rhs = {0};
        return this;
    }

    Result<Unit, std::out_of_range> insert(T x, size_t p) {
        if (p > _len)
            return std::out_of_range(
                "cannot insert element beyond the end of the list");
        // if the length reaches the total list capacity, we reallocate the list
        // with 2 times its previous capacity to fit newer entries
        if (_len == _cap) {
            _cap = 2 * _cap;
            _data = (T*)realloc(_data, sizeof(T) * _cap);
            // we throw an exception here instead of returning an Err because
            // running out of memory is, in most cases, a fatal error,
            // recovering from which is neither possible nor desirable since it
            // might just be a symptom of a much larger underlying problem.
            if (_data == nullptr) throw new std::bad_alloc();
        }
        for (size_t i = _len; i > p; i--) _data[i] = _data[i - 1];
        _data[p] = x;
        _len++;
        return Unit();
    }

    size_t len() { return _len; }

    Option<T> first() const {
        if (_len)
            return _data[0];
        else
            return None{};
    }
    Option<T> last() const {
        if (_len)
            return _data[_len - 1];
        else
            return None{};
    }

    Option<T> retrieve(size_t pos) const {
        if (_len > pos)
            return _data[pos];
        else
            return None{};
    }

    Option<size_t> locate(const T& x) const {
        // the list may not be sorted, so we must use brute force search :(
        size_t i = 0;
        for (i = 0; i < _len && _data[i] != x; ++i)
            ;
        if (i == _len)
            return None{};
        else
            return i;
    }

    void remove(size_t position) {
        if (position < _len) {
            // shift all elements after L_p to the left by 1
            for (size_t i = position; i < _len - 1; i++)
                _data[i] = _data[i + 1];
            _len--;
        }
    }

    void clear() {
        delete[] _data;
        _data = (T*)malloc(sizeof(T) * MIN_ALLOC);
        _len = 0;
        _cap = MIN_ALLOC;
    }

    Option<size_t> next(size_t position) {
        if (position >= _len)
            return None{};
        else
            return position + 1;
    }

    Option<size_t> previous(size_t position) {
        if (position == 0)
            return None{};
        else
            return position - 1;
    }

    // Since we don't want to limit ourselves by defining the exact details of
    // the printer function for individual elements (which might depend directly
    // on the type properties of T), we accept a pointer to a function defined
    // elsewhere instead, which is actually responsible for printing individual
    // elements.
    void print_list(void (*print)(const T&)) {
        for (size_t i = 0; i < _len; i++) print(_data[i]);
    }
};
}  // namespace zl::ds

#endif
