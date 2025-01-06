# A JUCE VST3 hello world using vcpkg + cmake

## Prerequisites

- [vcpkg](https://github.com/microsoft/vcpkg)
- [cmake](https://cmake.org/)
- A C++17 compiler

## Building

Add a `CMakeUserPresets.json` file to the root of this repo:

```json
// CMakeUserPresets.json

{
  "version": 2,
  "configurePresets": [
    {
      "name": "default",
      "inherits": "vcpkg",
      "environment": {
        "VCPKG_ROOT": "C:/vcpkg" // your vcpkg location
      }
    }
  ]
}
```

> :warning: On windows be sure to run cmake from a VS-aware shell.

```sh
# Generate
cmake --preset default

# Build
cmake --build --preset debug

# Validate
cmake --build --target validate_vst3 --preset debug
```

After a successful build, the plugin can be found in `out/install/VST3`:

```sh
$ cmake --build --preset debug
[...build logs...]
creating C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/build/JUCEHelloWorld_artefacts/Debug/VST3/JUCEHelloWorld.vst3/Contents/Resources/moduleinfo.json
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents/Resources
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents/Resources/moduleinfo.json
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents/x86_64-win
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents/x86_64-win/JUCEHelloWorld.ilk
-- Installing: C:/Users/Sam/Development/Cpp/JuceHelloWorld/out/install/VST3/JUCEHelloWorld.vst3/Contents/x86_64-win/JUCEHelloWorld.vst3
```
