#include <iostream>
#include <fstream>

int main() {
    //vars
    const int MIN = 0;
    const int MAX = 9;
    const std::string INT_TABLE_1 = "numbers1.txt";
    const std::string INT_TABLE_2 = "numbers2.txt";
    std::string fileName;
    int userNum;
    int num;
    int countTotalInt = 0;
    int countFound = 0;
    int sumOfAll = 0;
    int sumOfEnd = 0;
    std::ifstream inFile;

    std::cout << "This program will search a file for your number and provide some statistics on the numbers "
                 "in the file" << std::endl;

    std::cout << "Enter the name of the file you wish to search (numbers1.txt OR numbers2.txt): ";
    std::cin >> fileName;
    while(fileName != INT_TABLE_1 && fileName != INT_TABLE_2 ){
        std::cout << "Invalid file name. Please try again." << std::endl;
        std::cout << "Enter the name of the file you wish to search (numbers1.txt OR numbers2.txt): ";
        std::cin >> fileName;
    }
    inFile.open(fileName);

    std::cout << "Enter the integer that you wish to search for (0 to 9): ";
    std::cin >> userNum;
    std::cout << std::endl;
    while(userNum > MAX || userNum < MIN || std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(50, '\n');
        std::cout << "You must enter an integer (whole number) from 0 to 9. Please try again." << std::endl;
        std::cout << "Enter the integer that you wish to search for (0 to 9): ";
        std::cin >> userNum;
    }

    while(inFile >> num) {
        countTotalInt++;
        if (num == userNum) {
            countFound++;
        }
        if(countTotalInt%10 == 0){
            sumOfEnd += num;
        }
        sumOfAll += num;
    }

    std::cout << "There are " << countTotalInt << " integers in the file, organized into " << countTotalInt/10 <<
              " rows\n";
    std::cout << "The sum of all integers in the file: " << sumOfAll << std::endl;
    std::cout << "The sum of the integers located at the end of each row: " << sumOfEnd << std::endl;
    std::cout << "Your number was found " << countFound << " times" << std::endl;
    if(num == userNum){
        std::cout << "Fun fact: Your integer was the last number in the file!" << std::endl;
    } else {
        std::cout << "The number " << num << " was the last number in the file";
    }
    return 0;
}
