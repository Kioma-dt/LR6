#include <iostream>
#include <gtest/gtest.h>
#include "Tasks.h"
#include "Functions.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Performed by: Avramenko Roman Aleksandrovich\n";
    std::cout << "Group: 453503\n";
    std::cout << "Variant 1\n";
    int task;
    char *string_1 = new char[80];
    char *string_2 = new char[400];
    char **words = new char *[80];
    for (int i = 0; i < 80; i++) {
        words[i] = new char[80];
    }

    std::cout << "Choose option:\n1 - Task_1\n2 - Task_2\n3 - Task_3\n4 - Run Googletests\n5 - Exit program\n";
    std::cin >> task;

    switch (task) {
    case 1:
        Task_1(string_1);
        break;
    case 2:
        Task_2(string_2);
        break;
    case 3:
        Task_3(words);
        break;
    case 4:
        RUN_ALL_TESTS();
        break;
    case 5:
        break;
    default:
        std::cout << "Wrong number!\n";
    }

    delete[] string_1;
    delete[] string_2;
    for (int i = 0; i < 80; i++) {
        delete[] words[i];
    }
    delete[] words;

    repeat();
}