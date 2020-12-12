# Installation

### Windows [.bat](Scripts/Install.bat) [.sh](Scripts/Install.sh)

- Download and install [NVIDIA drivers](https://www.nvidia.com/Download/index.aspx)
- Install [MSYS2](https://repo.msys2.org/distrib/msys2-x86_64-latest.exe)
- Run MSYS2
```batch
pacman -Syu
pacman -Su
```
<!-- pacman -S mingw-w64-x86_64-make
``` -->
- Add to environment variable PATH:
<!--- C:\Program Files\Git\cmd -->
<!--- C:\Program Files\Git LFS -->
<!--- C:\Program Files (x86)\GitExtensions -->
<!--- C:\Program Files\CMake\bin -->
    C:\msys64\mingw64\bin
<!--- C:\Program Files\Python38 -->
<!--- C:\Program Files\Google\Chrome\Application -->
- Run MSYS2 MinGW 64-bit
    - C/C++
    ```batch
    pacman -S mingw-w64-x86_64-gcc
    ```
    - Doxygen
    ```batch
    pacman -S mingw-w64-x86_64-doxygen
    ```
    - OpenGL (Dynamic libraries)
    ```batch
    pacman -S mingw-w64-x86_64-glfw mingw-w64-x86_64-glew mingw-w64-x86_64-glm
    ```
<!--    - GLUT
    ```batch
    pacman -S mingw-w64-x86_64-freeglut
    ``` -->

### Linux [.sh](Scripts/Install.sh)

### MacOS [.sh](Scripts/Install.sh)

# Build

### Windows [.bat](Scripts/Build.bat) [.sh](Scripts/Build.sh)

- Prepare built directory
<!-- -->
<!-- -->
```batch
mkdir Build
mkdir Build/Windows
```
- Compile
```batch
g++ -Wall "Source/*.cpp" -o "Build/Windows/Output.exe" -lglfw3 -lopengl32 -lglew32
```

### Linux [.sh](Scripts/Build.sh)

- Prepare built directory
```batch
mkdir -p Build/Linux 
```
- Compile
```batch
g++ -Wall "Source/*.cpp" -o "Build/Linux/Output.a" -lglfw3 -lopengl32 -lglew32
```

### MacOS [.sh](Scripts/Build.sh)

- Prepare built directory
```batch
mkdir -p Build/MacOS 
```
- Compile
```batch
g++ -Wall "Source/*.cpp" -o "Build/MacOS/Output.a" -lglfw3 -lopengl32 -lglew32
```

# Run application

### Windows [.bat](Scripts/Run.bat) [.sh](Scripts/Run.sh)
```batch
start Build/Windows/Output.exe
```

### Linux [.sh](Scripts/Run.sh)

### MacOS [.sh](Scripts/Run.sh)

# Generate documentation

### Windows [.bat](Scripts/GenerateDocumentation.bat) [.sh](Scripts/GenerateDocumentation.sh)
```batch
chcp 65001>nul & (type "Documentation\Doxyfile" & echo PROJECT_NAME = "Project name" & echo PROJECT_NUMBER = "0.0.1" & echo PROJECT_BRIEF = "Description") | doxygen -
```

### Linux and MacOS [.sh](Scripts/GenerateDocumentation.sh)

# Open documentation
- chrome [.sh](Scripts/OpenDocumentation.sh) [.bat (Windows)](Scripts/OpenDocumentation.bat)
```batch
webbrowser "Documentation/html/index.html"
```
