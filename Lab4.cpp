#include <iostream>
#include <fstream>

using namespace std;

// Function to merge two sorted arrays into a third array
void mergeFiles(ifstream &file1, ifstream &file2, ofstream &outputFile) {
    const int SIZE1 = 100, SIZE2 = 100; // Assuming max 100 numbers per file
    int arr1[SIZE1], arr2[SIZE2], merged[SIZE1 + SIZE2];
    int size1 = 0, size2 = 0, mergedSize = 0;

    // Read numbers from first file into arr1
    while (file1 >> arr1[size1] && size1 < SIZE1) {
        size1++;
    }

    // Read numbers from second file into arr2
    while (file2 >> arr2[size2] && size2 < SIZE2) {
        size2++;
    }

    // Merge the two sorted arrays into merged[]
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[mergedSize++] = arr1[i++];
        } else {
            merged[mergedSize++] = arr2[j++];
        }
    }
    
    // Copy remaining elements from arr1, if any
    while (i < size1) {
        merged[mergedSize++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    while (j < size2) {
        merged[mergedSize++] = arr2[j++];
    }

    // Write the merged sorted numbers into the output file
    for (int k = 0; k < mergedSize; k++) {
        outputFile << merged[k] << " ";
    }
}

int main() {
    string fileName1, fileName2, outputFileName;

    // Get file names from the user
    cout << "Enter first input file name: ";
    cin >> fileName1;
    cout << "Enter second input file name: ";
    cin >> fileName2;
    cout << "Enter output file name: ";
    cin >> outputFileName;

    ifstream file1(fileName1), file2(fileName2);
    ofstream outputFile(outputFileName);

    // Check if files opened successfully
    if (!file1 || !file2 || !outputFile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    // Merge files
    mergeFiles(file1, file2, outputFile);

    // Close files
    file1.close();
    file2.close();
    outputFile.close();

    cout << "Merged numbers have been written to " << outputFileName << endl;
    return 0;
}
