#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <regex>

using namespace std;

// Function to check if a word is exactly three letters long
bool isThreeLetterWord(const string &word) {
    return word.length() == 3 && isalpha(word[0]) && isalpha(word[1]) && isalpha(word[2]);
}

// Function to process and replace three-letter words while keeping punctuation
string processText(const string &text) {
    string result;
    regex wordPattern(R"(\b[A-Za-z]{3}\b)"); // Regex pattern to find three-letter words
    sregex_iterator iter(text.begin(), text.end(), wordPattern);
    sregex_iterator end;

    size_t lastPos = 0;
    for (; iter != end; ++iter) {
        string word = iter->str();
        size_t pos = iter->position();

        // Append text before the matched word
        result.append(text, lastPos, pos - lastPos);

        // Replace word based on capitalization
        if (isupper(word[0])) {
            result.append("C++");
        } else {
            result.append("c--");
        }

        lastPos = pos + word.length();
    }

    // Append the remaining text
    result.append(text, lastPos, text.length() - lastPos);

    return result;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    // File validation check
    if (!inputFile) {
        cerr << "❌ Error: Unable to open input file.\n";
        return 1;
    }
    if (!outputFile) {
        cerr << "❌ Error: Unable to create output file.\n";
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();  // Read the entire file into a buffer
    string originalText = buffer.str();

    // Process the text
    string modifiedText = processText(originalText);

    // Display output in the console
    cout << "===== Modified Text =====\n" << modifiedText << "\n";

    // Write the modified text to output file
    outputFile << modifiedText;

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "\n✅ Process completed! Modified text saved in 'output.txt'.\n";
    return 0;
}
