#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const char DATA_FILE[] ="wordlist.txt";

string toLowerCase(const string& s)
{
string res = s;
int sz = s.size();
for (int i = 0; i < sz; i++)
res[i] = tolower(s[i]);
return res;
}

string chooseWord(const char* fileName)
{
    vector<string> wordList;
    ifstream file(fileName); //Mở tệp có đường dẫn như trong tham số
    if (file.is_open()) { // Kiểm tra tệp mở thành công
    string word;
    while (file >> word) { //Đọc từng từ đến khi không đọc được nữa
        wordList.push_back(word);
    }
file.close();
} else cout << "Error opening " << fileName;
if (wordList.size() > 0) { // nếu có dữ liệu đọc thành công
    int randomIndex = rand() % wordList.size();
    return toLowerCase(wordList[randomIndex]);

    } else return ""; 
}


const string FIGURE[] = {
    " ------------- \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | /| \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | /|\\ \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | /|\\ \n"
    " | / \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " | | \n"
    " | O \n"
    " | /|\\ \n"
    " | / \\ \n"
    " | \n"
    " ----- \n",
};

void renderGame(const string& guessedWord, int badGuessCount) {
    cout << FIGURE[badGuessCount] << endl;
    cout << "Word: " << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

string createGuessString(const string& word) {
    return string(word.length(), '-');
}

int main() {
    srand(time(0));

    string word = chooseWord(DATA_FILE);
    string guess = createGuessString(word);
    char letter;
    int tries = 0;
    bool won = false;

    while (tries < 7 && !won) {
        cout << "Enter a letter: ";
        cin >> letter;

        bool found = false;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guess[i] = letter;
                found = true;
            }
        }

        if (!found) {
            tries++;
        }

        renderGame(guess, tries);

        if (guess == word) {
            won = true;
        }
    }

    if (won) {
        cout << "You won! The word was: " << word << endl;
    } else {
        cout << "You lost! The word was: " << word << endl;
    }

    return 0;
}
