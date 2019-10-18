#ifndef EX03_LINKEDLIST_LIST_H
#define EX03_LINKEDLIST_LIST_H

#include <cstdlib>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    template<typename Ty>
    class list {
        struct node {
            node(const Ty &data): _data(data), _prev(nullptr), _next(nullptr) {}
            node(const Ty& data, node *prev, node* next): _data(data), _prev(prev), _next(next) {}
            Ty _data;
            node *_next;
            node *_prev;
        };

        node *_head = nullptr;
        node *_tail = nullptr;
        size_t _size;

    private:
        class iterator {
        public:
            node *_current;
        public:
            explicit iterator(node *link): _current(link) {}

            const Ty& operator *() { return _current->_data; }
            iterator& operator ++() { _current = _current->_next; return *this; }
            iterator operator ++(int) {
                node *old_current = _current;
                _current = _current->_next;
                return iterator(old_current);
            }
            iterator& operator --() { _current = _current->_prev; return *this; }
            iterator operator --(int) {
                node *old_current = _current;
                _current = _current->_prev;
                return iterator(old_current);
            }

            bool operator ==(const iterator &rhs) const {
                return _current == rhs._current;
            }

            bool operator !=(const iterator &rhs) const {
                return !(*this == rhs);
            }
        };

    public:
        explicit list(): _size(0) {}
        explicit list(size_t n): _size(0) { for (size_t i = 0; i < n; i++) push_back(Ty()); }
        list(size_t n, const Ty &val): _size(0) { for (size_t i = 0; i < n; i++) push_back(val); }
        list(const list &x) {}
        list(list &&x) noexcept: _head(x._head), _tail(x._tail), _size(x._size) {}

        iterator begin()  { return iterator(_head);   }
        iterator end()    { return iterator(nullptr); }

        bool empty() const { return size() == 0; }
        size_t size() const { return _size; }

        const Ty& front() const { return _head->_data; }
        const Ty& back()  const { return _tail->_data; }

        void push_front(const Ty& val) {

        }

        void pop_front() {

        }

        void push_back(const Ty& val) {

        }

        void pop_back() {

            
        }

        iterator insert(iterator it, const Ty &val) {
            node* newNode = new node(val);            //allocate memory for new node.  adds value, and points next/prev to null

            if(_head == nullptr){               //insert a new node if empty.
                newNode->_next = nullptr;
                newNode->_prev = nullptr;
                _head = newNode;
                _tail = newNode;
                it._current = newNode;
                _size++;
                return it;
            } else
            if(it._current == _head){           //insert at head if list is not empty
                newNode->_next = _head;
                newNode->_prev = nullptr;
                it._current = newNode;
                _head = newNode;
                it._current->_next->_prev = newNode;
                _size++;
                return it;
            } else
            if(it._current == nullptr){           //insert at tail if list is not empty
                newNode->_prev = _tail;
                newNode->_next = nullptr;
                _tail->_next = newNode;
                _tail = newNode;
                it._current = newNode;
                _size++;
                return it;
            }
            else{                              //insert in middle
                newNode->_prev = it._current->_prev;
                newNode->_next = it._current;
                it._current->_prev = newNode;
                newNode->_prev->_next = newNode;
                it._current = newNode;
                _size++;
                return it;
            }
        }

        iterator erase(iterator it) {
            // put your code here
        }

        iterator erase(iterator first, iterator last) {
            // put your code here
        }

        void clear() {
            // put your code here
        }
    };

}}}}
#endif //EX03_LINKEDLIST_LIST_H
