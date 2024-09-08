// A. Winner
// time limit per test1 second
// memory limit per test64 megabytes
// The winner of the card game popular in Berland "Berlogging" is determined according to the following rules. If at the end of the game there is only one player with the maximum number of points, he is the winner. The situation becomes more difficult if the number of such players is more than one. During each round a player gains or loses a particular number of points. In the course of the game the number of points is registered in the line "name score", where name is a player's name, and score is the number of points gained in this round, which is an integer number. If score is negative, this means that the player has lost in the round. So, if two or more players have the maximum number of points (say, it equals to m) at the end of the game, than wins the one of them who scored at least m points first. Initially each player has 0 points. It's guaranteed that at the end of the game at least one player has a positive number of points.

// Input
// The first line contains an integer number n (1  ≤  n  ≤  1000), n is the number of rounds played. Then follow n lines, containing the information about the rounds in "name score" format in chronological order, where name is a string of lower-case Latin letters with the length from 1 to 32, and score is an integer number between -1000 and 1000, inclusive.

// Output
// Print the name of the winner.

// Examples
// InputCopy
// 3
// mike 3
// andrew 5
// mike 2
// OutputCopy
// andrew
// InputCopy
// 3
// andrew 3
// andrew 2
// mike 5
// OutputCopy
// andrew
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> rounds(n);
    unordered_map<string, int> scores;

    // Reading the input and calculating scores
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        rounds[i] = {name, score};
        scores[name] += score;
    }

    // Determine the maximum score
    int maxScore = numeric_limits<int>::min();
    for (const auto& entry : scores) {
        if (entry.second > maxScore) {
            maxScore = entry.second;
        }
    }

    // Find all players with the maximum score
    unordered_map<string, bool> potentialWinners;
    for (const auto& entry : scores) {
        if (entry.second == maxScore) {
            potentialWinners[entry.first] = true;
        }
    }

    // Determine the first player to reach the maximum score
    unordered_map<string, int> currentScores;
    for (const auto& round : rounds) {
        const string& name = round.first;
        int score = round.second;
        currentScores[name] += score;

        // Check if this player has reached or exceeded the maximum score
        if (potentialWinners.find(name) != potentialWinners.end() && currentScores[name] >= maxScore) {
            cout << name << endl;
            return 0;
        }
    }

    return 0;
}
