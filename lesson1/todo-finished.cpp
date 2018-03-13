#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Prototypes */
void ReadFile(string fileName);
void WriteFile(string fileName, string text);

/* Global Variables */
ifstream fileReader;
ofstream fileWriter;

/* Start of Program */
int main()
{
  string todoFile = "todo.txt";
  ReadFile(todoFile);
  WriteFile(todoFile, "[x] Complete lesson 1");
}

/* Function Declarations */
void ReadFile(string fileName)
{
  // Open the file.
  fileReader.open(fileName);

  // Output each line to the console.
  string line;
  while (getline(fileReader, line))
  {
    cout << line << endl;
  }

  // Close the file (don't forget to do this!).
  fileReader.close();
}

void WriteFile(string fileName, string text)
{
  // Open the file.
  fileWriter.open(fileName, ios::app);

  // Write to the file.
  fileWriter << text << endl;

  // Close the file (don't forget to do this!).
  fileWriter.close();
}
