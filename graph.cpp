#include <iostream>
#include "graphmatrix.h"
#include "graphadj.h"

using namespace std;
bool isSubGraph(GraphAdjList, GraphAdjList);
bool isSubGraph(GraphMatrix, GraphMatrix);
bool isPath(GraphMatrix, int*, int);
bool isPath(GraphAdjList, int*, int);
bool isSimplePath(GraphMatrix, int*, int);
bool isSimplePath(GraphAdjList, int*, int);
void reachVector(GraphMatrix, int, bool*);
void reachVector(GraphAdjList, int, bool*);
bool canReach(GraphMatrix, int, int);
bool canReach(GraphAdjList, int, int);

int main(){

    // Teste função: isSimplePath
    int path1[]={0,1,2,3};
    int path2[]={0,1,2,3,0};
    int path3[]={1,2,3,4,2,3};
    int path4[]={0,1,2,5};
    int path5[]={0,1,2,3,4,5,0};

    GraphAdjList g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 0);

    //cout << isPath(g, path1, sizeof(path1)/sizeof(int))<< endl;
    //cout << isPath(g, path2, sizeof(path2)/sizeof(int))<< endl;
    //cout << isPath(g, path3, sizeof(path3)/sizeof(int))<< endl;
    //cout << isPath(g, path4, sizeof(path4)/sizeof(int))<< endl;
    //cout << isPath(g, path5, sizeof(path5)/sizeof(int))<< endl;

    /*if(isPath(g, path1, sizeof(path1)/sizeof(int))){
        cout << "path1 é caminho de g" << endl;
    }

    if(isPath(g, path2, sizeof(path2)/sizeof(int))){
        cout << "path2 é caminho de g" << endl;
    }

    if(isPath(g, path3, sizeof(path3)/sizeof(int))){
        cout << "path3 é caminho de g" << endl;
    }

    if(isPath(g, path4, sizeof(path4)/sizeof(int))){
        cout << "path4 é caminho de g" << endl;
    }

    if(isPath(g, path5, sizeof(path5)/sizeof(int))){
        cout << "path5 é caminho de g" << endl;
    }*/
    // Teste função: isSimplePath

    //cout << isSimplePath(g, path1, sizeof(path1)/sizeof(int))<< endl;
    //cout << isSimplePath(g, path2, sizeof(path2)/sizeof(int))<< endl;
    //cout << isSimplePath(g, path3, sizeof(path3)/sizeof(int))<< endl;
    //cout << isSimplePath(g, path4, sizeof(path4)/sizeof(int))<< endl;
    //cout << isSimplePath(g, path5, sizeof(path5)/sizeof(int))<< endl;
    
    /*if(isPath(g, path1, sizeof(path1)/sizeof(int)) && isSimplePath(g,path1,sizeof(path1)/sizeof(int))){
        cout << "path1 é caminho simples de g" << endl;
    }

    if(isPath(g, path2, sizeof(path2)/sizeof(int)) && isSimplePath(g,path2,sizeof(path2)/sizeof(int))){
        cout << "path2 é caminho simples de g" << endl;
    }

    if(isPath(g, path3, sizeof(path3)/sizeof(int)) && isSimplePath(g,path3,sizeof(path3)/sizeof(int))){
        cout << "path3 é caminho simples de g" << endl;
    }

    if(isPath(g, path4, sizeof(path4)/sizeof(int)) && isSimplePath(g,path4,sizeof(path4)/sizeof(int))){
        cout << "path4 é caminho simples de g" << endl;
    }

    if(isPath(g, path5, sizeof(path5)/sizeof(int)) && isSimplePath(g,path5,sizeof(path5)/sizeof(int))){
        cout << "path5 é caminho simples de g" << endl;
    }*/

    // Teste função: canReach
    GraphAdjList grafo(6);

    grafo.addEdge(0, 3);
    grafo.addEdge(1, 2);
    grafo.addEdge(1, 4);
    grafo.addEdge(3, 2);
    grafo.addEdge(4, 3);
    grafo.addEdge(5, 1);
    grafo.addEdge(5, 2);

    cout << canReach(grafo,0,1) << endl;
    //cout << canReach(grafo,0,2) << endl;
    //cout << canReach(grafo,1,3) << endl;
    //cout << canReach(grafo,1,5) << endl;
    //cout << canReach(grafo,5,2) << endl;

    // Teste função: isSubGraph
    GraphAdjList g1(6);
    GraphAdjList g2(6);
    GraphAdjList g3(6);
    GraphAdjList g4(6);
    GraphAdjList g5(7);
    GraphAdjList g6(6);

    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 4);
    g1.addEdge(3, 4);
    g1.addEdge(4, 2);
    g1.addEdge(4, 5);

    g2.addEdge(0, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 5);

    g3.addEdge(0, 2);
    g3.addEdge(1, 4);
    g3.addEdge(2, 4);
    g3.addEdge(3, 4);
    g3.addEdge(4, 5);

    g4.addEdge(0, 1);
    g4.addEdge(1, 3);
    g4.addEdge(3, 4);
    g4.addEdge(4, 5);
    g4.addEdge(5, 2);

    g5.addEdge(1, 4);
    g5.addEdge(4, 5);

    g6.addEdge(0, 1);
    g6.addEdge(1, 2);

    //cout << isSubGraph(g1,g1)<< endl;
    //cout << isSubGraph(g1,g2)<< endl;
    //cout << isSubGraph(g1,g3)<< endl;
    //cout << isSubGraph(g1,g4)<< endl;
    //cout << isSubGraph(g1,g5)<< endl;
    //cout << isSubGraph(g1,g6)<< endl;

    /*if(isSubGraph(g1, g2)){
        cout << "g2 é subgrafo de g1" << endl;
    }
    
    if(isSubGraph(g1, g3)){
        cout << "g3 é subgrafo de g1" << endl;
    }

    if(isSubGraph(g1, g4)){
        cout << "g4 é subgrafo de g1" << endl;
    }

    if(isSubGraph(g1, g5)){
        cout << "g5 é subgrafo de g1" << endl;
    }

    if(isSubGraph(g1, g6)){
        cout << "g6 é subgrafo de g1" << endl;
    }*/

    return 0;
};

