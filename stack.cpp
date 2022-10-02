#include<iostream>
#include<exception>
using namespace std;
template<class T>
class Queue{
    int capacity;
    int front;
    int back;
    T *queue;
public:
    Queue<T>(){
        front=back=-1;
        cout<<"Enter capacity of queue: ";
        cin>>capacity;
        queue=new T[capacity];
    }
    ~Queue(){
        delete queue;
        front=back=-1;
        capacity=0;
    }
    bool isEmpty();
    bool isFull();
    void enqueue();
    void dequeue();
    void peek();
    void printQueue();
};
template<class T>
bool Queue<T>::isEmpty(){
    return (front == -1);
}
template<class T>
bool Queue<T>::isFull(){
    return ((front == 0) && (back == capacity - 1));
}
template<class T>
void Queue<T>::enqueue(){

        if(isFull()){
            cout<<"Queue is full!"<<endl;
        }
        T data;
        cout<<"Enter data: ";
        cin>>data;
        if(isEmpty()){
            front=back=0;
        }
        else if(back==capacity-1){
            for(int i=front;i<=back;i++){
                queue[i-front]=queue[i];
            }
            back=back-front+1;
            front=0;
        }
        else{
            back++;
        }
        queue[back]=data;
    

}
template<class T>
void Queue<T>::dequeue(){
  
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
        }
        T temp;
        temp=queue[front];
        if(front==back){
            front=back=-1;
        }
        else{
            front++;
        }
        cout<<"Element removed: "<<temp<<endl;
    }
  

template<class T>
void Queue<T>::peek(){
  
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
        }
        cout<<"The first element is: ";
        cout<<queue[front]<<endl;
    }
 

template<class T>
void Queue<T>::printQueue(){
    cout<<"Queue is: [";
    for(int i=front;i<=back;i++){
        cout<<queue[i];
        if(i!=back){
            cout<<", ";
        }
    }
    cout<<"]\n";
}


int main(){
    Queue<int> object;
    int choice;
    while(true){
        cout<<"1.Insert element in queue.\n";
        cout<<"2.Remove element from queue.\n";
        cout<<"3.Get 1st element of queue.\n";
        cout<<"4.output Queue\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                object.enqueue();
                break;
            case 2:
                object.dequeue();
                break;
            case 3:
                object.peek();
                break;
            case 4:
                object.printQueue();
                break;
            default:
                cout<<"Wrong option entered!";
                break;
        }
        char ch;
        cout<<"Press Y/y to continue: ";
        cin>>ch;
        if(ch!='Y' && ch!='y'){
            exit(0);
        }
    }
}