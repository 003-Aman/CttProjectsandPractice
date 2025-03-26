#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

// Function to preprocess text: remove punctuation and convert to lowercase
string preprocessWord(const string& word) {
    string cleanedWord;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleanedWord += tolower(ch);
        }
    }
    return cleanedWord;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    // Variables
    vector<string> words;  // Stores unique words
    map<string, int> wordCount;  // Maps words to occurrences
    string longestWord = "";
    size_t longestLength = 0;

    // Dynamic Array for word storage
    size_t capacity = 10;
    size_t wordCountDynamic = 0;
    string* wordArray = new string[capacity];

    // Read file and process words
    string word;
    while (inputFile >> word) {
        string cleanedWord = preprocessWord(word);
        if (!cleanedWord.empty()) {
            words.push_back(cleanedWord);
            wordCount[cleanedWord]++;

            // Check for longest word
            if (cleanedWord.length() > longestLength) {
                longestLength = cleanedWord.length();
                longestWord = cleanedWord;
            }

            // Store words in dynamic array (resize if needed)
            if (wordCountDynamic >= capacity) {
                capacity *= 2;
                string* tempArray = new string[capacity];
                for (size_t i = 0; i < wordCountDynamic; i++) {
                    tempArray[i] = wordArray[i];
                }
                delete[] wordArray;
                wordArray = tempArray;
            }
            wordArray[wordCountDynamic++] = cleanedWord;
        }
    }
    inputFile.close();

    // Output word occurrences
    cout << "Word Occurrences:\n";
    for (const auto& entry : wordCount) {
        cout << entry.first << " - " << entry.second << endl;
    }

    // Output longest word
    cout << "\nLongest Word: " << longestWord << endl;

    // Cleanup dynamic array
    delete[] wordArray;

    return 0;
}
