#include <stdbool.h>

// Função para realizar o Cocktail Shaker Sort
void cocktail_shaker_sort(float arr[], int n, int *comparacoes, int *acessos) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    // Inicializa contadores
    *comparacoes = 0;
    *acessos = 0;

    while (swapped) {
        // Reseta a flag swapped para checar se houve troca nesta iteração
        swapped = false;

        // Loop da esquerda para a direita
        for (int i = start; i < end; ++i) {
            (*comparacoes)++;
            (*acessos) += 2; // Acessos para leitura de arr[i] e arr[i + 1]
            if (arr[i] > arr[i + 1]) {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                (*acessos) += 2; // Acessos para escrita em arr[i] e arr[i + 1]
                swapped = true;
            }
        }

        // Se não houve troca, o array está ordenado
        if (!swapped)
            break;

        // Caso contrário, reseta a flag swapped para a próxima iteração
        swapped = false;

        // Move o endpoint para trás, pois o último elemento já está no lugar correto
        --end;

        // Loop da direita para a esquerda
        for (int i = end - 1; i >= start; --i) {
            (*comparacoes)++;
            (*acessos) += 2; // Acessos para leitura de arr[i] e arr[i + 1]
            if (arr[i] > arr[i + 1]) {
                float temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                (*acessos) += 2; // Acessos para escrita em arr[i] e arr[i + 1]
                swapped = true;
            }
        }

        // Move o start para frente, pois o primeiro elemento já está no lugar correto
        ++start;
    }
}