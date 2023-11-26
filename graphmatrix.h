#ifndef GRAPHMATRIX_H_INCLUDED
#define GRAPHMATRIX_H_INCLUDED
#include <iostream>

using namespace std;

class GraphMatrix{
private:
    int numVertex;
    int numEdge;
    bool** adjMatrix; // O primeiro ponteiro aponta para as linhas e o segundo para as colunas.
public:
    GraphMatrix(int numVert); // Construtor
    ~GraphMatrix(); // Desconstrutor
    // Definindo métodos
    bool hasEdge(int v1, int v2);
    void addEdge(int v1, int v2);
    void removeEdge(int v1, int v2);
    void printEdges();
    void printMatrix();
    int getNumVertex();
    int getNumEdge();
    bool** getAdjMatrix(); 
};

GraphMatrix::GraphMatrix(int numVert):numVertex(numVert), numEdge(0), adjMatrix(nullptr){// Lista de inicialização
    // Inicializando matrix de adjacência 
    adjMatrix = new bool*[numVertex]; // Estou criando um vetor de ponteiros, para isso preciso alocar na memória
    // Inserindo valores bool (false)
    for(int i=0; i<numVertex; i++){
        adjMatrix[i]= new bool[numVertex];
        for (int j=0; j<numVertex; j++){
            adjMatrix[i][j]=false;
        }
    }
}

GraphMatrix::~GraphMatrix(){
    for (int i=0; i<numVertex; i++){
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

bool GraphMatrix::hasEdge(int v1, int v2){
    return adjMatrix[v1][v2];
}

void GraphMatrix::addEdge(int v1, int v2){
    if (!hasEdge(v1,v2)){
        adjMatrix[v1][v2] = true;
        numEdge++;
    }
}

void GraphMatrix::removeEdge(int v1, int v2){
    if(hasEdge(v1,v2)){
        adjMatrix[v1][v2]=false;
        numEdge--;
    }
}

void GraphMatrix::printEdges(){
    for (int i=0; i<numVertex; i++){
        for (int j=0; j<numVertex; j++){
            if(hasEdge(i,j)){
                std::cout<< "(" << i << "," << j << ")"<< std::endl;
            }
        }
    }
}

void GraphMatrix::printMatrix(){
    for (int i=0; i<numVertex; i++){
        for (int j=0; j<numVertex; j++){
            std::cout << hasEdge(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

int GraphMatrix::getNumVertex(){
    return numVertex;
}

int GraphMatrix::getNumEdge(){
    return numEdge;
}

bool** GraphMatrix::getAdjMatrix(){
    return adjMatrix;
}


#endif // GRAPHMATRIX_H_INCLUDED