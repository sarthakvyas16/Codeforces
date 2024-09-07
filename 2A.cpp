// A. Winner
// time limit per test1 second
// memory limit per test64 megabytes
// The winner of the card game popular in 
//Berland "Berlogging" is determined according to the following rules. 
//If at the end of the game there is only one player with the maximum number
// of points, he is the winner. The situation becomes more difficult if the number of 
//such players is more than one. During each round a player gains or loses a particular
// number of points. In the course of the game the number of points is registered in the line 
//"name score", where name is a player's name, and score is the number of points gained in this
// round, which is an integer number. If score is negative, this means that the player has lost 
//in the round. So, if two or more players have the maximum number of points (say, it equals to m) at the end of 
//the game, than wins the one of them who scored at least m points first. Initially each player has 0 points. It's
// guaranteed that at the end 
//of the game at least one player has a positive number of points.

// Input
// The first line contains an integer number n (1  ≤  n  ≤  1000), n is the number 
//of rounds played. Then follow n lines, containing the information about the rounds in "name 
//score" format in chronological order, where name is a string of lower-case Latin letters with 
//the length from 1 to 32, and score is an integer number between -1000 and 1000, inclusive.

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
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();  // To ignore the newline after the integer input

    // Dictionary to store the total scores
    unordered_map<string, int> scores;
    // Dictionary to store the first time a player reaches a certain score
    unordered_map<string, int> first_reach;

    // Process each round
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        size_t space_pos = line.find(' ');
        string name = line.substr(0, space_pos);
        int score = stoi(line.substr(space_pos + 1));

        // Update the player's score
        if (scores.find(name) == scores.end()) {
            scores[name] = 0;
        }
        scores[name] += score;

        // Record the first time a player reaches the new score
        if (first_reach.find(name) == first_reach.end()) {
            first_reach[name] = scores[name];
        }
    }

    // Determine the maximum score
    int max_score = 0;
    for (const auto& entry : scores) {
        if (entry.second > max_score) {
            max_score = entry.second;
        }
    }

    // Find the winner by checking who reached the max score first
    string winner;
    int earliest_reach = n + 1; // Initialize with a value greater than any possible index

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        size_t space_pos = line.find(' ');
        string name = line.substr(0, space_pos);

        if (scores[name] == max_score) {
            if (first_reach[name] < earliest_reach) {
                earliest_reach = first_reach[name];
                winner = name;
            }
        }
    }

    // Output the winner
    cout << winner << endl;

    return 0;
}
