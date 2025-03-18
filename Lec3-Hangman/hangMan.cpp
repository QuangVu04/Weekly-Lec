#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 

using namespace std;

string WORD_LIST[] = {
    "angle", "ant", "apple", "arch", "arm", "army",
    "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
    "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
    "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
    "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
    "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
    "cow", "cup", "curtain", "cushion",
    "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
    "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
    "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
    "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
    "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
    "leaf", "leg", "library", "line", "lip", "lock",
    "map", "match", "monkey", "moon", "mouth", "muscle",
    "nail", "neck", "needle", "nerve", "net", "nose", "nut",
    "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
    "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
    "rail", "rat", "receipt", "ring", "rod", "roof", "root",
    "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
    "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
    "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
    "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
    "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
    "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

string chooseWord() {
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
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

    string word = chooseWord();
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
