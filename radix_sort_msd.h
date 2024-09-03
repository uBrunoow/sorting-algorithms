#define BASE 10

// Função para encontrar o maior número no array
int getMax2(float arr[], int n, int *comparacoes, int *acessos) {
    int max = arr[0];
    (*acessos)++;
    for (int i = 1; i < n; i++) {
        (*comparacoes)++;
        (*acessos)++;
        if (arr[i] > max) {
            max = arr[i];
            (*acessos)++;
        }
    }
    return max;
}

// Função para obter o dígito em uma posição específica
int getDigit(int num, int pos, int *acessos) {
    for (int i = 0; i < pos; i++) {
        num /= BASE;
        (*acessos)++;
    }
    return num % BASE;
}

// Função de classificação por dígito
void countingSortByDigit(float arr[], int n, int pos, int *comparacoes, int *acessos) {
    int output[n];
    int count[BASE] = {0};

    // Contagem das ocorrências dos dígitos
    for (int i = 0; i < n; i++) {
        count[getDigit(arr[i], pos, acessos)]++;
        (*acessos)++;
    }

    // Atualização das posições no array de contagem
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
        (*acessos)++;
    }

    // Construção do array de saída
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], pos, acessos);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
        (*acessos) += 3;
    }

    // Copiando o array de saída para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        (*acessos)++;
    }
}

// Função recursiva para Radix Sort MSD
void radixSortMSD(float arr[], int n, int pos, int *comparacoes, int *acessos) {
    if (n <= 1 || pos < 0)
        return;

    countingSortByDigit(arr, n, pos, comparacoes, acessos);

    // Encontra os intervalos para a próxima chamada recursiva
    int start = 0;
    for (int i = 1; i < n; i++) {
        (*comparacoes)++;
        if (getDigit(arr[i], pos, acessos) != getDigit(arr[i - 1], pos, acessos)) {
            radixSortMSD(arr + start, i - start, pos - 1, comparacoes, acessos);
            start = i;
        }
    }
    radixSortMSD(arr + start, n - start, pos - 1, comparacoes, acessos);
}

// Função principal para Radix Sort MSD
void radix_sort_msd(float arr[], int n, int *comparacoes, int *acessos) {
    *comparacoes = 0;
    *acessos = 0;
    int max = getMax2(arr, n, comparacoes, acessos);
    int maxDigits = 0;
    while (max > 0) {
        max /= BASE;
        maxDigits++;
        (*acessos)++;
    }
    radixSortMSD(arr, n, maxDigits - 1, comparacoes, acessos);
}