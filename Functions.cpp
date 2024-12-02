#include <iostream>

int main();


int EnterStringAndGetSize(char * string){
    int size = 1;
    string[size - 1] = getchar();
    while (string[size - 1]!='\n'){
        if (size == 80){
            return 81;
        }
        size++;
        string[size - 1] = getchar();
    }

    return size;
}

void OutputString(char * string, int size){
    for (int i = 0; i < size; i++){
        std::cout << string[i];
    }
}

int FindGroups(char * string, int size){
    int count_groups = 0, total_groups = 0;
    for (int i = 0; i < size; i++){
        if (string[i] == ' '){
            if (count_groups == 5){
                total_groups++;
            }
            count_groups = 0;
            continue;
        }
        count_groups++;
    }

    return total_groups;
}

bool InCorrectString(char * string, int size){
    for (int i = 0; i < size - 1;i++){
        if (string[i] != '1' && string[i] != '0' && string[i] != ' '){
            return true;
        }
    }

    return false;
}

int CountWords(char * string, int size){
    int words = 0;
    for (int i = 1; i < size;i++){
        if ((string[i]==' ' || string[i]=='\n')  && string[i-1]!=' '){
            words++;
        }
    }

    return words;
}

void CountCodes(char ** words, int n_words, int * size_of_word, int * codes){
    int code_word = 0;
    for (int i = 0; i < n_words;i++){
        for (int j = 0; j < size_of_word[i] - 1;j++){
            codes[i] += (int)words[i][j];
        }
        code_word = 0;
    }
}

void ChangeWords(char ** words, int n_words, int * size_of_word , int * codes){
    for (int i = 0; i < n_words;i++){
        if (codes[i] % 2 == 0){
            for (int j = 0; j < (size_of_word[i] - 1) / 2; j++){
                std::swap(words[i][j], words[i][(size_of_word[i] - 1) - j - 1]);
            }  
        }
    }
}

unsigned int CheckUnsigned() {
	unsigned int input;
	char next;

	while (true) {
		if (std::cin >> input) {
			std::cin.get(next);
			while (next == ' ') {
				std::cin.get(next);
			}

			if (next == '\n') {
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Неверный формат ввода! Необходими ввести целое неотрицательное число!\n";
	}

	return input;
}

void repeat(){
    std::cout << "Повторить решение?(y/n) ";
	char answer;
	std::cin >> answer;

	while (true) {
		if (answer == 'y') {
			std::cout << "----------------------\n";
			std::cin.ignore(10000, '\n');
			main();
			break;
		}
		else if (answer == 'n') {
			break;
		}
		else {
			std::cout << "Неверный символ!\n";
			std::cin.ignore(10000, '\n');
			std::cin >> answer;
		}
	}
}