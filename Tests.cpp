#include <gtest/gtest.h>
#include "Functions.h"

TEST(Task_1, Regular_Test_1) {
    const int size = 10;
    char string[size + 1] = "10010 101\n";

    EXPECT_EQ(FindGroups(string, size), 1);
}

TEST(Task_1, Regular_Test_2) {
    const int size = 8;
    char string[size + 1] = "100 001\n";

    EXPECT_EQ(FindGroups(string, size), 0);
}

TEST(Task_1, Regular_Test_3) {
    const int size = 34;
    char string[size + 1] = "10000110 00110   1000     10100  \n";

    EXPECT_EQ(FindGroups(string, size), 2);
}

TEST(Task_1, Regular_Test_4) {
    const int size = 38;
    char string[size + 1] = "1000110 10101 0 110000 1110     01011\n";

    EXPECT_EQ(FindGroups(string, size), 2);
}

TEST(Task_1, Regular_Test_5) {
    const int size = 37;
    char string[size + 1] = "100 0101 100 001 0100 000 110 101 00\n";

    EXPECT_EQ(FindGroups(string, size), 0);
}

TEST(Task_1, Regular_Test_6) {
    const int size = 26;
    char string[size + 1] = "0000000000000000000000000\n";

    EXPECT_EQ(FindGroups(string, size), 0);
}

TEST(Task_1, Regular_Test_7) {
    const int size = 24;
    char string[size + 1] = "11111 11111 11111 11111\n";

    EXPECT_EQ(FindGroups(string, size), 4);
}

TEST(Task_1, Regular_Test_8) {
    const int size = 34;
    char string[size + 1] = "10100 111010101 10010 1 11000 001\n";

    EXPECT_EQ(FindGroups(string, size), 3);
}

TEST(Task_1, Empty_String) {
    const int size = 1;
    char string[size + 1] = "\n";

    EXPECT_EQ(FindGroups(string, size), 0);
}

TEST(Task_1, Only_Spaces) {
    const int size = 18;
    char string[size + 1] = "                 \n";

    EXPECT_EQ(FindGroups(string, size), 0);
}


TEST(Task_2, Regular_Test_1) {
    const int size = 15;
    char string[size + 1] = "Hello, World!\n";
    int cost = 1;

    EXPECT_EQ(CountWords(string, size) * cost, 2);
}

TEST(Task_2, Regular_Test_2) {
    const int size = 12;
    char string[size + 1] = "Privet,vse!\n";
    int cost = 1;

    EXPECT_EQ(CountWords(string, size) * cost, 1);
}

TEST(Task_2, Regular_Test_3) {
    const int size = 75;
    char string[size + 1] = "Computer science is the study of computation, information, and automation.\n";
    int cost = 1;

    EXPECT_EQ(CountWords(string, size) * cost, 10);
}

TEST(Task_2, Regular_Test_4) {
    const int size = 182;
    char string[size + 1] = "Mathematics is a field of study that discovers and organizes methods, theories and theorems that are developed and proved for the needs of empirical sciences and mathematics itself.\n";
    int cost = 4;

    EXPECT_EQ(CountWords(string, size) * cost, 112);
}

TEST(Task_2, Regular_Test_5) {
    const int size = 236;
    char string[size + 1] = "Contests are partitioned geographically into ICPC Regions, and every degree-granting team institution is assigned a home ICPC Region, which determines the only advancement path available for all teams having the same team institution.\n";
    int cost = 4057;

    EXPECT_EQ(CountWords(string, size) * cost, 133881);
}

TEST(Task_2, Regular_Test_6) {
    const int size = 229;
    char string[size + 1] = "In 1979, Bjarne Stroustrup, a Danish computer scientist, began work on C with Classes, the predecessor to C++. The motivation for creating a new language originated from Stroustrup's experience in programming for his PhD thesis.\n";
    int cost = 0;

    EXPECT_EQ(CountWords(string, size) * cost, 0);
}

TEST(Task_2, Regular_Test_7) {
    const int size = 293;
    char string[size + 1] = "International seminars and conferences are held at the university on the regular basis. In 1997, the seminar Management of Higher Educational Institutions was held. Two German universities (the Higher Technical School of Mittweide and the University of Wuppertal) participated in the seminar.\n";
    int cost = 1;

    EXPECT_EQ(CountWords(string, size) * cost, 42);
}

TEST(Task_2, Big_Cost) {
    const int size = 102;
    char string[size + 1] = "void OutputString(char * string, int size){ for (int i = 0; i < size; i++){ std::cout << string[i]; }\n";
    int cost = 12345678;

    EXPECT_EQ(CountWords(string, size) * cost, 234567882);
}

