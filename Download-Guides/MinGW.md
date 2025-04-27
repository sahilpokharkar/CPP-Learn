# Setting Up MinGW on Windows

This guide will walk you through downloading, installing, and configuring **MinGW (Minimalist GNU for Windows)** so you can compile and run C++ programs on Windows.

---

## Step 1: Download MinGW

1. Go to the official MinGW-w64 website:
   [https://www.mingw-w64.org/](https://www.mingw-w64.org/)

2. Scroll down and click the **"Downloads"** link.

3. Choose a recommended source such as:
   - **SourceForge**: [https://sourceforge.net/projects/mingw-w64/](https://sourceforge.net/projects/mingw-w64/)

4. Click **Download** to get the installer (`mingw-w64-install.exe`).

---

## Step 2: Install MinGW

1. Run the downloaded `mingw-w64-install.exe`.

2. In the installer, choose these settings:
   - **Version**: `8.1.0` or latest
   - **Architecture**: `x86_64`
   - **Threads**: `posix`
   - **Exception**: `seh`
   - **Build revision**: Keep default

**NOTE:** This just provides an general overview of the requirements choose the installer best suited for your system

3. Choose an installation directory (e.g., `C:\mingw-w64`).

4. Click **Next** and complete the installation.

---

## Step 3: Installation of some additional Packages

- After finishing the installation choose run option

- A Mingw Shell will open Run the following commands (Shell will look like git bash)

```
pacman -Syu
```
Enter Y to continue installation

- After Execution Terminal window might close
- To reopen the terminal Search for **MSYS2 MSYS** and click enter
- The terminal window shall open now
Now Run this command and Enter Y if asked
```
pacman -Su
```

- After Execution close the terminal window
- To reopen the terminal Search for **MSYS2 MinGW 64-bit** and click enter
- The terminal window shall open now
- Now run the follwing two installation commands
- the Commands might ask you to enter Y, So Enter Y and the installation will start 
- This commands might take a while to execute so don't worry u can check the installations are in order or not by simply checking the versions (Provided after each command)


1. To Install gcc
```
pacman -S mingw-w64-x86_64-gcc
```
```
gcc --version
```

2. To install gdb 
```
 pacman -S mingw-w64-x86_64-gdb
```
```
gdb --version
```

---

## Step 4: Add MinGW to System Path

1. Open the **Start Menu**, search for **"Environment Variables"**, and open it.

2. In the **System Properties** window, click on **Environment Variables...**

3. Under **System variables**, find and select the **Path** variable, then click **Edit**.

4. Click **New** and add the following path:
```
C:\mingw-w64\mingw64\bin
```
**NOTE:** This path might differ if you have chosen to install path to a different directory
It is Recommended that you keep your gcc in default location only

5. Click **OK** to close all windows and apply changes.

---

## Step 5: Verify Installation

1. Open Command Prompt:

2. Run the following command to verify MinGW is installed:
```bash
g++ --version
```
---

## Step 6: Compile and Run Your First C++ Program

Create a file named `hello.cpp` with the following content:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Open the command prompt where the hello.cpp file is located

Run the following command
This will create an executable file on the same location named hello.exe
```bash
g++ hello.cpp -o hello
```

Double clicking the file or running the following command will start the execution of your program

```bash
.\hello
```


