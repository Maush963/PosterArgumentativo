// =================================================================
//
// File: main.cpp
// Author: Mauricio Salas Hernández
// Date: 24/11/2023
//
// =================================================================

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

struct Contestant {
    int team;
    int solved;
    int penalty;
    map<int, int> incorrect;
    set<int> solvedSet;
};

// @Complexity	O(n)

int main() {
    vector<Contestant> teams(101);

    string line;
    // Receive team data and calculate results
    // Complexity O(n)
    while (getline(cin, line)) {
        istringstream ss(line);
        int teamNum, problem, time;
        char result;
        ss >> teamNum >> problem >> time >> result;

        Contestant& team = teams[teamNum];
        team.team = teamNum;
        if ((result == 'C' || result == 'I') && (result == 'C' && team.solvedSet.find(problem) == team.solvedSet.end())) {
            team.solved++;
            team.penalty += time + (20 * team.incorrect[problem]);
            team.solvedSet.insert(problem);
        } else if (result == 'I') {
            team.incorrect[problem]++;
        }
    }

    vector<Contestant> validTeams;

    // Complexity O(n)
    int i = 1;
    while (i < 101) {
        if (teams[i].solved > 0 || teams[i].penalty > 0) {
            validTeams.push_back(teams[i]);
        }
        i++;
    }

    // Add teams that registered but have no score or time
    // Complexity O(n)
    i = 1;
    while (i < 101) {
        if (teams[i].team == i && teams[i].solved == 0 && teams[i].penalty == 0) {
            validTeams.push_back(teams[i]);
        }
        i++;
    }

    // Sort teams according to the criteria
    // Complexity O(n log n)
    sort(validTeams.begin(), validTeams.end(),
        [](const Contestant& a, const Contestant& b) {
            if (a.solved == b.solved) {
                if (a.penalty == b.penalty) {
                    return a.team < b.team;
                }
                return a.penalty < b.penalty;
            }
            return a.solved > b.solved;
        }
    );

    // Print the sorted output
    for (const Contestant& team : validTeams) {
        cout << team.team << " " << team.solved << " " << team.penalty << endl;
    }

    return 0;
}
