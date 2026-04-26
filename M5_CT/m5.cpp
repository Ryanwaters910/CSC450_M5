#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void reverseFileContents()
{
    ifstream inputFile("CSC450_CT5_mod5.txt");

    if (!inputFile)
    {
        cout << "Error opening input file." << endl;
        return;
    }

    string fileContents;
    string line;

    while (getline(inputFile, line))
    {
        fileContents += line + "\n";
    }

    inputFile.close();

    reverse(fileContents.begin(), fileContents.end());

    ofstream outputFile("CSC450-mod5-reverse.txt");

    if (!outputFile)
    {
        cout << "Error creating reverse file." << endl;
        return;
    }

    outputFile << fileContents;
    outputFile.close();
}

int main()
{
    string userInput;

    cout << "Enter text to append to the file: ";
    getline(cin, userInput);

    ofstream appendFile("CSC450_CT5_mod5.txt", ios::app);

    if (!appendFile)
    {
        cout << "Error opening file for appending." << endl;
        return 1;
    }

    appendFile << userInput << endl;
    appendFile.close();

    reverseFileContents();

    cout << "User input was appended to CSC450_CT5_mod5.txt." << endl;
    cout << "Reversed file was created as CSC450-mod5-reverse.txt." << endl;

    return 0;
}
