#include <iostream>
#include <climits>

using namespace std;

int findNextAugmentingPath(int v0, int vf, int* parent, EdgeNode* parentEdge[]) {
    // Inicializa um vetor de booleanos para rastrear os vértices visitados
    bool visited[numVertices];
    for (int v = 0; v < numVertices; v++) {
        visited[v] = false;
    }

    // Inicializa uma fila para armazenar os vértices a serem processados
    queue<int> queue;

    // Marca o vértice de origem como visitado e o adiciona à fila
    visited[v0] = true;
    queue.push(v0);

    // Enquanto a fila não estiver vazia
    while (!queue.empty()) {
        // Remove o primeiro elemento da fila (v)
        int v = queue.front();
        queue.pop();

        // Se chegamos ao destino, saímos do loop
        if (v == vf) {
            break;
        }

        // Para cada aresta saindo do vértice v
        EdgeNode* edge = edges[v];
        while (edge) {
            int residual = edge->capacity() - edge->flow();
            int v2 = edge->getVertex();

            // Se a aresta tem capacidade residual e o vértice adjacente não foi visitado
            if (residual > 0 && !visited[v2]) {
                // Marca o vértice adjacente como visitado
                visited[v2] = true;

                // Define o pai do vértice adjacente como v
                parent[v2] = v;

                // Define a aresta pai do vértice adjacente como a aresta atual
                parentEdge[v2] = edge;

                // Adiciona o vértice adjacente à fila para processamento futuro
                queue.push(v2);
            }

            // Move para a próxima aresta saindo do vértice v
            edge = edge->next();
        }
    }

    // Se o destino não foi visitado, não existe caminho de aumento
    if (!visited[vf]) {
        return 0;
    }

    // Calcula a capacidade residual mínima ao longo do caminho encontrado
    int delta = INT_MAX;
    for (int v2 = vf; v2 != v0; v2 = parent[v2]) {
        EdgeNode* edge = parentEdge[v2];
        delta = min(delta, edge->capacity() - edge->flow());
    }

    // Retorna a capacidade residual mínima ao longo do caminho
    return delta;
}

int main() {
    //int arr[] = {1,4,-10,11,22,-70,30};
    int arr[] = {3,2,-82,5,8,6,-9,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maiorSeqDivisaoConquista(arr, 0, n - 1);
    cout << "A soma máxima da submatriz contígua é: " << result << endl;
    cout << 7/2;
    return 0;
}