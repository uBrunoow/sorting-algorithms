// Função para obter o maior valor no array
int getMax(float arr[], int n)
{
  float max = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

// Função para fazer o Counting Sort de acordo com o dígito representado por exp
void countingSort(float arr[], int n, int exp, int *comparacoes, int *acessos)
{
  float output[n]; // Array de saída
  int count[10] = {0};

  // Armazena a contagem de ocorrências em count[]
  for (int i = 0; i < n; i++)
  {
    int digit = ((int)arr[i] / exp) % 10;
    count[digit]++;
    (*acessos)++;
  }

  // Muda count[i] para que count[i] contenha a posição atual deste dígito em output[]
  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
    (*acessos)++;
  }

  // Constrói o array de saída
  for (int i = n - 1; i >= 0; i--)
  {
    int digit = ((int)arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
    (*acessos) += 3; // Acessos para leitura e escrita
  }

  // Copia o array de saída para arr[], para que arr[] contenha os números ordenados de acordo com o dígito atual
  for (int i = 0; i < n; i++)
  {
    arr[i] = output[i];
    (*acessos)++;
  }
}

// Função principal do Radix Sort
void radix_sort(float arr[], int n, int *comparacoes, int *acessos)
{
  // Encontra o maior número para saber o número de dígitos
  int m = getMax(arr, n);

  // Faz o Counting Sort para cada dígito. Note que exp é 10^i onde i é o dígito atual
  for (int exp = 1; m / exp > 0; exp *= 10)
  {
    countingSort(arr, n, exp, comparacoes, acessos);
  }
}