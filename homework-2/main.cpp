#include <iostream>
#include <fstream>
#include <sstream>
#include "Show.hpp"

using namespace std;

int main() {
    freopen("main.out", "w+", stdout);
    vector<Show> shows;
    ifstream file("netflix_titles.csv");
    string header;
    getline(file, header);
    int cols = 1;
    for (int i = 0; i < (int) header.size(); i++)
        if (header[i] == ';')
            cols++;
    while (!file.eof()) {
        Show s;
        for (int i = 0; i < cols; i++) {
            string input = "teste";
            // if (i == cols - 1)
            //     getline(file, input, '\n');
            // else
            //     getline(file, input, ';');
            if (i == CAST || i == LISTED_IN) {
                // vector<string> inputs;
                // stringstream ss(input);
                // while (getline(ss, input, ','))
                //     inputs.push_back(input);
                // s.set(i, inputs);
                continue;
            }
            s.set<int>(i, 1);
        }
        // shows.push_back(s);
        return 0;
    }
    // for (auto i : shows)
    //     cout << i.getShowId() << endl;
}