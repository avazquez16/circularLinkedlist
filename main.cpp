#include <iostream>
using namespace std;




//............................................................................................................................................................................
class Node{
public:
    int data;
    Node *next;
};





//............................................................................................................................................................................
class CircualrLinkedList{
private:
    Node *Head;
    Node *Tail;
public:
    CircualrLinkedList();
    ~CircualrLinkedList();
    void Display();
    void Delete(int index);
    int Lenght();
    void Prepend(int data);
    void Appened(int data);
    void Insert(int index, int data);
};





//............................................................................................................................................................................
CircualrLinkedList::CircualrLinkedList(){
     Head = nullptr;
     Tail = nullptr;
}




//............................................................................................................................................................................
CircualrLinkedList::~CircualrLinkedList(){
    Node *t = Head;
    Node *OrigHead = Head;
    while(t != OrigHead){
        Head = Head->next;
        delete t;
        t = Head;
    }
}




//............................................................................................................................................................................
void CircualrLinkedList::Display(){
    Node *T = Head;
    Node *OrigHead = Head;
    if(Head == nullptr)
        return;
    do{
        cout << T->data << " ";
        T = T->next;
    }
    while(T != OrigHead);
    cout << endl;
}




//............................................................................................................................................................................
void CircualrLinkedList::Insert(int index, int data){
    int CirLLlength = this->Lenght();
    if(index > CirLLlength or index < 0)
        return;
    
    Node *t = new Node();
    Node *T = Head;
    Node *prevT = nullptr;
    int currindex = 0;
    
    t->data = data;
    
    if(Head == nullptr){
        Head=t;
        Tail=t;
        Tail->next=Head;
    }
    else if(index == 0){
        Tail->next = t;
        t->next = Head;
        Head = t;
    }
    else if(index == CirLLlength){
        Tail->next =t;
        Tail = t;
        Tail->next = Head;
    }
    else{
        do{
            prevT = T;
            T = T->next;
            currindex++;
            if(index == currindex){
                prevT->next = t;
                t->next = T;
            }
        }while(T!=Head);
    }
}



//............................................................................................................................................................................
void CircualrLinkedList::Appened(int data){
    Node* t = new Node();
    t->data = data;
    t->next = nullptr;
    
    if(Head == nullptr){
        Head = t;
        Tail = Head;
        Tail->next = Head;
    }
    else{
        Tail->next = t;
        Tail = t;
        Tail->next = Head;
    }
}




//............................................................................................................................................................................
int CircualrLinkedList::Lenght(){
    int length = 0;
    Node *T = Head;
    
    if(Head == nullptr)
        return length;
    else{
        do{
            T = T->next;
            length++;
        }while(T!= Head);
    }
    return length;
}




//............................................................................................................................................................................
void CircualrLinkedList::Delete(int index){
    int CirLLlength = this->Lenght();
    int currindex = 0;
    Node *T = Head;
    Node * prevT = nullptr;
    
    if(Head == nullptr or index >= CirLLlength)
        return;
    else if(index == 0 and CirLLlength == 1){
        Tail = nullptr;
        Head =nullptr;
        delete T;
    }
    else if(index == 0){
        Head = Head->next;
        delete T;
        Tail->next = Head;
    }
    else{
        do{
            prevT = T;
            T = T->next;
            currindex++;
            
            if(index == currindex){
                if(T->next == Head)
                    Tail = prevT;
                prevT->next = T->next;
                delete T;
            }
        }while(T!=Head);
    }
        
}






//............................................................................................................................................................................
class NodeDLL{
public:
    NodeDLL* prev;
    int data;
    NodeDLL* next;
};

class DoublyLinkedList{
public:
    NodeDLL Head;
    NodeDLL Tail;
private:
    DoublyLinkedList();
    void appened(int data);
};






//............................................................................................................................................................................
int main() {
    CircualrLinkedList CL;
    
    for(int i =1; i < 6; i++)
        CL.Appened(i);
    CL.Display();
    CL.Insert(5, 6);
    CL.Display();

    CL.Insert(0, 6);
    CL.Display();
    CL.Delete(5);
    CL.Display();
    CL.Insert(6, 10);
    CL.Display();

    return 0;
}

