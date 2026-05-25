ACPM

Advanced C++ Project Manager
A lightweight terminal-based C++ project generator built for modern C++ development.

✨ Features
⚡ Fast interactive terminal UI
📁 Automatic project structure generation
🛠️ Optional CMakeLists.txt creation
🚀 Multiple C++ standard support
C++23
C++20
C++17
C++14
C++11
🎨 ANSI colored interface
⌨️ Arrow-key navigation system
📦 Generates:
src/
include/
main.cpp
pch.hpp
CMakeLists.txt
📸 Preview
-=========== ACPM (Project Manager) ===========-

   > Create Project
     Settings
     About
     Exit

------------------------------------------------
Use Arrow Keys To Navigate | ENTER -> Select
🚀 Getting Started
Requirements
Windows
MinGW / GCC
CMake
C++17 or newer compiler
🔧 Build
Using MinGW
cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build
▶️ Run
./build/ACPM.exe
📂 Generated Project Structure
MyProject/
├── src/
│   └── main.cpp
├── include/
│   └── pch.hpp
└── CMakeLists.txt
🧠 Why ACPM?

Creating C++ projects manually gets repetitive:

Creating folders
Writing boilerplate
Configuring CMake
Setting standards
Organizing structure

ACPM automates all of it in seconds.

⚙️ Technologies
Modern C++
STL
<filesystem>
ANSI Escape Codes
CMake
MinGW
🛣️ Roadmap
 Library integration system
 SDL3 templates
 Vulkan starter projects
 GLFW support
 ImGui integration
 Config system
 Theme customization
 Linux support
 Plugin system
🤝 Contributing

Pull requests, ideas, and improvements are welcome.

If you find bugs or have suggestions, feel free to open an issue.

📜 License

MIT License

👨‍💻 Author

Hadi Vafaee
GitHub: Hypex-g17 GitHub Profile

⭐ Support

If you like this project, consider giving it a star on GitHub.