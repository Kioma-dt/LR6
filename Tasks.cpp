#include <iostream>
#include "Functions.h"
#include "Tasks.h"

void Task_1(char * string) {
    std::cin.ignore(1000, '\n');
    std::cout << "In a string consisting of groups of zeros and ones separated by spaces, find the number of groups with five digits.\n";
    std::cout << "Maximum string length: 80\n";
    std::cout << "Enter a string of zeros and ones separated by spaces:\n";
    int size;
    size = EnterStringAndGetSize(string, 80);
    if (size == 81) {
        std::cout << "Wrong size of string!\n";
        return;
    }

    if (InCorrectString(string, size)) {
        std::cout << "Wrong characters of string!\n";
        return;
    }

    int total_groups = FindGroups(string, size);

    std::cout << "Entered string: \n";
    OutputString(string, size);
    std::cout << "Number of groups with five digits " << total_groups << '\n';
}

void Task_2(char * string) {
    std::cin.ignore(1000, '\n');
    std::cout << "Print a telegram receipt if the cost per word is known.\n";
    std::cout << "Maximum string length: 400\n";
    std::cout << "Enter telegram:\n";
    int size;
    size = EnterStringAndGetSize(string, 400);
    if (size == 401) {
        std::cout << "Wrong size of string!\\n";
        return;
    }

    unsigned int cost;
    std::cout << "Enter the cost of one word: ";
    cost = CheckUnsigned();

    int words = CountWords(string, size);

    int cost_of_telegram = words * cost;

    std::cout << "Telegram cost: " << cost_of_telegram << '\n';
}

void Task_3(char ** words) {
    std::cout << "Count the sum of the character codes of each word and, if the sum is even, mirror the word in the string.\n";
    std::cout << "Maximum number of words: 80\n";
    std::cout << "Maximum string length: 80\n";
    unsigned int n_words;
    std::cout << "Enter number of words: \n";
    n_words =  CheckUnsigned();
    if (n_words > 80) {
        std::cout << "Wrong number of words!\n";
        return;
    }

    int *size_of_word = new int[n_words];

    std::cout << "Enter words (one word per line):\n";
    for (int i = 0; i < n_words; i++) {
        size_of_word[i] = EnterStringAndGetSize(words[i], 80);
        if (size_of_word[i] == 81) {
            std::cout << "Wrong size of string!\n";
            return;
        }
    }

    int *codes = new int[n_words]();

    CountCodes(words, n_words, size_of_word, codes);

    for (int i = 0; i < n_words; i++) {
        if (codes[i] % 2 == 0) {
            ChangeWords(words[i], size_of_word[i]);
        }
    }

    std::cout << "Codes of words: \n";
    for (int i = 0; i < n_words; i++) {
        std::cout << codes[i] << ' ';
    }
    std::cout << "\nChanged words:\n";
    for (int i = 0; i < n_words; i++) {
        OutputString(words[i], size_of_word[i] - 1);
        std::cout << ' ';
    }
    std::cout << '\n';

    delete[] size_of_word;
    delete[] codes;
}