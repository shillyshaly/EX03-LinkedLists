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
            //allocate memory for new node
            node* newNode = new node(val, nullptr, nullptr);
            //check for empty list
            if(_head == nullptr){
                _head = _tail = newNode;
                _size++;
                return;
            }
            insert(begin(), val);                   //insert from front
        }

        void pop_front() {
            //if empty, return if true
            if(_head == nullptr){
                return;
            }
            //if single node, del node, H/T to null
            if(_size == 1){
                delete _head;
                _head = nullptr;
                _tail = nullptr;
                _size = 0;
                return;
            }
            //copy head to node
            node* oldNode = _head;

            //if head != null
            if(_head != nullptr){
                //set H to copy.next, del copy
                _head = oldNode->_next;
                delete oldNode;
            }
            _size--;
        }

        void push_back(const Ty& val) {
            //allocate memory for new node
            node* newNode = new node(val, nullptr, nullptr);

            //check for empty list
            if(_head == nullptr){
                _head = _tail = newNode;
                _size++;
                return;
            }
            insert(end(), val);                     //insert from end
        }

        void pop_back() {
            //if empty, return if true
            if(_head == nullptr){
                return;
            }
            //if single node, del node, H/T to null
            if(_size == 1){
                delete _head;
                _head = nullptr;
                _tail = nullptr;
                _size = 0;
                return;
            }
            //if H/T != null
            if(_head != nullptr){
                if(_tail != nullptr){
                    //make copy of node before tail, tail to null, tail = copy
                    node* oldNode = _tail->_prev;
                    oldNode->_next = nullptr;
                    delete _tail;
                    _tail = oldNode;
                }
            }
            _size--;
        }

        iterator insert(iterator it, const Ty &val) {
            //allocate memory for new node.  adds value, and points next/prev to null
            node* newNode = new node(val);

            //if empty, insert new node, newNode next/prev to null, head/tail to newNode
            if(_head == nullptr){
                newNode->_next = nullptr;
                newNode->_prev = nullptr;
                _head = newNode;
                _tail = newNode;
                it._current = newNode;
                _size++;
                return it;
            } else                                      //insert at head if list is not empty
            if(it._current == _head){
                newNode->_next = _head;
                newNode->_prev = nullptr;
                it._current = newNode;
                _head = newNode;
                it._current->_next->_prev = newNode;
                _size++;
                return it;
            } else                                      //insert at tail if list is not empty
            if(it._current == nullptr){
                newNode->_prev = _tail;
                newNode->_next = nullptr;
                _tail->_next = newNode;
                _tail = newNode;
                it._current = newNode;
                _size++;
                return it;
            }
            else{                                       //general list insert
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
            //copy it.current node as old node
            node* oldNode = it._current;

            //check for empty list
            if(it._current == nullptr){                 //if empty set oldNode to null
                oldNode = nullptr;
            }else{                                      //else set oldNode to next node
                oldNode = it._current->_next;
            }

            //when list is not empty, set it.next to
            if(it._current != nullptr){
                it._current->_next = oldNode->_next;
                delete oldNode;
            }
            _size--;
            return it;
        }
        //erase from it.current to end using for loop
        iterator erase(iterator first, iterator last) {
            for(auto i = first; i != last; i++){
                erase(i);
                return first;
            }
        }

        void clear() {
            erase(begin(), end());
            delete _head;
            delete _tail;
            _head = nullptr;
            _tail = nullptr;
            _size = 0;
        }
    };

}}}}
#endif //EX03_LINKEDLIST_LIST_H
