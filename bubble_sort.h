void bubble_sort(float vet[], int n, int *comparacoes, int *acessos)
{
  int i, troca, aux;
  *comparacoes = 0;
  *acessos = 0;

  troca = 1;
  while (troca == 1)
  {
    troca = 0;
    for (i = 0; i < n - 1; i++)
    {
      (*comparacoes)++;
      (*acessos) += 2; // Acesso a vet[i] e vet[i + 1]
      if (vet[i] > vet[i + 1])
      {
        troca = 1;
        (*acessos) += 4; // Acessos para a troca: vet[i], vet[i + 1], vet[i], vet[i + 1]
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
      }
    }
  }
}