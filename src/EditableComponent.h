#pragma once
#include <JuceHeader.h>

class EditableComponent : public Component{

EditableComponent():Component(){

    addAndMakeVisible(border);
}

#if JUCE_DEBUG
    ResizableBorderComponent border;
#endif
};