// Função para trocar dois elementos
void swap2(float *a, float *b)
{
  float t = *a;
  *a = *b;
  *b = t;
}

// Função para criar um heap
void heapify(float arr[], int n, int i, int *comparacoes, int *acessos)
{
  int largest = i; // Inicializa o maior como raiz
  int left = 2 * i + 1; // Filho esquerdo
  int right = 2 * i + 2; // Filho direito

  (*acessos)++; // Acesso a arr[i]

  // Se o filho esquerdo é maior que a raiz
  if (left < n)
  {
    (*comparacoes)++;
    (*acessos)++; // Acesso a arr[left]
    if (arr[left] > arr[largest])
    {
      largest = left;
    }
  }

  // Se o filho direito é maior que o maior até agora
  if (right < n)
  {
    (*comparacoes)++;
    (*acessos)++; // Acesso a arr[right]
    if (arr[right] > arr[largest])
    {
      largest = right;
    }
  }

  // Se o maior não é a raiz
  if (largest != i)
  {
    swap2(&arr[i], &arr[largest]);
    (*acessos) += 4; // Acessos para a troca

    // Recursivamente heapifica a subárvore afetada
    heapify(arr, n, largest, comparacoes, acessos);
  }
}

// Função principal do Heap Sort
void heap_sort(float arr[], int n, int *comparacoes, int *acessos)
{
  // Constrói o heap (reorganiza o array)
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i, comparacoes, acessos);
  }

  // Extrai um elemento do heap de cada vez
  for (int i = n - 1; i > 0; i--)
  {
    // Move a raiz atual para o final
    swap2(&arr[0], &arr[i]);
    (*acessos) += 4; // Acessos para a troca

    // Chama heapify na heap reduzida
    heapify(arr, i, 0, comparacoes, acessos);
  }
}