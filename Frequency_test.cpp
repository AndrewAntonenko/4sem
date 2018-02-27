#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::string prepare(std::string &word);

bool comp(std::pair<std::string, int> lhs, std::pair<std::string, int> rhs);

int main(int argc, char *argv[]) {
    std::ifstream fInput(argv[2]);
    std::ofstream fOutput(argv[3]);
    std::string word;
    std::map<std::string, int> map;
    
    if (fInput.is_open() && fOutput.is_open()) {
        while (!fInput.eof()) {
            fInput >> word;
            word = prepare(word);
            map[word]++;
        }
    } else {
        std::cout << "fInput: " << fInput.is_open() << "\n";
        std::cout << "fOutput: " << fOutput.is_open() << "\n";
        perror("LOL");
        exit(EXIT_FAILURE);
    }

    std::vector<std::pair<std::string, int >> statistics;
    for (auto &item : map)
        statistics.emplace_back(item.first, item.second);

    std::sort(statistics.begin(), statistics.end(), comp);
    for (auto i : statistics)
        fOutput << i.first << " " << i.second << "\n";


    fInput.close();
    fOutput.close();
    return 0;
}

std::string prepare(std::string &word) {
    while ((!isalpha(*(word.end() - 1)) && !word.empty()))
        word.pop_back();

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

bool comp(const std::pair<std::string, int> lhs, const std::pair<std::string, int> rhs) {
    return lhs.second > rhs.second;
}