// Função para trocar dois elementos
void swap(float *a, float *b)
{
  float t = *a;
  *a = *b;
  *b = t;
}

// Função de partição
int partition(float arr[], int low, int high, int *comparacoes, int *acessos)
{
  float pivot = arr[high]; // Pivô
  int i = (low - 1); // Índice do menor elemento

  (*acessos)++; // Acesso ao pivô

  for (int j = low; j <= high - 1; j++)
  {
    (*comparacoes)++;
    (*acessos)++; // Acesso a arr[j]
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
      (*acessos) += 4; // Acessos para a troca
    }
  }
  swap(&arr[i + 1], &arr[high]);
  (*acessos) += 4; // Acessos para a troca final
  return (i + 1);
}

// Função principal do Quick Sort
void quick_sort(float arr[], int low, int high, int *comparacoes, int *acessos)
{
  if (low < high)
  {
    int pi = partition(arr, low, high, comparacoes, acessos);

    // Recursivamente ordena os elementos antes e depois da partição
    quick_sort(arr, low, pi - 1, comparacoes, acessos);
    quick_sort(arr, pi + 1, high, comparacoes, acessos);
  }
}