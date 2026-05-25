# ACPM

> Advanced C++ Project Manager  
> A lightweight terminal-based C++ project generator built for modern C++ development.

---

# ✨ Features

- ⚡ Fast interactive terminal UI
- 📁 Automatic project structure generation
- 🛠️ Optional `CMakeLists.txt` generation
- 🚀 Multiple C++ standard support
  - C++23
  - C++20
  - C++17
  - C++14
  - C++11
- 🎨 ANSI colored interface
- ⌨️ Arrow-key navigation
- 📦 Auto-generated project layout
- 📄 Template-based source generation
- ⚙️ Modern CMake support

---

# 🚀 Getting Started

## 📋 Requirements

Before building ACPM, make sure you have:

- Windows
- MinGW / GCC
- CMake
- Git (Optional)
- A terminal with ANSI color support

Recommended compiler:

```txt
GCC 13+
```

---

# 🔧 Build ACPM

## Using MinGW

```bash
cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

---

# ▶️ Run ACPM

```bash
./build/bin/ACPM.exe
```

---

# 🌍 Global Terminal Usage

You can run ACPM from anywhere in the terminal by adding the executable directory to your system `PATH`.

---

## ⚙️ Add ACPM To Environment Variables

### 1️⃣ Open Environment Variables

Search for:

```txt
Edit the system environment variables
```

Then open:

```txt
Environment Variables
```

---

### 2️⃣ Edit PATH

Inside:

```txt
System Variables
```

find:

```txt
Path
```

then click:

```txt
Edit
```

---

### 3️⃣ Add ACPM Binary Path

Add:

```txt
C:\Projects\ACPM\build\bin
```

Replace the path with your actual ACPM location if different.

---

### 4️⃣ Restart Terminal

Close and reopen:

- PowerShell
- CMD
- Windows Terminal

---

## ✅ Usage

Now ACPM works globally from anywhere:

```bash
acpm
```

---

# 📂 Example Workflow

```bash
mkdir Projects
cd Projects

acpm
```

Then instantly generate a modern C++ project.

---

# 📁 Generated Project Structure

```txt
MyProject/
├── src/
│   └── main.cpp
├── include/
│   └── pch.hpp
└── CMakeLists.txt
```

---

# 🧠 Why ACPM?

Creating C++ projects manually becomes repetitive:

- Creating folders
- Setting up structure
- Writing boilerplate
- Configuring CMake
- Managing standards

ACPM automates the entire setup process in seconds.

---

# ⚙️ Technologies Used

- Modern C++
- STL
- `<filesystem>`
- ANSI Escape Codes
- CMake
- MinGW

---

# 🤝 Contributing

Contributions, ideas, and pull requests are welcome.

If you find bugs or have suggestions, feel free to open an issue.

---

# 📜 License

MIT License

---

# 👨‍💻 Author

**Hadi Vafaee**

GitHub: https://github.com/Hypex-g17

---

# ⭐ Support

If you like this project, consider giving it a star on GitHub.