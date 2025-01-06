#pragma once
#include "PluginProcessor.h"

class HelloWorldEditor : public juce::AudioProcessorEditor
{
public:
    explicit HelloWorldEditor(HelloWorldProcessor& p)
        : AudioProcessorEditor(&p)
    {
        setSize(400, 300);
    }

    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::white);
        g.setColour(juce::Colours::black);
        g.setFont(24.0f);
        g.drawText("Hello World!", getLocalBounds(), juce::Justification::centred);
    }

    void resized() override {}

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HelloWorldEditor)
};
