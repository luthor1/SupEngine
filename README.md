# SupEngine

A completely custom 3D Game Engine built from scratch using C++ and Vulkan.

## Technologies
- **Language:** C++20
- **Graphics API:** Vulkan
- **Windowing:** GLFW
- **Math:** GLM
- **Logging:** spdlog
- **Build System:** CMake + GCC (MinGW-w64)

## How to Build
This project uses CMake and requires the Vulkan SDK to be installed on your machine.

```bash
# Clone the repository
git clone <repository_url>
cd SupEngine

# Configure the CMake Project (using GCC / MinGW)
cmake -B build -G "MinGW Makefiles"

# Build the Executable
cmake --build build -j 4

# Run the Engine
./build/SupEngine.exe
```

## Architecture
- **OOP Design:** Modular architecture separating the Vulkan Context, Windowing, and Application logic.
