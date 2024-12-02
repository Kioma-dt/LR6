#include <iostream>
#include "Functions.h"

void Task_1(char * string){
    std::cin.ignore(1000, '\n');
    std::cout << "В строке, состоящей из групп нулей и единиц, разделенных пробелами, найти количество групп с пятью цифрами.\n";
    std::cout << "Максимальная длина строки: 80\n";
    std::cout << "Введите строку из нулей и единиц, разделенных пробелами:\n";
    int size;
    size = EnterStringAndGetSize(string);
    if (size == 81){
        std::cout << "Неверный размер строки!\n";
        return;
    }

    if (InCorrectString(string, size)){
        std::cout << "Неверно введенная строка!\n";
        return;
    }

    int total_groups = FindGroups(string, size);

    std::cout << "Введенная строка: \n";
    OutputString(string, size);
    std::cout << "Количество групп с пятью цифрами: " << total_groups << '\n';
}

void Task_2(char * string){
    std::cin.ignore(1000, '\n');
    std::cout << "Напечатать квитанцию об оплате за телеграмму, если известна стоимость одного слова.\n";
    std::cout << "Максимальная длина строки: 80\n";
    std::cout << "Введите телеграмму:\n";
    int size;
    size = EnterStringAndGetSize(string);
    if (size == 81){
        std::cout << "Неверный размер строки!\n";
        return;
    }

    unsigned int cost;
    std::cout << "Введите цену одного слова: ";
    cost = CheckUnsigned();

    int words = CountWords(string, size);

    int cost_of_telegram = words * cost;

    std::cout << "Стоимость телеграммы: " << cost_of_telegram << '\n';
}

void Task_3(char ** words){
    std::cout << "Подсчитать сумму кодов символов каждого слова и, если сумма оказалась четной, развернуть зеркально это слово в строке.\n";
    std::cout << "Максимальное количество строк: 80\n";
    std::cout << "Максимальная длина строки: 80\n";
    unsigned int n_words;
    std::cout << "Введите количество строк: \n";
    n_words =  CheckUnsigned();
    if (n_words > 80){
        std::cout << "Неверное количество строк!\n";
        return;
    }

    int *size_of_word = new int[n_words];

    std::cout << "Введите строки по одной:\n";
    for (int i = 0; i < n_words;i++){
        size_of_word[i] = EnterStringAndGetSize(words[i]);
        if (size_of_word[i] == 81){
            std::cout << "Неверный размер строки!\n";
            return;
        }
    }

    int *codes = new int[n_words]();

    CountCodes(words, n_words, size_of_word, codes);
    ChangeWords(words, n_words, size_of_word, codes);

    std::cout << "Коды строк: \n";
    for (int i = 0; i < n_words; i++){
        std::cout << codes[i]<<' ';
    }
    std::cout << "\nПреобразованные строки:\n";
    for (int i = 0; i < n_words;i++){
        OutputString(words[i], size_of_word[i] - 1);
        std::cout << ' ';
    }
    std::cout << '\n';

    delete[] size_of_word;
    delete[] codes;
}