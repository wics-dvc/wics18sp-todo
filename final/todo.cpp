#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Prototypes */
void ParseFile(string, vector<bool>&, vector<string>&, vector<string>&);
void ShowList(vector<bool>, vector<string>, vector<string>);
void ShowMenu();
void AddTask(vector<bool>&, vector<string>&, vector<string>&);
void ToggleTask(vector<bool>&);
void RemoveTask(vector<bool>&, vector<string>&, vector<string>&);
void SaveFile(string, vector<bool>&, vector<string>&, vector<string>&);

/* Global Variables */
ifstream fileReader;
ofstream fileWriter;

/* Start of Program */
int main()
{
  // Declare 3 vectors to hold our data.
  vector<bool> myChecks;
  vector<string> myTasks;
  vector<string> myDates;

  // Open the to do file and store the data to the vector.
  ParseFile("todo.txt", myChecks, myTasks, myDates);

  // Run the program until user choose exit.
  while (true)
  {
    // Clear the console/terminal screen.
    if (system("CLS")) system("clear");

    // Show list and menu.
    ShowList(myChecks, myTasks, myDates);
    ShowMenu();

    // Get user's choice.
    cout << "Choice: ";
    int choice;
    cin >> choice;
    cin.ignore(1000, 10);
    cout << endl << endl;

    // Do things based on user's choice.
    switch (choice)
    {
      case 1: // Add task.
        AddTask(myChecks, myTasks, myDates);
        break;
      case 2: // Check/uncheck a task.
        ToggleTask(myChecks);
        break;
      case 3: // Remove a task.
        RemoveTask(myChecks, myTasks, myDates);
        break;
      case 4:
        return 0;
    }

    // Save to file after we're done with user action.
    SaveFile("todo.txt", myChecks, myTasks, myDates);
  }
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
    string check = line.substr(0, 1);
    string task = line.substr(4, line.length());
    string date = task.substr(task.find("| ") + 2, task.length());
    task = task.substr(0, task.find("|"));

    // Add the data to the vectors.
    if (check == "0")
    {
      checks.push_back(false);
    }
    else
    {
      checks.push_back(true);
    }
    tasks.push_back(task);
    dates.push_back(date);
  }

  // Close the file.
  fileReader.close();
}

void ShowList(vector<bool> checks,
               vector<string> tasks,
               vector<string> dates)
{
  for (int i = 0; i < checks.size(); i++)
  {
    // Output number so user can easily select tasks.
    cout << i + 1 << ". ";

    // Output the check mark.
    if (checks[i] == false)
    {
      cout << "[ ] ";
    }
    else
    {
      cout << "[x] ";
    }

    // Output the task description.
    cout << tasks[i] << endl;

    // Output the task date.
    cout << "       " << dates[i] << endl << endl;
  }
}

void ShowMenu()
{
  cout << "Menu:" << endl
       << "1. Add a task" << endl
       << "2. Check/uncheck a task" << endl
       << "3. Remove a task" << endl
       << "4. Exit" << endl;
}

void AddTask(vector<bool>& checks,
             vector<string>& tasks,
             vector<string>& dates)
{
  // Print a header.
  cout << "Add Task" << endl
       << "========" << endl;

  // Get task description from user.
  cout << "Description: ";
  string task;
  getline(cin, task);

  // Get task date from user.
  cout << "Date: ";
  string date;
  getline(cin, date);

  // TODO: Store data to our vectors.
}

void ToggleTask(vector<bool>& checks)
{
  // Print a header.
  cout << "Toggle Task" << endl
       << "===========" << endl;

  // Get the task number.
  cout << "Number: ";
  int num;
  cin >> num;
  cin.ignore(1000, 10);

  // TODO: Make sure the number is within the range.
  if (/* Put something here */)
  {
    // TODO: Flip the boolean of the check status.
  }
}

void RemoveTask(vector<bool>& checks,
                vector<string>& tasks,
                vector<string>& dates)
{
  // Print a header.
  cout << "Remove Task" << endl
       << "===========" << endl;

  // Get the task number.
  cout << "Number: ";
  int num;
  cin >> num;
  cin.ignore(1000, 10);

  // TODO: Make sure the number is within the range.
  if (/* Put something here */)
  {
    // TODO: Remove the task from the vectors.
  }
}

void SaveFile(string fileName,
              vector<bool>& checks,
              vector<string>& tasks,
              vector<string>& dates)
{
  // Open the file.
  fileWriter.open(fileName);

  // TODO: Write the vectors to the file.

  // Close the file.
  fileWriter.close();
}
