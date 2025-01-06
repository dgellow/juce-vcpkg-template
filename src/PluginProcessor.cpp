#include "PluginProcessor.h"
#include "PluginEditor.h"

HelloWorldProcessor::HelloWorldProcessor()
    : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo()).withOutput("Output", juce::AudioChannelSet::stereo()))
{
}

HelloWorldProcessor::~HelloWorldProcessor() {}

void HelloWorldProcessor::prepareToPlay(double, int) {}
void HelloWorldProcessor::releaseResources() {}

void HelloWorldProcessor::processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer &)
{
    // Pass-through audio
    for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
    {
        auto *channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = channelData[sample];
        }
    }
}

juce::AudioProcessorEditor *HelloWorldProcessor::createEditor()
{
    return new HelloWorldEditor(*this);
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter()
{
    return new HelloWorldProcessor();
}

const juce::String HelloWorldProcessor::getProgramName(int index)
{
    return "Default Program"; // Give it a proper name
}

void HelloWorldProcessor::changeProgramName(int index, const juce::String &newName)
{
    // Implementation if you want to allow program name changes
}

int HelloWorldProcessor::getNumPrograms()
{
    return 1; // Keep one program for now
}

int HelloWorldProcessor::getCurrentProgram()
{
    return 0;
}

void HelloWorldProcessor::setCurrentProgram(int index)
{
    // Add program switching logic if needed
}