// =========================================================
// File: main.cpp
// Author: Mauricio Salas Hernández - A01710309
// Date: 03/11/2023
// =========================================================

#include <iostream>
#include <map>
#include <vector>

using namespace std;
//Complexity for this algorithm is O(n^3)

int main(){
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n-1; i++) {
        cin >> list[i];
    }
    //now we make a map "mp" of "n" elements, with int keys and vector<int> values
    map<int, vector<int>> mp;
    //now we go through the array "list" and add the values to the map "mp".
    //depending on the value of the key, the values are added to the vector
    for (int i = 0; i < n-1; i++) {
        mp[list[i]].push_back(i+2);
    }
    
    //now we go through the map from the bottom to the top and check if the vector has any elements
    //if it has them, we delete the number that is equal to the key of the map that we are traversing
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        //if the vector is not empty
        if (!it->second.empty()) {
            //we do two fors that goes through the whole map and deletes the number of the vector that is equal to the key
            for (auto it2 = mp.begin(); it2 != mp.end(); it2++) {
                for (int i = 0; i < it2->second.size(); i++) {
                    //if the number of the vector is equal to the key, we delete it
                    if (it2->second[i] == it->first) {
                        it2->second.erase(it2->second.begin() + i);
                    }
                }
            }
        }
    }

    //now we go through the map, if there are keys in the vector with less than 3 elements, we print "NO", otherwise we print "YES".
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second.size() < 3) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}