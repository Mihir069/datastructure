#include <iostream>
#include <stack>
using namespace std;
bool isop(char o){
    if(o >= 'a' && o <='z' || o >= 'A' && o <='Z'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cout<<"Enter number of termes :";
    cin>>n;
    char opnstk[n];
    cout<<"Enter an operation :";
    for(int i=0;i<n;i++){
        cin>>opnstk[i];
    }
    for(int i=0;i<n;i++){
        cout<<opnstk[i];
    }
    stack<char> s;
    for(int i=0;i<n;i++){
        if(isop(opnstk[i])){
            char op;
            s.push(op);
        }
        else{
            char op1 = s.top();
            s.pop();
            char op2 = s.top();
            s.pop();
            //s.push("(" + op2 + opnstk[i] + op1 + ")");
            cout<<"(" + op2 + opnstk[i] + op1 + ")";
        }
        return s.top();
    }
    return 0;
}