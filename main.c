#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
#include <time.h>
#include "selection_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "radix_sort_lsd.h"
#include "radix_sort_msd.h"
#include "shell_sort.h"
#include "bitonic_sort.h"
#include "cocktail_shaker_sort.h"
#include "gnome_sort.h"

int main(void)
{

  float *random, *random_copia; // definindo o ponteiro v
  int i, j, valor_random, randomico, num_componentes;

  printf("Informe o numero de componentes do vetor\n");
  scanf("%d", &num_componentes);

  srand(time(NULL));

  random = (float *)malloc(num_componentes * sizeof(float));
  random_copia = (float *)malloc(num_componentes * sizeof(float));

  for (j = 0; j < num_componentes; j++)
  {
    randomico = rand();
    valor_random = 1 + randomico % 10000;
    random[j] = valor_random;
    random_copia[j] = random[j];
  }

  printf("\n*********** Vetor randômico ***********\n\n");
  for (i = 0; i < num_componentes; i++)
  {
    printf("%.2f → ", random_copia[i]);
  }
  printf("\n");

  // ------ Ordenando os valores do vetor por SELECTION SORT ------
  printf("\n*********** Valores do vetor ordenado por SELECTION SORT ***********\n\n");
  int comparacoes, acessos;

  selecion_sort(random_copia, num_componentes, &comparacoes, &acessos);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes, acessos);


  // ------ Ordenando os valores do vetor por BUUBLE SORT ------
  printf("\n*********** Valores do vetor ordenado por BUBBLE SORT ***********\n\n");

  int comparacoes_bubble, acessos_bubble;

  bubble_sort(random_copia, num_componentes, &comparacoes_bubble, &acessos_bubble);  printf("Comparações: %d\nAcessos: %d\n", comparacoes_bubble, acessos_bubble);

  // ------ Ordenando os valores do vetor por INSERTION SORT ------
  printf("\n*********** Valores do vetor ordenado por INSERTION SORT ***********\n\n");

  int comparacoes_insertion, acessos_insertion;

  insertion_sort(random_copia, num_componentes, &comparacoes_insertion, &acessos_insertion);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_insertion, acessos_insertion);

  // ------ Ordenando os valoers do vetor por QUICK SORT ------
  printf("\n*********** Valores do vetor ordenado por QUICK SORT ***********\n\n");

  int comparacoes_quick = 0, acessos_quick = 0;

  quick_sort(random_copia, 0, num_componentes - 1, &comparacoes_quick, &acessos_quick);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_quick, acessos_quick);


  // ------ Ordenando os valores do vetor por MERGE SORT ------
  printf("\n*********** Valores do vetor ordenado por MERGE SORT ***********\n\n");

  int comparacoes_merge = 0, acessos_merge = 0;

  merge_sort(random_copia, 0, num_componentes - 1, &comparacoes_merge, &acessos_merge);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_merge, acessos_merge);


  // ------ Ordenando os valores do vetor por HEAP SORT ------
  printf("\n*********** Valores do vetor ordenado por HEAP SORT ***********\n\n");

  int comparacoes_heap = 0, acessos_heap = 0;

  heap_sort(random_copia, num_componentes, &comparacoes_heap, &acessos_heap);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_heap, acessos_heap);

  // ------ Ordenando os valores do vetor por RADIX SORT (LSD) ------
  printf("\n*********** Valores do vetor ordenado por RADIX SORT (LSD) ***********\n\n");

  int comparacoes_radix = 0, acessos_radix = 0;

  radix_sort(random_copia, num_componentes, &comparacoes_radix, &acessos_radix);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_radix, acessos_radix);


  // ------ Ordenando os valores do vetor por RADIX SORT (MSD) ------
  printf("\n*********** Valores do vetor ordenado por RADIX SORT (MSD) ***********\n\n");

  int comparacoes_radix_msd = 0, acessos_radix_msd = 0;

  radix_sort_msd(random_copia, num_componentes, &comparacoes_radix_msd, &acessos_radix_msd);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_radix_msd, acessos_radix_msd);


  // ------ Ordenando os valores do vetor por SHELL SORT ------
  printf("\n*********** Valores do vetor ordenado por SHELL SORT ***********\n\n");

  int comparacoes_shell = 0, acessos_shell = 0;

  shell_sort(random_copia, num_componentes, &comparacoes_shell, &acessos_shell);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_shell, acessos_shell);


  // ------ Ordenando os valores do vetor por BITONIC SORT ------
  printf("\n*********** Valores do vetor ordenado por BITONIC SORT ***********\n\n");

  int comparacoes_bitonic = 0, acessos_bitonic = 0;

  bitonic_sort(random_copia, num_componentes, &comparacoes_bitonic, &acessos_bitonic);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_bitonic, acessos_bitonic);


  // ------ Ordenando os valores do vetor por COCKTAIL SHAKER SORT ------
  printf("\n*********** Valores do vetor ordenado por COCKTAIL SHAKER SORT ***********\n\n");

  int comparacoes_cocktail = 0, acessos_cocktail = 0;

  cocktail_shaker_sort(random_copia, num_componentes, &comparacoes_cocktail, &acessos_cocktail);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_cocktail, acessos_cocktail);


  // ------ Ordenando os valores do vetor por GNOME SORT ------
  printf("\n*********** Valores do vetor ordenado por GNOME SORT ***********\n\n");

  int comparacoes_gnome = 0, acessos_gnome = 0;

  gnome_sort(random_copia, num_componentes, &comparacoes_gnome, &acessos_gnome);
  printf("Comparações: %d\nAcessos: %d\n", comparacoes_gnome, acessos_gnome);

  // ------ Imprimindo os valores do vetor ordenado ------
  printf("\n*********** Vetor ordenado ***********\n\n");
  for (i = 0; i < num_componentes; i++)
  {
    printf("%.2f → ", random_copia[i]);
  }


  // liberando o espaço de memória alocado
  free(random_copia);
  free(random);

  return 0;
}