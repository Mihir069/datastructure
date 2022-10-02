#include<iostream>
using namespace std;

template<class t>
class Node{
    public:
        t elem;
        Node *prev;
        Node *next;
};

template<class t>
class List{
    public :
    List<t>();

    bool empty();
    void addFirst();
    void addIthh();
    void addEnd();
    void removeFirst();
    void removeIth();
    void removeLast();
    void SearchElem();
    void concatenate();
    void display();

    void SecondListData();
    bool SecondEmpty();
    void addSecondFirst();
    void addSecondIth();

    void displaySecond();

private:
    Node<t> *header;
    Node<t> *tailer;
    Node<t> *header2;
    Node<t> *tailer2;
};


template<class t>
List<t>::List(){
    header = new Node<t>;
    tailer = new Node<t>;
    header->next = tailer;
    tailer->prev = header;
    header2 = new Node<t>;
    tailer2 = new Node<t>;
    header->next = tailer2;
    tailer->prev = header2;
}

template<class t>
bool List<t>::SecondEmpty(){
    if (header2->next == tailer2){
        return true;
    }
    else{
        return false;
    }
}

template<class t>
void List<t>::displaySecond(){
    if (SecondEmpty() != true){
        cout<<"Element in the list are :- "<<endl;
        Node<t> *p = new Node<t>;
        p = header2->next;
        while(p != tailer2){
            cout<<p->elem<<" ";
            p = p->next;
        }
    }
    else{
        cout<<"List is empty !"<<endl;
    }
    cout<<endl;
}

template<class t>
void List<t>::addSecondFirst(){
    cout<<"Enter the value in the node: "<<endl;
    t ele;
    cin>>ele;

    if (SecondEmpty() == true){
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = tailer2;
        n->prev = tailer2->prev;
        tailer2->prev = n;
        header2->next = n;
    }
    else{
        Node<t> *n = new Node<t>;
        n->next = header2->next;
        header2->next->prev = n;
        n->prev = header2;
        n->elem = ele;
        header2->next = n;
    }
}

template<class t>
void List<t>::addSecondIth(){
    displaySecond();
    int i;
    int count = 0;
    t ele;
    cout<<"Enter the position to add the element: "<<endl;
    cin>>i;
    cout<<"Enter the element: "<<endl;
    cin>>ele;
    Node<t> *p = new Node<t>;
    Node<t> *n = new Node<t>;
    p = header2->next;
    while(p != tailer2) {
        if (count == i - 1){
            p->prev->next;
            n->next = p;
            n->elem = ele;
            n->prev = p->prev;
            p->prev = n;
        }
        p = p->next;
        count++;
    }
}

template<class t>
bool List<t>::empty(){
    if (header->next == tailer){
        return true;
    }
    else{
        return false;
    }
}

template<class t>
void List<t>::addFirst(){
    cout<<"Enter the value in the node: "<<endl;
    t ele;
    cin>>ele;

    if (empty() == true){
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = tailer;
        n->prev = tailer->prev;
        tailer->prev = n;
        header->next;
    }
    else{
        Node<t> *n = new Node<t>;

        n->next = header->next;
        header->next->prev = n;
        n->prev = header;
        n->elem = ele;
        header->next = n;
    }
}

template<class t>
void List<t>::addIthh(){
    display();
    int i;
    int count = 0;
    t ele;
    cout<<"Enter the position to the add the element to: "<<endl;
    cin>>i;
    cout<<"Enter the element: "<<endl;
    cin>>ele;
    Node<t> *p = new Node<t>;
    Node<t> *n = new Node<t>;
    p = header->next;
    while(p != tailer) {
        if (count == i - 1){
            p->prev->next = n;
            n->next = p;
            n->elem = ele;
            n->prev = p->prev;
            p->prev = n;
        }
        p = p->next;
        count++;
    }
}

template<class t>
void List<t>::addEnd(){
    t ele;
    Node<t> *n = new Node<t>;
    cout<<"Enter the element: "<<endl;
    cin>>ele;
    if (empty() == true){
        cout<<"List is empty!"<<endl;
    }
    else{
        Node<t> *p = p->next;
        p = header->next;

        header->next = p->next;
        p->next->prev = header;
        cout<<"Element"<<p->elem<<"deleted."<<endl;
        delete p;
    }
}

template<class t>
void List<t>::removeIth(){
    display();
    if (empty()!=true){
        cout<<"Enter the position of the element you want to delete: "<<endl;
        int i;
        cin>>i;
        Node<t> *p = new Node<t>;
        p = header->next;
        int counter = 1;
        while ( p != tailer ){
            if (counter == i){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                cout<<"Element "<<p->elem<<"deleted."<<endl;
                delete p;
                break;
            }
            counter++;
            p = p->next;
        }
    }
}

