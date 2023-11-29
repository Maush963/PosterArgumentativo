// =========================================================
// File: main.cpp
// Author: Mauricio Salas Hernández - A01710309
// Date: 09/11/2023
// =========================================================

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

//Complexity for this algorithm is O(n^3)

using namespace std;

void DFS_on_map(string str, map<string, vector<string>>& mp, vector<string>& visited_nodes) {
    if (str.empty()) return;
    string current_node = str.substr(0, 1);

    //we check if the current node has already been visited
    if (find(visited_nodes.begin(), visited_nodes.end(), current_node) == visited_nodes.end()) {
        visited_nodes.push_back(current_node);

        // Check if the current node value is present in any other node's neighbors list
        for (auto& pair : mp) {
            if (find(pair.second.begin(), pair.second.end(), current_node) != pair.second.end()) {
                // If found, perform the DFS operation on that node
                DFS_on_map(pair.first, mp, visited_nodes);
            }
        }
        //we call the function recursively for the neighbors of the current node
        for (auto& neighbor : mp[current_node]) {
            DFS_on_map(neighbor, mp, visited_nodes);
        }
    }
}

string erase_visited_nodes(string str, vector<string>& visited_nodes) {
//We compare with the string with the visited nodes, we remove the nodes that have already been visited 
    //We repeat the process until we have no more nodes to visit
    for (int i = 0; i < str.size(); i++) {
        if (find(visited_nodes.begin(), visited_nodes.end(), str.substr(i, 1)) != visited_nodes.end()) {
            str.erase(i, 2);
            i--;
        }
    }
    return str;
}

int main() {
    // We create a map with string keys and vector<string> values
    map<string, vector<string>> mp;
    // We create the keys for the map, which are the letters of the alphabet (A-Z)
    string keys = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // We fill the map with the keys and empty vectors
    for (int i = 0; i < keys.size(); i++) {
        mp[keys.substr(i, 1)] = {};
    }

    string input;
    // The user can input as long as they don't input "****" which will break the cycle
    while (true) {
        cout << "Enter data in the format (A,B): ";
        cin >> input;
        
        if (input == "****") {
            break;
        }
        // We asign the values to the key and value variables from their corresponding indexes in the input string
        string key = input.substr(1, 1);
        string value = input.substr(3, 1);

        // We add the value to the key in the map, only if it's not already in the map
        if (find(mp[key].begin(), mp[key].end(), value) == mp[key].end()) {
            mp[key].push_back(value);
        } 
    }

    string str; 
    cin >> str; 

    vector<string> visited_nodes;
    int tree = 0;
    int acorn = 0;

    //we call the function to erase the visited nodes and the DFS_on_map until str is empty
    while (!str.empty()) {
        DFS_on_map(str, mp, visited_nodes);
        str = erase_visited_nodes(str, visited_nodes);
        
        //we check if the visited nodes are more than 1, if they are, we add 1 to the tree variable, otherwise we add 1 to the acorn variable
        if (visited_nodes.size() > 1) {
            tree++;
        }
        else {
            acorn++;
        }
        
        visited_nodes.clear();
    }
    // we print the number of trees and acorns
    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;

    //The program will end and display the BFS traversal
    return 0;
}