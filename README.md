# Speech Recognition System

Program for spectral analysis of sounds and studying the operation of neural networks in the task of speech recognition

## 1. Research program "Project"

The "Project" program has the following functionality and capabilities.
1. Reading and writing files in * .wav format.
2. Receiving a signal from the computer's sound card in real time, playing files and individual sounds from the database.
3. Spectral transformation - Fast Fourier transform (FFT) in a moving time window with smoothing function.
4. Displaying of the spectral diagram of the speech signal in the "time-frequency" coordinates. The diagram shows the amplitude of spectra by a palette of colors.
5. Displaying of the signal graph and spectrum graph. By placing the mouse cursor on any point of the chart, you can view the spectrum graph for the corresponding time.
6. It supports the work with the database necessary to form a set of samples to train the neural network. There is a functionality of conducting a test on database files, showing what percentage of sounds are recognized correctly.
7. Setting the parameters of the neural network (number of layers, neurons, activation functions), training neural networks using various methods.
8. There is a window for visualizing the work of the neural network. Signal amplitudes on neurons, thresholds and weights of synaptic connections (or bond amplitudes) are represented by colors.
9. The program recognizes speech sounds in real time with the output of sound symbols in the text box. When working with files, the result of sounds recognition can be displayed both in the specified text window and in the form of a color bar at the bottom of the spectrum diagram.
10. The program can perform the simplest synthesis of vowels and sonorous sounds by the relative amplitudes of the harmonics. It verifies the quality of the algorithm for the detachment of spectral lines.

## 2. Application "Voice Commander"

A program of speech control that opens and closes programs, executes commands "OK", "Cancel", "Close" in other programs, shutdown the computer, etc. This program also translates speech sounds into text. It is on the development stage and doesn't work perfectly.

## Installation

These 2 projects were created using Microsoft VS c++ 6. You can open dsw file in VS 6 and compile source code. The resultant exe file needs SoundCap.dll in the same directory to work properly (you can find this file in the root directory).

## Usage

Just open exe file (with SoundCap.dll in the same folder) and enjoy.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/AleksandrRogachev94/speech-recognition-system. This project is intended to be a safe, welcoming space for collaboration, and contributors are expected to adhere to the [Contributor Covenant](http://contributor-covenant.org) code of conduct.


## License

This Web Application is available as open source under the terms of the [GNU GENERAL PUBLIC LICENSE](https://www.gnu.org/licenses/gpl-3.0.en.html).
