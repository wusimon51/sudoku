#include <iostream>
#include <fstream>


int main() {
    std::ofstream txtFile;
    txtFile.open("sudoku.txt");
    txtFile << "1";
    txtFile.close();
}