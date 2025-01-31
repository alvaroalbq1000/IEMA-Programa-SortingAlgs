// Autor: Álvaro Gabriel Alves Albuquerque
// Criado em: 2023
// Apenas para exibição e estudo

#include <iostream>
using namespace std; 

// Inverte arr[0..i]
void flip(int array[], int i) {  
    int temp, start = 0;  
    while (start < i){  // Troca os elementos nas posições start e i
        temp = array[start];  
        array[start] = array[i];  
        array[i] = temp;  
        start++;  
        i--;  
    }  
}  

// Retorna o índice do elemento máximo em array[0..n-1]
int findMax(int array[], int n) {  
    int m, i;  
    for (m = 0, i = 0; i < n; ++i)  
        if (array[i] > array[m])  
            m = i;  
    return m;  
}  

// Função principal que ordena o array usando operações de flip
void pancake_Sort(int *array, int n) {  
    for (int curr_size = n; curr_size > 1; --curr_size) {  
        // Encontra o índice do elemento máximo em arr[0..curr_size-1]
        int m = findMax(array, curr_size);  
        // Move o elemento máximo para o final do array, se ainda não estiver lá
        if (m != curr_size-1) {  
            // Move o número máximo para o início primeiro
            flip(array, m);  
            // Agora move o número máximo para o final invertendo o array atual
            flip(array, curr_size-1);  
        }  
    }  
}

// Função de utilidade para imprimir um array de tamanho n
void printArray(int array[], int n) {  
    for (int i = 0; i < n; ++i)  
        cout << array[i] << " ";  
}  

// Função principal (Driver program)
int main() {  
    int array[] = {20, 5, 2, 13, 15, 6, 14};  
    int n = sizeof(array) / sizeof(array[0]);  
    // Chama a função para ordenar o array
    pancake_Sort(array, n);  
    cout << "Sorted Array:" << endl;  
    printArray(array, n);  
    return 0;  
}