# PJM Recognizer Demo
An app for learning the Polish sign alphabet.

## Short description
Thanks for taking interest in this small project :) This is an app meant to teach you the Polish sign alphabet in an interactive way. Requires a webcam and utilizes a simple neural net to classify your gestures into one of 21 classes. To read about the net architecture and training in more detail, visit [this repo](https://github.com/worthy11/PJMRecognizer). 

## Usage
Upon running the app, you'll be shown a window containing the following elements:
- A **category picker**, which lets you select the type of words you'd like to learn to spell. Includes foods, names, emotions, geographical locations and more;
- The **chosen word**, selected randomly from the category of your choice and divided into particular letters. You can generate a new one anytime you want;
- Your **webcam feed**, where you can admire your pretty face and make sure your hand is in frame;
- An **instruction image**, displaying the gesture you're supposed to show;
- An **instruction text box**, in case you forget what you're supposed to be doing. <br />

When the correct gesture is detected, the current letter will start changing its colour to green. Hold the gesture for about 1 second to complete the letter - the app will automatically switch to the next one after that (unless you complete the whole word, then a new one will be generated). <br />

And that's it! Happy spelling :)

## Installation
Fair warning: I haven't tested the app on anything but Windows, so there's a chance it won't work if you're using a different OS.

### Downloading release
Prerequisits: Python 3.11. The required Python modules are listed in `requirements.txt`. You can install them by running the command `pip install -r requirements.txt`. <br />

Download the release package from [here](). After installing the prerequisits and extracting the package, you should be able to run the `PJMRecognizer.exe` file located in the `<extract_location>/PJMRecognizer/build/src/` directory.

### Running from source
Prerequisits:
- OpenCV 4.9.0 or higher
- Qt 5.15.2
- Python 3.x<br />

The required Python modules are listed in `requirements.txt`. You can install them by running the command `pip install -r requirements.txt`. <br />

I recommend a custom installation of Qt Creator containing Qt 5.15.2 along with the MSVC2019 64bit compiler and running the code from there.