// #include <iostream>
// #include <limits.h>
// #include <vector>
// #include <functional>
// #include <algorithm>
// #include <queue>
// #include <vector>

// #include "graphadj.h"

// using namespace std;

// void CaminhoLimitado(GraphAdjList* G, int parents[],int distances[],int tempo[],int fonte,int sorvedouro,int t){   
//     // Inicializa os vetores de distancias, pais e checked
//     bool checked[G->getNumVertex()];
//     for (int i = 0; i < G->getNumVertex(); i++){
//         distances[i] = INT_MAX;
//         parents[i] = -1;
//         checked[i] = false;
//         tempo[i] = INT_MAX;
//     }
//     // Define a distancia da fonte para ela mesma como 0
//     parents[fonte] = fonte;
//     distances[fonte] = 0;
//     tempo[fonte] = 0;
//     // Adiciona a fonte na heap
//     priority_queue<PII, vector<PII>, greater<PII>> heap;
//     heap.push({0, fonte});
//     // Enquanto a heap nao estiver vazia
//     while (!heap.empty()){
//         // Pega o primeiro elemento da fila de prioridade, aquele com menor distancia
//         int v1 = heap.top().second;
//         heap.pop();
//         // Se o vértice já foi verificado, ignore
//         if (checked[v1])
//             continue;
//         // Marca o vértice como verificado
//         checked[v1] = true;
//         // Percorre os vértices adjacentes ao vértice atual
//         EdgeNode* edge = G->edges[v1]->getNext();
//         while (edge != nullptr){
//             int v2 = edge->getVertex();
//             int tamanho = edge->iWeight;
//             int tempoV2 = edge->iTempo;
//             // Cria a árvore considerando a menor distância e o limite de tempo
//             if(tempo[v1] + tempoV2 <= t && distances[v1] + tamanho < distances[v2]){
//                 distances[v2] = distances[v1] + tamanho;
//                 tempo[v2] = tempo[v1] + tempoV2;
//                 parents[v2] = v1;
//                 heap.push({distances[v2], v2});
//             }
//             node = node->next;
//         }
//     }
// }

// int main(){

//     return 0;
// }