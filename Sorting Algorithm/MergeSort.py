def merge(tab, inf, middle, sup):
   indexTab1 = indexTab2 = 0
   tab1 = tab[inf:middle+1] + [float("inf")]
   tab2 = tab[middle+1: sup+1] + [float("inf")]

   for delta in range(sup - inf + 1):
      if tab1[indexTab1] <= tab2[indexTab2]:
         tab[inf + delta] = tab1[indexTab1]
         indexTab1 += 1
      
      else:
         tab[inf + delta] = tab2[indexTab2]
         indexTab2 += 1
         

def mergeSort(tab, inf, sup):
   if inf < sup:
      middle = (inf + sup) // 2
      mergeSort(tab, inf, middle)
      mergeSort(tab, middle + 1, sup)
      merge(tab, inf, middle, sup)


nb = list(map(int, input().split()))

print("Starting array :", *nb)
mergeSort(nb, 0, len(nb)-1)
print("Sorted array :", *nb)