#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Prototypes */
void ParseFile(string, vector<bool>&, vector<string>&, vector<string>&);
void ShowList(vector<bool>, vector<string>, vector<string>);

/* Global Variables */
ifstream fileReader;
ofstream fileWriter;

/* Start of Program */
int main()
{
  // TODO: Declare 3 vectors to hold our data.

  // Open the to do file and store the data to the vector.
  // TODO: Complete the functions below.
  ParseFile("todo.txt", /*?*/, /*?*/, /*?*/);
  ShowList(/*?*/, /*?*/, /*?*/);

  /* TODO Challenge:
     Create a new function that asks user for task and date,
     and then add them to the list.
     (You don't have to save the list to the file for this challenge)
  */
}

void ParseFile(string fileName,
               vector<bool>& checks,
               vector<string>& tasks,
               vector<string>& dates)
{
  // Open the file.
  fileReader.open(fileName);

  // Iterate through each line from the file.
  string line;
  while (getline(fileReader, line))
  {
    // Declare 3 variables to hold our data.
    // TODO: Complete the statements below using string manipulation.
    string check = /*?*/;
    string task = /*?*/;
    string date = /*?*/;

    // TODO: Add the data to the vectors.

  }
}

void ShowList(vector<bool> checks,
               vector<string> tasks,
               vector<string> dates)
{
  for (int i = 0; i < checks.size(); i++)
  {
    // TODO: Output the check mark.

    // TODO: Output the task description.

    // TODO: Output the task date.

  }
}
