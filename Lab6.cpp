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
        if (isalpha(ch)) {  // Keep only alphabetic characters
            cleanedWord += tolower(ch);  // Convert to lowercase
        }
    }
    return cleanedWord;
}

// Function to display word occurrences from the map
void displayWordOccurrences(const map<string, int>& wordCount) {
    cout << "Word Occurrences:\n";
    for (const auto& entry : wordCount) {
        cout << entry.first << " - " << entry.second << endl;
    }
}

// Function to find and display the longest word
void displayLongestWord(const string& longestWord) {
    cout << "\nLongest Word: " << longestWord << endl;
}

int main() {
    // Open input file
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
    string* wordArray = new string[capacity];  // Dynamic array to store words

    // Read file and process words
    string word;
    while (inputFile >> word) {
        string cleanedWord = preprocessWord(word);
        if (!cleanedWord.empty()) {
            words.push_back(cleanedWord);  // Store word in vector
            wordCount[cleanedWord]++;  // Update word count in map

            // Check for longest word
            if (cleanedWord.length() > longestLength) {
                longestLength = cleanedWord.length();
                longestWord = cleanedWord;
            }

            // Store words in dynamic array (resize if needed)
            if (wordCountDynamic >= capacity) {
                capacity *= 2;  // Double the capacity
                string* tempArray = new string[capacity];
                for (size_t i = 0; i < wordCountDynamic; i++) {
                    tempArray[i] = wordArray[i];
                }
                delete[] wordArray;  // Delete old array
                wordArray = tempArray;  // Assign new array
            }
            wordArray[wordCountDynamic++] = cleanedWord;  // Add word to dynamic array
        }
    }
    inputFile.close();

    // Output word occurrences and longest word
    displayWordOccurrences(wordCount);
    displayLongestWord(longestWord);

    // Cleanup dynamic array
    delete[] wordArray;

    return 0;
}