bool isSubGraph(GraphMatrix G, GraphMatrix H){
    /* Verificando se H é sub-grafo de G 
    Condições mínimas e necessárias para ser um subgrafo: 
        i) H(vértices) \in G(vértices);
        ii) H(arestas) \in G(arestas);
        iii) Se (a,b)\inH(arestas) então a,b\inH(vértices);
    */
    // Tirando casos triviais, do sub-grafo ter mais vértices ou mais arestas que o grafo original
    if((H.getNumVertex()>G.getNumVertex())||(H.getNumEdge()>G.getNumEdge())){
        return false;
    }
    // Note que precisamos apenas verificar se para toda aresta a em H, a é aresta de G //
    for(int i=0;i<H.getNumVertex();i++){
        for(int j=0; j<H.getNumVertex();j++){
            // Verificando se é verdade que há uma aresta entre i e j em H então não há uma aresta entre i e j em G, isso implica que H não é subgrafo de G.
            if(H.getAdjMatrix()[i][j] && !G.getAdjMatrix()[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool isSubGraph(GraphAdjList G, GraphAdjList H){
    /* Verificando se H é sub-grafo de G 
    Condições mínimas e necessárias para ser um subgrafo: 
        i) H(vértices) \in G(vértices);
        ii) H(arestas) \in G(arestas);
        iii) Se (a,b)\inH(arestas) então a,b\inH(vértices);
    */
   cout << "ai caramba 0" << endl;
    // Tirando casos triviais, do sub-grafo ter mais vértices ou mais arestas que o grafo original
cout << "u";
    if((H.getNumVertex()>G.getNumVertex())||(H.getNumEdge()>G.getNumEdge())){
        cout << "ai caramba 01" << endl;
        return false;
    } // Até aqui ok
    else{
        cout <<"AOIOI";
    } // Até aqui ok
    // Note que precisamos apenas verificar se para toda aresta a em H, a é aresta de G //
    for(int i=0;i<H.getNumVertex();i++){
        if(H.getNumEdgeVertex()[i]>G.getNumEdgeVertex()[i]){
            cout << "ai caramba 02" << endl; // Até aqui ok
            return false;
        }
        EdgeNode* edge = H.getEdges()[i];
        while(edge!=nullptr){
            // Verificando se é verdade que há uma aresta entre i e j em H então não há uma aresta entre i e j em G, isso implica que H não é subgrafo de G.
            int j = edge->getVertex();
            if(!G.hasEdge(i,j)){
                cout << "ai caramba 03" << endl;
                return false;
            }
            edge = edge->getNext();
        }
    }
    return true;
}

bool isPath(GraphMatrix G, int* path, int n){
    for(int i=0; i<n-1;i++){
        if(!G.hasEdge(path[i],path[i+1])){
            return false;
        }
    }
    return true;
}

bool isPath(GraphAdjList G, int* path, int n){
    for(int i=0; i<n-1;i++){
        if(!G.hasEdge(path[i],path[i+1])){
            return false;
        }
    }
    return true;
}

bool isSimplePath(GraphMatrix G, int* path, int n){
    int vertexPath[G.getNumVertex()];
    for(int i=0; i<G.getNumVertex(); i++){vertexPath[i]=0;}
    vertexPath[path[0]]++;
    for(int i=0; i<n-1;i++){
        vertexPath[path[i+1]]++;
        if(vertexPath[path[i+1]]>1){
            return false;
        }
        if(!G.hasEdge(path[i],path[i+1])){
            return false;
        }
    }
    return true;
}

bool isSimplePath(GraphAdjList G, int* path, int n){
    int vertexPath[G.getNumVertex()];
    for(int i=0; i<G.getNumVertex(); i++){vertexPath[i]=0;}
    vertexPath[path[0]]++;
    for(int i=0; i<n-1;i++){
        vertexPath[path[i+1]]++;
        if(vertexPath[path[i+1]]>1){
            return false;
        }
        if(!G.hasEdge(path[i],path[i+1])){
            return false;
        }
    }
    return true;
}

void reachVector(GraphMatrix G, int i, bool* visited){
    visited[i]=true;
    for(int j=0; j<G.getNumVertex(); j++){
        if(G.hasEdge(i,j) && !visited[j]){
            reachVector(G, j, visited);
        }
    }
}

bool canReach(GraphMatrix G, int i, int j){
    bool* visited[G.getNumVertex()];
    for(int k=0; k<G.getNumVertex(); k++){*visited[k]=false;}
    reachVector(G,i,*visited);
    return visited[j];
}

void reachVector(GraphAdjList G, int i, bool* visited){
    visited[i]=true;
    for(int j=0; j<G.getNumVertex(); j++){
        if(G.hasEdge(i,j) && !visited[j]){
            reachVector(G, j, visited);
        }
    }
}

bool canReach(GraphAdjList G, int i, int j){
    bool* visited[G.getNumVertex()];
    for(int k=0; k<G.getNumVertex(); k++){*visited[k]=false;}
    reachVector(G,i,*visited);
    return visited[j];
}