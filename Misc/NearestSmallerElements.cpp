/*
Made by Gainsborow
Github : https://github.com/Gainsboroow/

Enter the number of elements in your array.
Enter the elements.
This algorithm displays the nearest previous element that 
is before the current element of the array.

Input example:
8
1 3 4 2 5 3 4 2

Output example: (Index -1 : This means that there is no smaller element)
The nearest smaller element of 1 (index 0) is -2147483647 (index -1) 
The nearest smaller element of 3 (index 1) is 1 (index 0)
The nearest smaller element of 4 (index 2) is 3 (index 1)
The nearest smaller element of 2 (index 3) is 1 (index 0)
The nearest smaller element of 5 (index 4) is 2 (index 3)
The nearest smaller element of 3 (index 5) is 2 (index 3)
The nearest smaller element of 4 (index 6) is 3 (index 5)
The nearest smaller element of 2 (index 7) is 2 (index 3)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> elements;
vector<pair<int,int>> nearestSmaller;

deque<pair<int,int>> smallerElements;

int main(){
    int numberOfElements;
    cin >> numberOfElements;

    for (int i = 0; i < numberOfElements; i++){
        int elem; cin >> elem;
        elements.push_back(elem);
    }

    smallerElements.push_back({-__INT_MAX__, -1});

    for (int i = 0; i < numberOfElements; i++){
        int currentElement = elements[i];
        while (currentElement < smallerElements.back().first){
            smallerElements.pop_back();
        }
        nearestSmaller.push_back(smallerElements.back());
        smallerElements.push_back({currentElement, i});
    }

    for (int i = 0; i < numberOfElements; i++){
        cout << "The nearest smaller element of " << elements[i] << " (index " << i << ") is " 
             << nearestSmaller[i].first << " (index " << nearestSmaller[i].second << ")\n";
    }
    
}