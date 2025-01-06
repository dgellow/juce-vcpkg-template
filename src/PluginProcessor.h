#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class HelloWorldProcessor : public juce::AudioProcessor
{
public:
	HelloWorldProcessor();
	~HelloWorldProcessor() override;

	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;
	void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

	juce::AudioProcessorEditor *createEditor() override;
	bool hasEditor() const override { return true; }

	const juce::String getName() const override { return "Hello World"; }
	bool acceptsMidi() const override { return false; }
	bool producesMidi() const override { return false; }
	double getTailLengthSeconds() const override { return 0.0; }

	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int) override;
	const juce::String getProgramName(int) override;
	void changeProgramName(int, const juce::String &) override;

	void getStateInformation(juce::MemoryBlock &) override {}
	void setStateInformation(const void *, int) override {}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HelloWorldProcessor)
};
