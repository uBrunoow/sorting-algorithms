// Função para realizar o Shell Sort
void shell_sort(float arr[], int n, int *comparacoes, int *acessos) {
    // Inicializa contadores
    *comparacoes = 0;
    *acessos = 0;

    // Começa com um grande intervalo, depois reduz o intervalo
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realiza a ordenação por inserção para este intervalo
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            (*acessos)++; // Acesso para leitura de arr[i]
            int j;
            for (j = i; j >= gap; j -= gap) {
                (*comparacoes)++; // Comparação no loop
                (*acessos)++; // Acesso para leitura de arr[j - gap]
                if (arr[j - gap] <= temp) {
                    break;
                }
                arr[j] = arr[j - gap];
                (*acessos)++; // Acesso para escrita em arr[j]
            }
            arr[j] = temp;
            (*acessos)++; // Acesso para escrita em arr[j]
        }
    }
}