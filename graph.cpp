// #include <iostream>
// #include "graphmatrix.h"
// #include "graphadj.h"

// using namespace std;

// bool isSubGraph(GraphAdjList*, GraphAdjList*);
// bool isPath(GraphAdjList*, int*, int);
// bool isSimplePath(GraphAdjList*, int*, int);
// void reachVector(GraphAdjList*, int, bool*);
// bool canReach(GraphAdjList*, int, int);


// int main(){

//     // Teste função: isSimplePath
//     int p0[]={0,1,2,3};
//     int p1[]={0,1,2,3,0};
//     int p2[]={1,2,3,4,2,3};
//     int p3[]={0,1,2,5};
//     int p4[]={0,1,2,3};

//     GraphAdjList* G0;
//     GraphAdjList G0Ob(6);
//     G0 = &G0Ob;
//     G0->addEdge(0, 1);
//     G0->addEdge(0, 2);
//     G0->addEdge(1, 3);
//     G0->addEdge(1, 4);
//     G0->addEdge(2, 4);
//     G0->addEdge(3, 4);
//     G0->addEdge(4, 1);
//     G0->addEdge(4, 5);

//     GraphAdjList* G1;
//     GraphAdjList G1Ob(6);
//     G1 = &G1Ob;
//     G1->addEdge(0, 1);
//     G1->addEdge(0, 2);
//     G1->addEdge(1, 2);
//     G1->addEdge(1, 3);
//     G1->addEdge(2, 3);
//     G1->addEdge(3, 4);
//     G1->addEdge(4, 2);
//     G1->addEdge(4, 1);
//     G1->addEdge(4, 5);
//     G1->addEdge(5, 0);

//     GraphAdjList* G2;
//     GraphAdjList G2Ob(7);
//     G2 = &G2Ob;
//     G2->addEdge(0, 1);
//     G2->addEdge(0, 2);
//     G2->addEdge(1, 2);
//     G2->addEdge(2, 6);
//     G2->addEdge(3, 2);
//     G2->addEdge(3, 4);
//     G2->addEdge(5, 2);
//     G2->addEdge(5, 4);

//     GraphAdjList* G3;
//     GraphAdjList G3Ob(5);
//     G3 = &G3Ob;
//     G3->addEdge(0, 1);
//     G3->addEdge(0, 2);
//     G3->addEdge(1, 3);
//     G3->addEdge(2, 4);
//     G3->addEdge(3, 2);
//     G3->addEdge(3, 4);

//     GraphAdjList* subG0;
//     GraphAdjList subG0Ob(3);
//     subG0 = &subG0Ob;
//     subG0->addEdge(0, 1);
//     subG0->addEdge(1, 3);

//     GraphAdjList* subG1;
//     GraphAdjList subG1Ob(3);
//     subG1 = &subG1Ob;
//     subG1->addEdge(0, 1);
//     subG1->addEdge(1, 2);

//     GraphAdjList* subG2;
//     GraphAdjList subG2Ob(3);
//     subG2 = &subG2Ob;
//     subG2->addEdge(1, 2);

//     cout << "Teste função canReach: " << endl;
//     cout << "G0, há um caminho entre 0 e 5?" << endl;
//     if(canReach(G0, 0, 5)){
//         cout << "Sim!" << endl;
//         }
//     else{
//         cout << "Não." << endl;
//         }
//     cout << "G2, há um caminho entre 0 e 5?" << endl;
//     if(canReach(G2, 0, 5)){
//         cout << "Sim!" << endl;
//         }
//     else{
//         cout << "Não." << endl;
//         }


//     return 0;
// };


// bool isSubGraph(GraphAdjList* G, GraphAdjList* H){
//     /* Verificando se H é sub-grafo de G 
//     Condições mínimas e necessárias para ser um subgrafo: 
//         i) H(vértices) \in G(vértices);
//         ii) H(arestas) \in G(arestas);
//         iii) Se (a,b)\inH(arestas) então a,b\inH(vértices);
//     */
//     // Tirando casos triviais, do sub-grafo ter mais vértices ou mais arestas que o grafo original
//     if((H->getNumVertex()>G->getNumVertex())||(H->getNumEdge()>G->getNumEdge())){
//         return false;
//     } // Até aqui ok
//     // Note que precisamos apenas verificar se para toda aresta a em H, a é aresta de G //
//     for(int i=0;i<H->getNumVertex();i++){
//         if(H->getNumEdgeVertex()[i]>G->getNumEdgeVertex()[i]){
//             return false;
//         }
//         EdgeNode* edge = H->getEdges()[i];
//         while(edge!=nullptr){
//             // Verificando se é verdade que há uma aresta entre i e j em H então não há uma aresta entre i e j em G, isso implica que H não é subgrafo de G.
//             int j = edge->getVertex();
//             if(!G->hasEdge(i,j)){
//                 return false;
//             }
//             edge = edge->getNext();
//         }
//     }
//     return true;
// }


// bool isPath(GraphAdjList* G, int* path, int n){
//     for(int i=0; i<n-1;i++){
//         if(!G->hasEdge(path[i],path[i+1])){
//             return false;
//         }
//     }
//     return true;
// }

// bool isSimplePath(GraphAdjList* G, int* path, int n){
//     int vertexPath[G->getNumVertex()];
//     for(int i=0; i<G->getNumVertex(); i++){vertexPath[i]=0;}
//     vertexPath[path[0]]++;
//     for(int i=0; i<n-1;i++){
//         vertexPath[path[i+1]]++;
//         if(vertexPath[path[i+1]]>1){
//             return false;
//         }
//         if(!G->hasEdge(path[i],path[i+1])){
//             return false;
//         }
//     }
//     return true;
// }

// void reachVector(GraphAdjList* G, int i, bool* visited){
//     visited[i]=true;
//     for(int j=0; j<G->getNumVertex(); j++){
//         if(G->hasEdge(i,j) && !visited[j]){
//             reachVector(G, j, visited);
//         }
//     }
// }

// bool canReach(GraphAdjList* G, int i, int j){
//     bool visited[G->getNumVertex()];
//     for(int k=0; k<G->getNumVertex(); k++){
//         visited[k]=false;
//         }
//     reachVector(G,i,visited);
//     for(int n=0; n<G->getNumVertex(); n++){
//         cout << visited[n] << " ";
//     }
//     cout << endl;
//     return visited[j];
// }
