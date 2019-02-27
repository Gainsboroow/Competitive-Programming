MAX_LENGTH  = 100
memoization = [[-1 for i in range(MAX_LENGTH)] for a in range(MAX_LENGTH)] 

for i in range(MAX_LENGTH):
   memoization[0][i] = i
   memoization[i][0] = i

string1 = ' ' + input("Enter the first string : ")
string2 = ' ' + input("Enter the second string : ")

def Levenshtein(indexString1, indexString2):
   if memoization[indexString1][indexString2] != -1:
      return memoization[indexString1][indexString2] 
   
   cost = string1[indexString1] != string2[indexString2]

   distance = min(1 + Levenshtein(indexString1-1, indexString2), 
                  1 + Levenshtein(indexString1, indexString2-1),
                  Levenshtein(indexString1-1, indexString2-1) + cost)

   memoization[indexString1][indexString2] = distance
   return distance

print( Levenshtein(len(string1)-1, len(string2)-1) )