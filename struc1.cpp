#include <iostream>
#include <string>
using namespace std;

struct employee
{
    /* data */
    int Id;
    float salary;
    char favchar;
    string fname;
};

int main(){
    struct employee Mihir;
    Mihir.Id = 30;
    Mihir.favchar='P';
    Mihir.salary = 23.50;
    Mihir.fname = "Mihir Kumar Sah";
    cout<<"Your Id :"<<Mihir.Id<<endl;
    cout<<"Your favourate character:"<<Mihir.favchar<<endl;
    cout<<"Your salary:"<<Mihir.salary<<endl;
    cout<<"Your full name:"<<Mihir.fname<<endl;
    
    return 0;
}