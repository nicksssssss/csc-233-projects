#include <string>
#include <iostream>
#include <time.h>

bool isLetterInArr(char letter, char arr[], int arrSize);

int main(){
    std::string words[5] = {"helloworld", "omg", "this", "plzgivemeagoodgrade"};
    srand(time(NULL));
        int amountGuessed,charIndex;
        char guessed[30];
        char guess, answer;

    while(true) {

        int index = rand() % 4;
        std::string wordToGuess = words[index];
        std::string guessedWord = std::string(words[index].size(), '*');

        amountGuessed = 0;

        while (guessedWord.find('*') != std::string::npos)
        {
            std::cout << "(guess) Enter a letter in the word " << guessedWord << std::endl;
            std::cin >> guess;
            if(isLetterInArr(guess, guessed, amountGuessed)) {
                std::cout << "You guessed " << guess << " already" << std::endl;
            } else {
                guessed[amountGuessed] = guess;
                amountGuessed++;
                if (wordToGuess.find(guess) != std::string::npos){
                    while(wordToGuess.find(guess) != std::string::npos){
                        charIndex = wordToGuess.find(guess);
                        wordToGuess[charIndex] = '*';
                        guessedWord[charIndex] = guess;
                    }
                } else {
                    std::cout << guess << " is not in the word" << std::endl;
                }
            }
        }
        

        std::cout << "The word is " << guessedWord << ". You missed " << amountGuessed - guessedWord.length() << " time(s)" << std::endl;
        std::cout << "Do you want to guess another word? Enter y or no: " << std::endl;
        std::cin >> answer;
        if (answer != 'y') {
            break;
        }
    }    
    return 0;
}

bool isLetterInArr(char letter, char arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++){
        if(letter == arr[i]) return true;
    }
    return false;
}