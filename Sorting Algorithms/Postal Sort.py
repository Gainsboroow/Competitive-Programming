MAX_POSSIBLE_VALUE = 10**6

count = [0]*MAX_POSSIBLE_VALUE

nb = list(map(int, input().split()))

print("Starting array :", *nb)
for value in nb:
   count[value] += 1

sortedArray = []

for index in range(MAX_POSSIBLE_VALUE):
   while count[index]:
      sortedArray.append(index)
      count[index] -= 1

print("Sorted array :", *sortedArray)