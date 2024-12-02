#include <iostream>
#include "Tasks.h"
#include "Functions.h"

int main(){
    std::cout << "Выполнил: Авраменко Роман Александрович\nГруппа: 453503\n";
    std::cout << "Вариант 1\n";
    int task;
    char **words = new char *[80];
    for (int i = 0; i < 80;i++){
        words[i] = new char[80];
    }
    char *string = new char[80];

    std::cout << "Выберите номер задания (1, 2 или 3): ";
    std::cin >> task;

    switch (task){
    case 1:
        Task_1(string);
        break;
    case 2:
        Task_2(string);
        break;
    case 3:
        Task_3(words);
        break;
    default:
        std::cout << "Невереный номер задания!\n";
    }

    for (int i = 0; i < 80;i++){
        delete[] words[i];
    }
    delete[] words;
    delete[] string;

    repeat();
}