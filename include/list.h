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
            node* newNode = new node(val, nullptr, nullptr);        //allocate memory for new node
            if(_head == nullptr){            //Check empty, points head/tail to new node if true
                _head = newNode;
                _tail = newNode;
            }else{
                newNode->_next = _head;      //else add to front of list
                newNode->_prev = nullptr;
                _head = newNode;
            }
            _size++;
        }

        void pop_front() {
            if(_size = 0){
                return;
            }
            if(_size = 1){
                delete _head;
                _head = nullptr;
                _tail = nullptr;
                _size = 0;
                return;
            }
            node* _old = _head;
            if(_old != nullptr){
                _head = _old->_next;
                delete _old;
            }
            _size--;
        }

        void push_back(const Ty& val) {
            node* newNode = new node(val, nullptr, nullptr);
            if(_tail == nullptr){
                _head = newNode;
                _tail = newNode;
            }else{
                newNode->_prev = _tail;
                newNode->_next = nullptr;
                _tail = newNode;
            }
        }

        void pop_back() {
            // put your code here
        }

        iterator insert(iterator it, const Ty &val) {
            it._current = new node(val, it._current->_next, it._current->_prev);
            if(it._current == _tail){
                _tail = it._current;
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
