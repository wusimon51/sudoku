#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

#include "Node.h"


struct Column : public Node {
    int size;
    std::string name;
    Column(int size, std::string name) : size(size), name(std::move(name)) {};
};

int main() {
    std::ifstream txtFile;
    txtFile.open("sudoku.txt");
    std::string line;
    std::vector<std::vector<char>> grid;
    while (std::getline(txtFile, line)) {
        std::vector<char> row;
        for (char number : line) {
            if (number != ',') row.push_back(number);
        }
        grid.push_back(row);
    }
    txtFile.close();

    //initial 729x324 matrix
    Node root;
    Column start(0, "0");
    start.addLeft(&root);
    root.addRight(&start);

    for (int col = 0; col < 324; col++) {

    }

}