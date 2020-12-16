# BoilerPlate Repository for developing audio plugins with JUCE & CMake & Visual Studio Code

## Requirements

- JUCE >= 6.0.0 (supports CMake after v6.)
- CMake >= 3.15
- Visual Studio Code

Also, clangd a language server for C++ is highly recommended. In macOS, you can install with `brew install llvm`.

Ninja is also recommended for fast build (will be used automatically if present in this repository. You can change priority of generators in `cmake.preferredGenerators` in workspace setting).

### Recommended Extentions for vscode

- cpptools (basic language supports for C++ development)
- CMake (CMake language supports)
- CMake Tools (Advanced Integration for using CMake in VScode with GUI)
- CodeLLDB (better debugger than built-in gdb)
- clangd (Advanced intellisense support and formatter powered by llvm)

## Getting Started

### macOS

Install Xcode and type `xcode-select --install` in terminal.
open `~/.zshrc` and add `export SDKROOT="$(xcrun --sdk macosx --show-sdk-path)"` in the last line of the file.

### Windows

Install Visual Studio.

### common

1: Open `juce_cmake_vscode_example.code-workspace` with Visual Studio Code.
If recommended extensions are not installed, notification to install them will come up.

If CMake Tools is correctly installed, you will be asked which CMake Kits(compiler) you want to use. 

In macOS, choose `Clang x.x.x` which point to `/usr/bin/clang++` (clang provided by xcode. of course you can choose other compilers if you have).

In Windows, choose `Visual Studio Community 2019 Release - amd64`, you will have choices of architectures(like amd64/x86-amd64).

Open CMake Menu on your left sidebar (it will show up if CMake Tools is installed).

Click "Build All Projects".

If successfully built, right click JUCE_CMAKE_EXAMPLE/src/ExamplePlugin_Standalone and select "set as Debug/Launch Target".

Open Debug Menu in left Sidebar. And click Run button on the left in a menu of CMake Debug(workspace). Standalone version of your plugin will be launched.

## Resources

[JUCE CMake API Documents](https://github.com/juce-framework/JUCE/blob/master/docs/CMake%20API.md)

## License

(c) Tomoya Matsuura https://matsuuratomoya.com

All of source codes included in this repository are published under MIT License.

All of documents included in this repositry are published under Creative Commons 4.0 BY.

