#ifndef GRAPHADJ_H_INCLUDED
#define GRAPHADJ_H_INCLUDED
#include <iostream>

using namespace std;

class EdgeNode{
public:
    EdgeNode(int newVertex, EdgeNode* newNext):vertex(newVertex),next(newNext){} // Construtor 
    int getVertex(){
        return vertex;
    }
    EdgeNode* getNext(){
        return next;
    }
    void setNext(EdgeNode* newNext){
        next = newNext;
    }
private:
    int vertex;
    EdgeNode* next;
    int weight;
};

class GraphAdjList{
private:
    int numVertex;
    int numEdge;
    EdgeNode** edges; // Ponteiro que aponta para um ponteiro de uma linked list
    int* numEdgeVertex; // Número de aresta saindo de cada vértice
public:
    GraphAdjList(int numVert); // Construtor
    ~GraphAdjList(); // Desconstrutor
    // Definindo métodos
    bool hasEdge(int v1, int v2);
    void addEdgeFinal(int v1, int v2);
    void addEdge(int v1, int v2);
    void removeEdge(int v1, int v2);
    void printEdges();
    void printAdjList();
    int getNumVertex();
    int getNumEdge();
    EdgeNode** getEdges();
    int* getNumEdgeVertex();
};

GraphAdjList::GraphAdjList(int numVert):numVertex(numVert),numEdge(0),edges(nullptr){
    edges = new EdgeNode*[numVert]; // Criando uma linked list vazia para cada vertice
    numEdgeVertex = new int[numVert];
    for(int v=0; v<numVert; v++){
        getNumEdgeVertex()[v]=0;
        edges[v] = nullptr; // Cada vértice recebe uma linked list vazia
    }
} 

GraphAdjList::~GraphAdjList(){
    for(int v=0; v<numVertex;v++){
        EdgeNode* edge = edges[v];
        while(edge!=nullptr){
            EdgeNode* next = edge->getNext();
            delete edge;
            edge = next;
        }
        delete[] edges;
    }
} 

bool GraphAdjList::hasEdge(int v1, int v2){
    EdgeNode* edge = edges[v1]; // O primeiro elemento dessa lista encadeada, já é um vértice associado a uma aresta
    while(edge!=nullptr){
        if(edge->getVertex()==v2){
            return true;
        }
        else{
            edge=edge->getNext();
        }
    }
    return false;
}
void GraphAdjList::addEdgeFinal(int v1, int v2){
    // Adiciona uma aresta entre v1 e v2, uma aresta que saí de v1 e chega em v2, adiciona no final da lista
    EdgeNode* edge=edges[v1];
    if(hasEdge(v1,v2)){
        return;
    }
    EdgeNode* newEdge;
    newEdge = new EdgeNode(v2,nullptr);
    if(edge!=nullptr){
        while(edge->getNext()!=nullptr){
            edge = edge->getNext();
        }
        edge->setNext(newEdge);
    }
    else{
        edges[v1] = newEdge;
    }
    numEdgeVertex[v1]++;
    numEdge++; 
}

void GraphAdjList::addEdge(int v1, int v2){
    // Adiciona uma aresta entre v1 e v2, uma aresta que saí de v1 e chega em v2, no começo
    if(hasEdge(v1,v2)){
        return;
    }
    EdgeNode* newEdge;
    newEdge = new EdgeNode(v2,edges[v1]);
    edges[v1]=newEdge;
    numEdgeVertex[v1]++;
    numEdge++; 
}

void GraphAdjList::removeEdge(int v1, int v2){
    EdgeNode* edge = edges[v1];
    EdgeNode* previousEdge = nullptr;
    if(not hasEdge(v1,v2)){
        return;
    }
    while(edge!=nullptr){
        if(edge->getVertex()==v2){
            if(previousEdge == nullptr){
                edges[v1]=edge->getNext();
            }
            else{
                previousEdge->setNext(edge->getNext());
            }
            delete edge;
        }
        else{
            previousEdge = edge;
            edge=edge->getNext();
        }
    }
    numEdgeVertex[v1]--;
    numEdge--;
}

void GraphAdjList::printEdges(){
    for(int i = 0; i<numVertex; i++){
        EdgeNode* edge = edges[i];
        cout << "Vertex V" << i << ": ";
        while(edge!=nullptr){
            cout <<edge->getVertex() << "->";
            edge = edge->getNext();
        }
        cout << "nullptr" <<endl;
    }
}

void GraphAdjList::printAdjList(){ 
    for(int i=0; i<numVertex; i++){
        EdgeNode* edge = edges[i];
        while(edge!=nullptr){
            cout << "(" << i << "," << edge->getVertex() << ")";
            edge = edge->getNext();
        }
        cout << endl;
    }
}
int GraphAdjList::getNumVertex(){
    return numVertex;
}
int GraphAdjList::getNumEdge(){
    return numEdge;
}
EdgeNode** GraphAdjList::getEdges(){
    return edges;
}
int* GraphAdjList::getNumEdgeVertex(){
    return numEdgeVertex;
}
#endif // GRAPHADJ_H_INCLUDED