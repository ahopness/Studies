def trocar(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def particionar(arr, min, max):
    pivo = arr[max]
    
    i = min-1
    for j in range(min, max):
        if arr[j] < pivo:
            i += 1
            trocar(arr, i, j)
    
    trocar(arr, i+1, max)
    return i+1

def quick_sort(arr, min, max):
    if min < max:
        pivo = particionar(arr, min, max)
        
        quick_sort(arr, min, pivo-1)
        quick_sort(arr, pivo+1, max)
