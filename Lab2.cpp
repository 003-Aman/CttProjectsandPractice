#include <iostream>
using namespace std;

// Program to calculate the average score and letter grade for assignments
int main() {
    int numAssignments; // Variable to store the number of assignments

    // Prompt user for the number of assignments
    cout << "Enter the number of assignments: ";
    cin >> numAssignments;

    double sum = 0; // Variable to store the sum of all assignment scores

    // Loop through each assignment to collect scores
    for (int i = 0; i < numAssignments; i++) {
        double score; // Variable for each assignment score
        cout << "Enter score for assignment " << i + 1 << ": ";
        cin >> score;

        // Validate that the score is between 0 and 100
        if (score >= 0 && score <= 100) {
            sum += score; // Add valid score to the sum
        } else {
            cout << "Invalid score. Please enter a value between 0 and 100." << endl;
            i--; // Decrement loop counter to re-enter score for the current assignment
        }
    }

    double average = sum / numAssignments; // Calculate the average score

    char grade; // Variable to store the letter grade
    // Determine the letter grade based on the average score
    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';

    // Display the results to the user
    cout << "\nAverage Score: " << average << endl;
    cout << "Letter Grade: " << grade << endl;

    
    

    return 0;
}
