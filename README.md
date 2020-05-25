# About ASIOhost
 Windows Forms cpp/CLR ASIO host
 
ASIOhost is a cpp/CLR interface to Steinberg's [Audio Stream Input/Output](http://en.wikipedia.org/wiki/Audio_Stream_Input/Output) (ASIO) API. It provides access to low-level ASIO audio drivers and low-latecy (< 10ms) audio input and output access to the available audio hardware on **Windows**.

+ It provides a simple hook procedure for customized mono or multichannel audio processing  
+ It provides a simple Windows Form that can be enhanced with the Visual Studio Forms designer
+ It provides an ASIO device enumeration control


## Getting Started

+ You must [download](http://www.steinberg.net/en/company/developer.html) your own copy of the ASIO library. It cannot be distributed here due to licensing restrictions by Steinberg.
+ Copy the ASIOSDK2.3.2 folder besides the ASIOhost folder 
+ Compile with MS Visual Studio 2019 
+ In case you don't have an ASIO device driver installed, consider to use the [ASIO4ALL](http://www.asio4all.org/) generic ASIO driver.


## Acknowledgements
ASIO is a trademark and software of Steinberg Media Technologies GmbH
