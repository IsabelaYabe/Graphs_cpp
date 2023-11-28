#include <iostream>
#include <climits>

using namespace std;

int maxSomaDivisao(int arr[], int inicio, int meio, int fim) {
    int somaAtual = 0;
    int maxSomaEsquerda = INT_MIN;
    for (int i = meio; i >= inicio; i--) {
        somaAtual += arr[i];
        if (somaAtual > maxSomaEsquerda) {
            maxSomaEsquerda = somaAtual;
        }
    }

    somaAtual = 0;
    int maxSomaDireita = INT_MIN;
    for (int i = meio + 1; i <= fim; i++) {
        somaAtual += arr[i];
        if (somaAtual > maxSomaDireita) {
            maxSomaDireita = somaAtual;
        }
    }

    return maxSomaEsquerda + maxSomaDireita;
}

int maiorSeqDivisaoConquista(int arr[], int inicio, int fim) {
    if (inicio == fim) {
        return arr[inicio];
    }

    int meio = (inicio + fim) / 2;

    // Calcula a maior soma de subsequência contígua nas partes esquerda e direita
    int maxSomaEsquerda = maiorSeqDivisaoConquista(arr, inicio, meio);
    int maxSomaDireita = maiorSeqDivisaoConquista(arr, meio + 1, fim);

    // Calcula a maior soma que atravessa a divisão das partes esquerda e direita
    int maxSomaAtravessa = maxSomaDivisao(arr, inicio, meio, fim);

    // Retorna o máximo entre as três opções
    return max(maxSomaEsquerda, max(maxSomaDireita, maxSomaAtravessa));
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