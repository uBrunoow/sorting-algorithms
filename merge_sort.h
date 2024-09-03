// Função para combinar dois subarrays
void merge(float arr[], int l, int m, int r, int *comparacoes, int *acessos)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Cria arrays temporários
  float L[n1], R[n2];

  // Copia os dados para os arrays temporários L[] e R[]
  for (i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
    (*acessos)++;
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
    (*acessos)++;
  }

  // Combina os arrays temporários de volta em arr[l..r]
  i = 0; // Índice inicial do primeiro subarray
  j = 0; // Índice inicial do segundo subarray
  k = l; // Índice inicial do subarray combinado
  while (i < n1 && j < n2)
  {
    (*comparacoes)++;
    (*acessos) += 2; // Acessos a L[i] e R[j]
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    (*acessos)++; // Acesso para escrever em arr[k]
    k++;
  }

  // Copia os elementos restantes de L[], se houver
  while (i < n1)
  {
    arr[k] = L[i];
    (*acessos)++; // Acesso para escrever em arr[k]
    i++;
    k++;
  }

  // Copia os elementos restantes de R[], se houver
  while (j < n2)
  {
    arr[k] = R[j];
    (*acessos)++; // Acesso para escrever em arr[k]
    j++;
    k++;
  }
}

// Função principal do Merge Sort
void merge_sort(float arr[], int l, int r, int *comparacoes, int *acessos)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    // Ordena a primeira e a segunda metade
    merge_sort(arr, l, m, comparacoes, acessos);
    merge_sort(arr, m + 1, r, comparacoes, acessos);

    // Combina as metades ordenadas
    merge(arr, l, m, r, comparacoes, acessos);
  }
}