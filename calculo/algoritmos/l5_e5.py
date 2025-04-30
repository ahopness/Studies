def buscaSequencialModificada(lista, chave):
  indices_encontrados = []
  for i in range(len(lista)): 
    if lista[i] == chave:
      indices_encontrados.append(i)
  return indices_encontrados


def buscaBinariaModificada(lista, chave):
  indices_encontrados = []
  inicio = 0
  fim = len(lista) - 1
  indice_achado_inicial = -1

  while inicio <= fim:
    meio = (inicio + fim) // 2
    if lista[meio] == chave:
      indice_achado_inicial = meio
      break 
    elif lista[meio] < chave:
      inicio = meio + 1
    else:
      fim = meio - 1

  if indice_achado_inicial == -1:
    return []

  indices_encontrados.append(indice_achado_inicial)

  temp_i = indice_achado_inicial - 1
  while temp_i >= 0 and lista[temp_i] == chave:
    indices_encontrados.append(temp_i)
    temp_i -= 1

  temp_i = indice_achado_inicial + 1
  while temp_i < len(lista) and lista[temp_i] == chave:
    indices_encontrados.append(temp_i)
    temp_i += 1

  return indices_encontrados