mkdir ..\Build 2>nul
mkdir ..\Build\Windows 2>nul
g++ -Wall "../Source/*.cpp" -o "../Build/Windows/Output.exe" -lglfw3 -lopengl32 -lglew32