template<class t>
void List<t>::removeLast(){
    if (empty() == true){
        cout<<"List is empty "<<endl;
    }
    else{
        Node<t> *p = new Node<t>;
        p = tailer->prev;
        p->prev->next = tailer;
        tailer->prev = p->prev;
        cout<<"Element: "<<p->elem<<"deleted."<<endl;
        delete p;
    }
}

template<class t>
void List<t>::SearchElem(){
    t x;
    bool flag = false;
    int counter = 1;
    cout<<"Enter element to be searched: "<<endl;
    cin>>x;
    Node<t> *p = new Node<t>;

    p = header->next;
    while (p != tailer){
        if (p->elem == x){
            cout<<"Element is found at the position "<< counter<<endl;
            cout<<"It's pointer is "<< p->prev<<endl;
            flag = true;
            break;
        }

        counter++;
        p = p->next;
    }
    if (flag == false){
        cout<<"Element is not found in the list: "<<endl;
    }
}

template<class t>
void List<t>::SecondListData(){
    int choice;
    char repeat;
    do{
        cout<<"Enter 1: To add at the first of the second list. "<<endl;
        cout<<"Enter 2: To add at the ith position of the second list. "<<endl;
        cout<<"Enter 3: To add at the last of the second list. "<<endl;
        cin>>choice;

        switch (choice){
            case 1:
                addSecondFirst();
            case 2:
                addSecondIth();
            case 3:
                displaySecond();
            default:
                cout<<"Invalid Choice."<<endl;
                break;
        }
        cout<<"Want to repeat in the second list? Y / N"<<endl;
        cin>>repeat;
        cout<<"******"<<endl;
    }
    while(repeat == 'y' || repeat == 'Y');
}

template<class t>
void List<t>::concatenate(){
    cout<<"Elements in both list are: "<<endl;
    Node<t> *p = new Node<t>;
    p = header->next;
    while(p != tailer2){
        cout<<p->elem<<"->";
        p = p->next;
        if (p->next == tailer){
            p->next = header2->next;
        }
    }
}


template<class t>
void List<t>:: display(){
    if (empty() != true){
        cout<<"Element in the list are : "<<endl;
        Node<t> *p = new Node<t>;
        p = header->next;
        while (p != tailer){
            cout<<p->elem<<"->";
            p = p->next;
        }
    }
    else{
            cout<<"List is empty ."<<endl;
        }
        cout<<endl;
    }

template<class t>
void List<t>::removeFirst(){
    if (empty()==true){
        cout<<"List is empty "<<endl;
    }
    else{
        Node<t> *p = new Node<t>;
        p = header->next;
        header->next = p->next;
        p->next->prev = header;
        cout<<"Element "<< p->elem<<"Deleted."<<endl;
        delete p;
    }
}


int main(){
    List<int> l;
    char choice;
    int enter;
    do{
        cout<<"Enter 1: To add at the first pos."<<endl;
        cout<<"Enter 2: To add at the Ith pos."<<endl;
        cout<<"Enter 3: To display."<<endl;
        cout<<"Enter 4: To add at the last pos."<<endl;
        cout<<"Enter 5: To delete from the first pos."<<endl;
        cout<<"Enter 6: To delete from the Ith pos."<<endl;
        cout<<"Enter 7: To delete from the last pos."<<endl;
        cout<<"Enter 8: To search an element in the list."<<endl;
        cout<<"Enter 9: To add data in the second list."<<endl;
        cout<<"Enter 10: To concatenate both list and print the elements."<<endl;
        cout<<"================================================"<<endl;
        cin>>enter;
        switch (enter)
        {
        case 1:
            l.addFirst();
            break;
        
        case 2:
            l.addIthh();
            break;

        case 3:
            l.display();
            break;
        
        case 4:
            l.addEnd();
            break;
        case 5:
            l.removeFirst();
            break;

        case 6:
            l.removeIth();
            break;

        case 7:
            l.removeLast();
            break;
        
        case 8:
            l.SearchElem();
            break;
        
        case 9:
            l.SecondListData();
            break;
        
        case 10:
            l.concatenate();
            break;
        
        default:
            cout<<"Invalid choice"<<endl;
            break;        
        }
        cout<<"\n Do you want to repeat in first list ? Y / N : "<<endl;
        cin>>choice;
    }
    while (choice == 'y' || choice == 'Y');
    return 0;
}