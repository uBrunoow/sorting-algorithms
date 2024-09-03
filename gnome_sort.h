// Função para realizar o Gnome Sort
void gnome_sort(float arr[], int n, int *comparacoes, int *acessos) {
    int index = 0;

    // Inicializa contadores
    *comparacoes = 0;
    *acessos = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }
        (*comparacoes)++;
        (*acessos) += 2; // Acessos para leitura de arr[index] e arr[index - 1]
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            float temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            (*acessos) += 4; // Acessos para leitura e escrita em arr[index] e arr[index - 1]
            index--;
        }
    }
}