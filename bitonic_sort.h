
// Função para comparar e trocar elementos
void compareAndSwap(float arr[], int i, int j, int dir, int *comparacoes, int *acessos) {
    (*comparacoes)++;
    (*acessos) += 2; // Acessos para leitura de arr[i] e arr[j]
    if (dir == (arr[i] > arr[j])) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        (*acessos) += 2; // Acessos para escrita em arr[i] e arr[j]
    }
}

// Função para criar uma sequência bitônica
void bitonicMerge(float arr[], int low, int cnt, int dir, int *comparacoes, int *acessos) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            compareAndSwap(arr, i, i + k, dir, comparacoes, acessos);
        }
        bitonicMerge(arr, low, k, dir, comparacoes, acessos);
        bitonicMerge(arr, low + k, k, dir, comparacoes, acessos);
    }
}

// Função para criar uma sequência bitônica
void bitonicSort(float arr[], int low, int cnt, int dir, int *comparacoes, int *acessos) {
    if (cnt > 1) {
        int k = cnt / 2;

        // Ordena em ordem crescente
        bitonicSort(arr, low, k, 1, comparacoes, acessos);

        // Ordena em ordem decrescente
        bitonicSort(arr, low + k, k, 0, comparacoes, acessos);

        // Mescla a sequência bitônica
        bitonicMerge(arr, low, cnt, dir, comparacoes, acessos);
    }
}

// Função principal para Bitonic Sort
void bitonic_sort(float arr[], int n, int *comparacoes, int *acessos) {
    *comparacoes = 0;
    *acessos = 0;
    bitonicSort(arr, 0, n, 1, comparacoes, acessos);
}
