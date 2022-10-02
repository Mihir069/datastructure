#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T val;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class DoublyLinkedList {
public:
    Node<T> *head;
    Node<T> *tail;
    
    DoublyLinkedList() {
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->prev = head;
    }

    bool empty() { return head->next == tail; }
    T front() { return head->next->val; }
    T back() { return tail->prev->val; }

    void add(Node<T> *node, T val) {
        Node<T> *new_node = new Node<T>;
        new_node->val = val;
        
        new_node->next = node;
        new_node->prev = node->prev;
        
        node->prev->next = new_node;
        node->prev = new_node;
    }

    void remove(Node<T> *node) {
        Node<T> *a = node->prev;
        Node<T> *b = node->next;

        a->next = b;
        b->prev = a;
        delete node;
    }

    void addFront(T val) { add(head->next, val); }
    void addBack(T val) { add(tail, val); }
    
    void removeFront() { remove(head->next); }
    void removeBack() { remove(tail->prev); }

    void addAtIndex(int idx, T val) {
        if (idx == 0) { addFront(val); return; }
        if (idx == -1) { addBack(val); return; }

        Node<T> *cur = head;
        while (idx--) cur = cur->next;
        add(cur->next, val);
    }

    void removeAtIndex(int idx) {
        if (empty()) return;
        if (idx == 0) { removeFront(); return; }
        if (idx == -1) { removeBack(); return; }
        
        Node<T> *cur = head;
        while (idx--) cur = cur->next;
        remove(cur->next);
    }

    void print() {
        cout << "NULL <-> ";
        Node<T> *cur = head;
        while (cur->next != tail) {
            cur = cur->next;
            cout << cur->val << " <-> ";
        }
        cout << "NULL" << endl;
    }

    Node<T>* search(int val) {
        if (empty()) return NULL;
        Node<T> *cur = head;
        
        while (cur->next != tail) {
            cur = cur->next;
            if (cur->val == val) return cur;
        }
        return NULL;
    }

    void concat(DoublyLinkedList l) {
        tail->prev->next = l.head->next;
        tail = l.tail;
    }
};