MAX_LENGTH  = 100
memoization = [[-1 for i in range(MAX_LENGTH)] for a in range(MAX_LENGTH)] 

string1 = input("Enter the first string : ")
string2 = input("Enter the second string : ")

def LCS(indexString1, indexString2):
   if indexString1 == len(string1) or indexString2 == len(string2):
      return ''
   
   if memoization[indexString1][indexString2] != -1:
      return memoization[indexString1][indexString2] 
   
   longestCommonSubsequence = None

   if string1[indexString1] == string2[indexString2]:
      longestCommonSubsequence = string1[indexString1] + LCS(indexString1+1, indexString2+1)
   
   else:
      longestCommonSubsequence = LCS(indexString1+1, indexString2)
      temp = LCS(indexString1, indexString2+1) 

      if len(temp) > len(longestCommonSubsequence):
         longestCommonSubsequence = temp
   
   memoization[indexString1][indexString2] = longestCommonSubsequence
   return longestCommonSubsequence

print( LCS(0,0) )