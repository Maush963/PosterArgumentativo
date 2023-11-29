// =================================================================
//
// File: act2.3
// Author: Brisa Reyes
// Date: 10 OCT 2023
//
// =================================================================

//=================================================================
// Find the mathematically safe starting position.
// 
// @param n The number of people in the circle.
// @param survivor The position of the found survivor.
// @return The position to start counting from for the survivor to survive.
// Complexity: O(1)
//=================================================================
#include <iostream>
#include <list>

using namespace std;

int find_safe_position(int n, int survivor) {
    if (survivor == 1) {
        return 1;
    }
    else {
        return n - survivor + 2;
    }
}

int main(int argc, char* argv[]) {
    int n, k;
    cin >> n >> k;
    
    // Initialize the list
    list<int> death_circle;
    int i = 1;
    while (i <= n) {
        death_circle.push_back(i);
        i++;
    }

    // Initialize iterators
    list<int>::iterator it = death_circle.begin();
    list<int>::iterator itK = it;

    // Main elimination loop
    while (death_circle.size() > 1) {
        int i = 1;
        while (i < k) {
            it++;
            if (it == death_circle.end()) {
                it = death_circle.begin();
            }
            i++;
        }

        it = death_circle.erase(it);
        if (it == death_circle.end()) {
            it = death_circle.begin();
        }

        itK = it;

        int j = 0;
        while (j < k - 1) {
            it++;
            if (it == death_circle.end()) {
                it = death_circle.begin();
            }
            j++;
        }

        itK = death_circle.emplace(itK, *it);
        death_circle.erase(it);
        it = itK;
        it++;
    }

    int safe_position = find_safe_position(n, death_circle.front());
    cout << safe_position << endl;

    return 0;
}
