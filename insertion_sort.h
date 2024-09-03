void insertion_sort(float vet[], int n, int *comparacoes, int *acessos)
{
  int i, j;
  float key;
  *comparacoes = 0;
  *acessos = 0;

  for (i = 1; i < n; i++)
  {
    key = vet[i];
    j = i - 1;

    (*acessos)++; // Acesso a vet[i]

    // Move elementos de vet[0..i-1] que são maiores que key
    while (j >= 0 && vet[j] > key)
    {
      (*comparacoes)++;
      (*acessos) += 2; // Acesso a vet[j] e vet[j + 1]
      vet[j + 1] = vet[j];
      j = j - 1;
    }
    if (j >= 0) (*comparacoes)++; // Comparação final quando vet[j] <= key

    vet[j + 1] = key;
    (*acessos)++; // Acesso para inserir key
  }
}