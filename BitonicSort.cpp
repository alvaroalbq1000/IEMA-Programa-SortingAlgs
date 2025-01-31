// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

// Programa em C++ para Bitonic Sort. Tamanho da entrada deve ser uma potência de 2.
#include<bits/stdc++.h> 
using namespace std; 

// dir: direção (Ascendente ou Descendente);
// se a direção concordar com a[i] > a[j], a[i] e a[j] serão trocados.
void compAndSwap(int a[], int i, int j, int dir) { 
    if (dir==(a[i]>a[j])) 
        swap(a[i],a[j]); 
} 

// Ordena uma sequência bitônica na ordem ascendente (dir = 1) ou descendente (dir = 0)
// A sequência inicia na posição índice low; cnt é o número de elementos a ordenar
void bitonicMerge(int a[], int low, int cnt, int dir) { 
    if (cnt>1) { 
        int k = cnt/2; 
        for (int i=low; i<low+k; i++) 
            compAndSwap(a, i, i+k, dir); 
        bitonicMerge(a, low, k, dir); 
        bitonicMerge(a, low+k, k, dir); 
    } 
} 

// Função geral: produz uma sequência bitônica por recursividade, ordenando suas duas
// metades em ordens diferentes, aí chama bitonicMerge para fundí-las na mesma ordem.
void bitonicSort(int a[],int low, int cnt, int dir) { 
    if (cnt>1) { 
        int k = cnt/2; 
        bitonicSort(a, low, k, 1); // ordena na direção ascendente (1)
        bitonicSort(a, low+k, k, 0); // ordena na direção descendente (0)
        bitonicMerge(a,low, cnt, dir); // Junta as sequências em ascendência (dir = 1)
    } 
} 

// Chama a bitonicSort para ordenar a lista de tamanho N em ordem ascendente
void sort(int a[], int N, int up) { 
    bitonicSort(a,0, N, up); 
} 
 
// Driver code 
int main() { 
    int a[]= {3, 7, 4, 8, 6, 2, 1, 5}; 
    int N = sizeof(a)/sizeof(a[0]); 
    int up = 1; // means sort in ascending order 
    sort(a, N, up); 
    printf("Sorted array: \n"); 
    for (int i=0; i<N; i++) 
        printf("%d ", a[i]); 
    return 0; 
}