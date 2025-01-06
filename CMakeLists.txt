cmake_minimum_required(VERSION 3.10)

project(JUCEHelloWorld VERSION 0.1.0)

find_package(JUCE CONFIG REQUIRED)

juce_add_plugin(JUCEHelloWorld
    VERSION ${PROJECT_VERSION}
    FORMATS VST3
    COPY_PLUGIN_AFTER_BUILD TRUE
    VST3_COPY_DIR "${CMAKE_INSTALL_PREFIX}/VST3")

target_compile_features(JUCEHelloWorld PRIVATE cxx_std_17)

target_sources(JUCEHelloWorld
    PRIVATE
        src/PluginProcessor.cpp
        src/PluginProcessor.h
        src/PluginEditor.h
        src/moduleinfo.json)

target_link_libraries(JUCEHelloWorld
	PRIVATE
		juce::juce_core
		juce::juce_audio_basics
		juce::juce_events
		juce::juce_audio_devices
		juce::juce_recommended_config_flags
		juce::juce_recommended_lto_flags
		juce::juce_recommended_warning_flags)

file(GLOB VST3_VALIDATOR_PATH
    "${CMAKE_BINARY_DIR}/vcpkg_installed/*/tools/vst3sdk/validator*")

add_custom_target(validate_vst3
    COMMAND ${VST3_VALIDATOR_PATH}
    "-e" # extended validation
    "${CMAKE_BINARY_DIR}/JUCEHelloWorld_artefacts/$<CONFIG>/VST3/JUCEHelloWorld.vst3"
    DEPENDS JUCEHelloWorld
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
