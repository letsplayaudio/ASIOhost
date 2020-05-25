# About ASIOhost
 Windows Forms cpp/CLR ASIO host skeleton
 
ASIOhost is a simple Windows Forms cpp/CLR skeleton to use the Steinberg's [Audio Stream Input/Output](http://en.wikipedia.org/wiki/Audio_Stream_Input/Output) (ASIO) API. It provides access to low-level ASIO audio drivers for low-latecy (< 10ms) audio input and output access **Windows** audio hardware.

It provides:

+ A simple hook function for customized mono or multichannel audio processing  
+ A simple Windows Form that can be enhanced with the Visual Studio Forms Designer
+ An ASIO device enumeration control

![Alt text](/screenshots/screenshot1.jpg?raw=true "ASIO host")

## Getting Started

+ You must [download](http://www.steinberg.net/en/company/developer.html) your own copy of the ASIO library. It cannot be distributed here due to licensing restrictions by Steinberg.
+ Copy the ASIOSDK2.3.2 folder besides the ASIOhost folder 
+ Compile with MS Visual Studio 2019 
+ In case you don't have an ASIO device driver installed, consider to use the [ASIO4ALL](http://www.asio4all.org/) generic ASIO driver.

## Audio processing

Hock your audio processing code into the following function (host.cpp)
```cpp
bool ProcessSamples(void *inputBuffer, void *outputBuffer, long sampleCount, int channel, ASIOSampleType bufferType)
{

	long  *outBuff = (long*)outputBuffer;
	long  *inBuff = (long*)inputBuffer;
	float  sampleIn, sampleOut;


	for (int i = 0; i < sampleCount; i++, outBuff++, inBuff++) {

		sampleIn = *inBuff / CPClipSample32;

		// Processing
		sampleOut = sampleIn *(float)0.5;

		*outBuff = round(CPClipSample32* sampleOut);
		
	}

	return true;
}
```

## Acknowledgements
ASIO is a trademark and software of Steinberg Media Technologies GmbH
