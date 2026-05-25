#include <conio.h>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESCAPE 27

// Fast ANSI Clear Screen
void ClearScreen() { system("cls"); }

void DrawMenu(const vector<string> &options, size_t selected) {
  cout << "\033[1m\033[36m-=========== ACPM (Project Manager) "
          "===========-\033[0m\n";

  for (size_t i = 0; i < options.size(); i++) {
    if (i == selected)
      cout << "   \033[32m\033[1m> \033[0m" << options[i] << "\n";
    else
      cout << "     " << options[i] << "\n";
  }

  cout << "\n------------------------------------------------\n";
  cout << "\033[94mUse Arrow Keys To Navigate | ENTER -> Select\033[0m\n";
}

int GetKey() {
  int ch = _getch();

  if (ch == 0 || ch == 224)
    return _getch();

  return ch;
}

int selectionMenu(const string &title, const vector<string> &options) {
  size_t selected = 0;

  while (true) {
    ClearScreen();

    cout << "\033[1m\033[33m" << title << "\033[0m\n";
    cout << "------------------------------------------------\n\n";

    for (size_t i = 0; i < options.size(); i++) {
      if (i == selected)
        cout << "   \033[32m\033[1m>\033[0m " << options[i] << "\n";
      else
        cout << "     " << options[i] << "\n";
    }

    cout << "\n\033[90mUse Arrow Keys, ENTER to confirm.\033[0m\n";

    int key = GetKey();

    if (key == KEY_UP)
      selected = (selected == 0) ? options.size() - 1 : selected - 1;

    else if (key == KEY_DOWN)
      selected = (selected + 1) % options.size();

    else if (key == KEY_ENTER)
      return static_cast<int>(selected);
  }
}

