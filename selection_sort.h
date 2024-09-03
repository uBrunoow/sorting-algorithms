#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
#include <time.h>

void selecion_sort(float vet[], int n, int *comparacoes, int *acessos)
{
  int i, j, soma = 0;
  *comparacoes = 0;
  *acessos = 0;

  for (i = 0; i < n - 1; i++)
  {
    soma += i;
    int i_menor = i;
    for (j = i + 1; j < n; j++)
    {
      (*comparacoes)++;
      (*acessos) += 2; // Acesso a vet[j] e vet[i_menor]
      if (vet[j] < vet[i_menor])
      {
        i_menor = j;
      }
    }

    (*acessos) += 4; // Acessos para a troca: vet[i], vet[i_menor], vet[i], vet[i_menor]
    float aux = vet[i];
    vet[i] = vet[i_menor];
    vet[i_menor] = aux;
  }
}