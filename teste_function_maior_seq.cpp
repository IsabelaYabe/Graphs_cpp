#include <iostream>
#include <limits.h>

using namespace std;

class Node{
public:
    Node(int newValue, Node* newNext):value(newValue),next(newNext){} // Construtor 
    int getValue(){
        return value;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* newNext){
        next = newNext;
    }
private:
    int value;
    Node* next;
};

class LinkedList{
public:
    LinkedList(Node* newNode):head(newNode){} // Construtor 
    ~LinkedList(); // Destrutor
    Node* getHead(){
        return head;
    }    
    void addNode(int i);
private:
    Node* head;
};
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;  // Libera a memória para cada nó
        current = next;
    }
    head = nullptr;
}
void LinkedList::addNode(int i){
    Node* newNode = new Node(i,nullptr);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->setNext(head);
    head = newNode;
}

int maiorSeq(int array[], int n,int &sumMax){
    if(n==1){
        if(array[0]>sumMax){return array[0];}
    }
    LinkedList* numbers;
    LinkedList numbersOb(nullptr);
    numbers = &numbersOb;
    int newN = 0;
    int temp=0;
    bool positive = true;
    int count = 0;
    while(array[count]<=0){
        count++;
    }
    for(count; count<n; count++){
        int newTemp = temp+array[count];
        if(newTemp<temp && positive){
            positive = false;
            numbers->addNode(temp);
            newN++;
            if(temp>sumMax){
                sumMax=temp;
            }
            temp = 0;

        }
        if(newTemp>temp && !positive){
            positive = true;
            numbers->addNode(temp);
            newN++;
            temp = 0;
        }
        temp += array[count];
    }    
    int newArray[newN];
    int i=0;
    for(Node* node = numbers->getHead();node!=nullptr;node=node->getNext()){
        newArray[i++]=node->getValue();
        cout<< node->getValue() << " ";
        node=node->getNext();
    }
    cout<< ".";
    if(newN>=0){
        array = newArray;
        n = newN;
        return maiorSeq(array, n, sumMax);
    }
    return sumMax;
}


int main() {
    int array[] = {3, 2, -82, 5, 8, 6, -9, 17};

    int sumMax = INT_MIN;

    int result = maiorSeq(array, 8, sumMax);

    std::cout << "Maior sequencia: " << result << std::endl;

    return 0;
}