void CreateProject() {
  string projectName;
  bool validName = false;

  do {
    ClearScreen();

    cout << "\033[1m\033[36m-=========== Create New Project "
            "===========-\033[0m\n\n";

    cout << "\033[1m\033[33m[Input]\033[0m Enter Project Name: ";

    getline(cin, projectName);

    string forbiddenChars = "#@$%/+*,.'\\\" ";

    if (projectName.empty()) {
      cout << "\033[31m[Error]: Name is empty! Press any key...\033[0m";
      _getch();
    }

    else if (projectName.find_first_of(forbiddenChars) != string::npos) {
      cout << "\033[31m[Error]: Invalid characters! Press any key...\033[0m";
      _getch();
    }

    else {
      validName = true;
    }

  } while (!validName);

  string folderName;
  fs::path projectPath;

  while (true) {
    ClearScreen();

    cout << "\033[1m\033[36m-=========== Create New Project "
            "===========-\033[0m\n\n";

    cout << "\033[1m\033[33m[Input]\033[0m Enter Project's Folder Name: ";

    getline(cin, folderName);

    projectPath = folderName;

    if (fs::exists(projectPath)) {
      cout << "\033[31m[Error]: Folder already exists! Press any key...\033[0m";
      _getch();
    }

    else {
      break;
    }
  }

  // CMake Options
  string cmakeTitle =
      "Project: " + projectName + "\nDo you want to create CMakeLists.txt?";

  vector<string> cmakeOptions = {
      "Yes (Recommended)",
      "No"
  };

  bool createCMake = (selectionMenu(cmakeTitle, cmakeOptions) == 0);

  // C++ Standard
  string cppTitle =
      "Project: " + projectName + "\nSelect C++ standard version:";

  vector<string> cppVersions = {
      "c++23 (Recommended)",
      "c++20",
      "c++17",
      "c++14",
      "c++11"
  };

  int cppSelIndex = selectionMenu(cppTitle, cppVersions);

  string cppVersion = cppVersions[static_cast<size_t>(cppSelIndex)];

  string cppStdNumber = cppVersion.substr(3, 2);

  ClearScreen();

  cout << "\033[1m\033[36m-=========== Generating Project "
          "===========-\033[0m\n\n";

  fs::create_directories(projectPath / "src");
  fs::create_directories(projectPath / "include");

  cout << "\033[1m\033[32m[ACPM]\033[0m Directory structure created.\n";

  // main.cpp
  fs::path mainFilePath = projectPath / "src" / "main.cpp";

  ofstream mainFile(mainFilePath);

  if (mainFile.is_open()) {

    ifstream templateFile("assets/MainCppCode.txt");

    if (templateFile.is_open()) {
      mainFile << templateFile.rdbuf();
      templateFile.close();
    }

    else {
      mainFile
          << "#include <iostream>\n\n"
          << "int main() {\n"
          << "    std::cout << \"Hello World!\" << std::endl;\n"
          << "    return 0;\n"
          << "}\n";
    }

    mainFile.close();

    cout << "\033[1m\033[32m[ACPM]\033[0m main.cpp generated.\n";
  }

  // header file
  fs::path headerPath = projectPath / "include" / "pch.hpp";

  ofstream headerFile(headerPath);

  if (headerFile.is_open()) {
    headerFile << "#pragma once\n";
    headerFile.close();
  }

  // CMake
  if (createCMake) {

    fs::path cmakePath = projectPath / "CMakeLists.txt";

    ofstream cmakeFile(cmakePath);

    if (cmakeFile.is_open()) {

      ifstream cmakeTemplate(
          "assets/MainCmakeCode.txt");

      if (cmakeTemplate.is_open()) {

        string content(
            (istreambuf_iterator<char>(cmakeTemplate)),
            istreambuf_iterator<char>());

        size_t pos = content.find("project(");

        if (pos != string::npos) {

          size_t endPos = content.find(")", pos);

          content.replace(
              pos,
              endPos - pos + 1,
              "project(" + projectName + ")");
        }

        cmakeFile << content;

        cmakeTemplate.close();
      }

      else {

        cmakeFile
            << "cmake_minimum_required(VERSION 3.10)\n"
            << "project(" << projectName << ")\n"
            << "set(CMAKE_CXX_STANDARD " << cppStdNumber << ")\n"
            << "add_executable(${PROJECT_NAME} src/main.cpp)\n";
      }

      cmakeFile.close();

      cout << "\033[1m\033[32m[ACPM]\033[0m CMakeLists.txt generated.\n";
    }
  }

  cout << "\n\033[1m\033[32m[Success]\033[0m Project '"
       << projectName
       << "' is ready!\n";

  cout << "Press any key to continue...";
  _getch();
}

void ShowAbout() {
  cout << "\033[1mACPM - Advanced C++ Project Manager\033[0m\n"
       << "Version 1.0\n"
       << "A lightweight tool to bootstrap C++ projects quickly.\n";
}

void ShowSettings() {
  cout << "\033[1mSettings:\033[0m\n"
       << "Config file support coming soon...\n";
}

int main() {

  vector<string> options = {
      "Create Project",
      "Settings",
      "About",
      "Exit"
  };

  size_t selected = 0;

  bool running = true;

  while (running) {

    ClearScreen();

    DrawMenu(options, selected);

    int key = GetKey();

    switch (key) {

    case KEY_UP:
      selected = (selected == 0)
                     ? options.size() - 1
                     : selected - 1;
      break;

    case KEY_DOWN:
      selected = (selected + 1) % options.size();
      break;

    case KEY_ENTER:

      if (selected == 0) {
        CreateProject();
      }

      else if (selected == 1) {
        ClearScreen();
        ShowSettings();
        cout << "\nPress any key...";
        _getch();
      }

      else if (selected == 2) {
        ClearScreen();
        ShowAbout();
        cout << "\nPress any key...";
        _getch();
      }

      else if (selected == 3) {
        running = false;
      }

      break;

    case KEY_ESCAPE:
      running = false;
      break;
    }
  }

  ClearScreen();

  return 0;
}