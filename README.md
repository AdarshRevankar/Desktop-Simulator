# Desktop Simulator 
[![Inline docs](http://inch-ci.org/github/AdarshRevankar/Desktop-Simulator.svg?branch=master)](http://inch-ci.org/github/AdarshRevankar/Desktop-Simulator)
[![Build Status](https://travis-ci.org/AdarshRevankar/Desktop-Simulator.png?branch=master)](https://travis-ci.org/AdarshRevankar/Desktop-Simulator)
[![HitCount](http://hits.dwyl.com/AdarshRevankar/Desktop-Simulator.svg)](http://hits.dwyl.com/AdarshRevankar/Desktop-Simulator)

OpenGL project which consists of 3D environment, to demonstrate assembly and disassembly of desktop parts. This uses basic glut library to construct a 3D Scene of CPU and it's components.

![Desktop-Simulator-Logo](https://user-images.githubusercontent.com/48080453/79739766-4220f300-831c-11ea-9873-8991e212f4cb.png)

see [Code of Conduct](https://github.com/AdarshRevankar/Desktop-Simulator/blob/master/CODE_OF_CONDUCT.md)

---
## Demonstration - Youtube
```https://youtu.be/VInynN3uoLo```

---
## Snapshot

Instance | Image
--- | ---
Initial View | <img src="https://user-images.githubusercontent.com/48080453/60199807-5a41f600-9862-11e9-849c-9f65a8638e0d.png" alt="initial view of system" style="max-height: 80px;"/>
CPU View | <img src="https://user-images.githubusercontent.com/48080453/60199855-73e33d80-9862-11e9-9d0f-3606fbb0bbb8.png" alt="cpu view" style="max-height: 80px;"/>
Desktop View | <img src="https://user-images.githubusercontent.com/48080453/60199856-73e33d80-9862-11e9-850e-467f089f63cc.png" alt="desktop" style="max-height: 80px;"/>

---

## Setup Project

 ### Windows
  1. Setup the project with required OpenGL headerfiles in your IDE (refer this - [Visual Studio](https://www.youtube.com/watch?v=k9LDF016_1A) or [CodeBlocks](https://www.youtube.com/watch?time_continue=79&v=Le4ub4apbn0)).
  2. Copy all required __header files & data files__ the project.
  3. Run the project. `main.cpp`
  
 > **Note**: BMP Image Error - `parameter.h` change _BMP images_ path to either **Relative** to project *( Currently )* or **Absolute**  *( if error occurs )*

 ### MacOS
 Instructions to run on MacOS
 
 Install **brew**
 ```
 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
 ```
 
 Install necesarry linking libraries
 ```
 brew install freeglut glfw3 glew lstdc++
 ```
 
 Compile project into binary
 ```
 clang -o main main.cpp -L/usr/local/lib -lglfw -lstdc++ -framework OpenGL -framework GLUT -framework Cocoa
 ```
 
 Run the binary
 ```
 ./main
 ```

 > **Note**: GLUT is getting deprecated on MacOS 10.9 above, so some functionalities might not work. Need to fix these deprecations soon

---
  
## Controls
  - `Up Arrow` - Move Forwards
  - `Down Arrow` - Move Backwords
  - `Left Arrow` - Move Left Side
  - `Right Arrow` - Move Right Side
  - `Esc` - Exit of Program / Exit of CPU View ( according to context )
  - `Enter` - Enter into CPU View / Disassemble Components ( according to context )
  - `Backspace` - Assemble components
  - `Mouse Hover` - Change Camera View & Rotate Person
  
---

## Requirements
  - (optional) IDE ( *Visual Studio / CodeBlocks* )\*
  - basic C++ Libraries
  - glut.h ( freeglut )
    
---

## References
  1. Basic 3D World Setup - [lighthouse3d.com](http://www.lighthouse3d.com/tutorials/glut-tutorial/).
  2. Basic OpenGL function's introduction - [khronos.org](https://www.khronos.org/).
  3. Texture Mapping - [youtube.com](https://www.youtube.com/watch?v=Eh0HeTCCgnE&t=452s).
  4. Textbook for understanding structure of OpenGL - [Computer Graphics With OpenGL - Donald Hearn & Pauline Baker](https://doc.lagout.org/programmation/OpenGL/Computer%20Graphics%20with%20OpenGL%20%284th%20ed.%29%20%5BHearn%2C%20Baker%20%26%20Carithers%202013%5D.pdf).
  
---

## Project Report
> [Project Report](https://github.com/AdarshRevankar/GRAPHICAL-SIMULATION-OF-DESKTOP-AND-ITS-COMPONENTS/files/3331188/Report_GSDC.pdf) with detailed structure of project.

---

## Questions
  Mail / Facebook messages can be done
  * [Adarsh Revankar](https://www.facebook.com/adarsh.revankar.3) - `adarsh_revankar@live.com`
  * [Akshaya Ram](https://www.facebook.com/akshaya.muthuraman) - `akshayaram004@gmail.com`
