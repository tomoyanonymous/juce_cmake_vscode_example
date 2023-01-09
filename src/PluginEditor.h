/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"


//==============================================================================
/**
 */
class TestpluginAudioProcessorEditor : public juce::AudioProcessorEditor {
 public:
  TestpluginAudioProcessorEditor(TestpluginAudioProcessor &);
  ~TestpluginAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;

 private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  TestpluginAudioProcessor &audioProcessor;
  std::unique_ptr<juce::Drawable> svgimg;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TestpluginAudioProcessorEditor)
};