TEST(Task_2, Empty_String) {
    const int size = 1;
    char string[size + 1] = "\n";
    int cost = 50;

    EXPECT_EQ(CountWords(string, size) * cost, 0);
}

TEST(Task_2, Only_Spaces) {
    const int size = 20;
    char string[size + 1] = "                   \n";
    int cost = 46;

    EXPECT_EQ(CountWords(string, size) * cost, 0);
}

TEST(Task_3, Test_Of_Codes_1) {
    const int n_words = 3;
    int size_of_words[n_words] = {4, 4, 4};
    int codes[n_words] = {};
    char *words[] = {(char *)"AAA\n", (char *)"BBB\n", (char *)"CCC\n"};

    int actual_codes[n_words] = {195, 198, 201};

    CountCodes((char**)words, n_words, size_of_words, codes);

    for (int i = 0; i < n_words; i++) {
        EXPECT_EQ(codes[i], actual_codes[i]);
    }
}

TEST(Task_3, Test_Of_Codes_2) {
    const int n_words = 3;
    int size_of_words[n_words] = {6, 6, 4};
    int codes[n_words] = {};
    char *words[] = {(char *)"Hfa.g\n", (char *)"usala\n", (char *)"khd\n"};

    int actual_codes[n_words] = {420, 534, 311};

    CountCodes((char**)words, n_words, size_of_words, codes);

    for (int i = 0; i < n_words; i++) {
        EXPECT_EQ(codes[i], actual_codes[i]);
    }
}

TEST(Task_3, Test_Of_Codes_3) {
    const int n_words = 0;
    int size_of_words[n_words] = {};
    int codes[n_words] = {};
    char *words[] = {};
    
    int actual_codes[n_words] = {};

    CountCodes((char**)words, n_words, size_of_words, codes);

    for (int i = 0; i < n_words; i++) {
        EXPECT_EQ(codes[i], actual_codes[i]);
    }
}

TEST(Task_3, Test_Of_Codes_4) {
    const int n_words = 2;
    int size_of_words[n_words] = {1, 1};
    int codes[n_words] = {};
    char *words[] = {(char *)"\n", (char *)"\n"};

    int actual_codes[n_words] = {0, 0};

    CountCodes((char**)words, n_words, size_of_words, codes);

    for (int i = 0; i < n_words; i++) {
        EXPECT_EQ(codes[i], actual_codes[i]);
    }
}

TEST(Task_3, Test_Of_Codes_5) {
    const int n_words = 5;
    int size_of_words[n_words] = {10, 3, 5, 7, 5};
    int codes[n_words] = {};
    char *words[] = {(char *)"         \n", (char *)"\t6\n", (char *)"GO0L\n", (char *)"eeeboy\n", (char *)"kuku\n"};
    
    int actual_codes[n_words] = {288, 63, 274, 633, 448};

    CountCodes((char**)words, n_words, size_of_words, codes);

    for (int i = 0; i < n_words; i++) {
        EXPECT_EQ(codes[i], actual_codes[i]);
    }
}

TEST(Task_3, Test_Of_Change_1) {
    const int size = 6;
    char string[size + 1] = "HeaPi\n";
    ChangeWords(string, size);
    char actual_string[size] = "iPaeH";

    for (int i = 0; i < size - 1; i++) {
        EXPECT_EQ(string[i], actual_string[i]);
    }
}

TEST(Task_3, Test_Of_Change_2) {
    const int size = 6;
    char string[size + 1] = "Aboba\n";
    ChangeWords(string, size);
    char actual_string[size] = "abobA";

    for (int i = 0; i < size - 1; i++) {
        EXPECT_EQ(string[i], actual_string[i]);
    }
}

TEST(Task_3, Test_Of_Change_3) {
    const int size = 7;
    char string[size + 1] = "  \t228\n";
    ChangeWords(string, size);
    char actual_string[size] = "822\t  ";

    for (int i = 0; i < size - 1; i++) {
        EXPECT_EQ(string[i], actual_string[i]);
    }
}

TEST(Task_3, Test_Of_Change_4) {
    const int size = 1;
    char string[size + 1] = "\n";
    ChangeWords(string, size);
    char actual_string[size];

    for (int i = 0; i < size - 1; i++) {
        EXPECT_EQ(string[i], actual_string[i]);
    }
}

TEST(Task_3, Test_Of_Change_5) {
    const int size = 15;
    char string[size + 1] = "DLfm;aas;++'fd\n";
    ChangeWords(string, size);
    char actual_string[size] = "df'++;saa;mfLD";

    for (int i = 0; i < size - 1; i++) {
        EXPECT_EQ(string[i], actual_string[i]);
    }
}