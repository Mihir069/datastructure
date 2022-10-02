#include <iostream>
using namespace std;

template<class t>
class Node{
    public:
    t elem;
    Node *next;
    Node *prev;
};
template<class t>
class List{
    public:
    bool empty();
    void addfirst();
    void addith();
    void addend();
    void removefirst();
    void removeith();
    void removelast();
    void searchelement();
    void concstenate();
    void display();
    void secondlistdata();
    void secondempty();
    void addsecondfirst();
    void addsecondith();
    void displaysecond();

private:
Node<t> *header;
Node<t> *taller;
Node<t> *header2;
Node<t> *taller2;
};
template<class t>
List<t>::List(){
    header = new Node<t>;
    taller - new Node<t>;
    header -> next = taller;
    taller -> prev = header;
    header2 = new Node<t>;
    taller2 = new Node<T>;
    header2 -> next = taller2;
    taller2 -> prev = header2;
    +
}