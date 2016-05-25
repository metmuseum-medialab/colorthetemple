Color The Temple
================

The Color the Temple project is an interactive, projection mapped presentation about Hathor, Horus and Caesar Augustus. The content and software was initially developed by Maria Paula Saba and Matt Felsen during their internship in the Media Lab at the Metropolitan Museum of Art.


## Compile and run the openFrameworks presentation app

Download the v0.8.4 release of [openFrameworks](http://openframeworks.cc):
[http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_osx_release.zip](http://www.openframeworks.cc/versions/v0.8.4/of_v0.8.4_osx_release.zip)

Rename the folder to `openFrameworks` and put it in your home folder. The full page should be something like `/Users/YOUR_USER_NAME/openFrameworks`

Clone this repository to `~/openFrameworks/apps`

```
cd ~/openFrameworks/apps
git clone http://github.com/metmuseum-medialab/colorthetemple
````


Clone [ofxJSON](https://github.com/jefftimesten/ofxJSON.git), [ofxSyphon](https://github.com/astellato/ofxSyphon), [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew), and [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets) to `~/openFrameworks/addons`

```
cd ~/openFrameworks/addons
git clone https://github.com/jefftimesten/ofxJSON.git
git clone https://github.com/astellato/ofxSyphon
git clone https://github.com/Spacebrew/ofxSpacebrew
git clone https://github.com/labatrockwell/ofxLibwebsockets
```
    
Check out specific versions of these addons that are known to work:

```
cd ofJSON
git checkout 5934d70
cd ..

cd ofxLibwebsockets
git checkout 30a2d3c
cd ..

cd ofxSyphon
git checkout 62353d8
cd ..

cd ofxSpacebrew
git checkout d99b734
cd ..
``` 

### Build the app
Open SpacebrewController.xcodeproj. Make sure to build the DEBUG, not the RELEASE target. Add the video files to `~/openFrameworks/apps/colorthetemple/ColorTheTemple/bin/data`

## Run MadMapper for projection mapping

Install and run [MadMapper](http://madmapper.com), after connecting to an external projector.

Open up MadMapper, which will be used to deform the projection

* click the colorthetemple syphon plugin
* add a square mesh from the middle icon in the top left corner
* click the 'warp mesh' checkbox in the bottom left, then start tweaking the subdivisions, dragging the mesh points...
* to use on the projector, go to view -> view fullscreen
  * make sure the display mirroring is OFF


## Setup Spacebrew for remote control
[note: normally you wouldn't run code right from the Downloads directory. You should probably move both the Spacebrew directory and the colorTheTemple project under a common directory, with its own openframeworks directory structure. But the below will work.

#### Install Spacebrew

**Note:** This only be needs to be done if you are setting up the project on a new computer or new account. It is already set up on the `undeed` account on the Mac mini

Download and unzip the latest release of [spacebrew](http://spacebrew.cc) to `~/Downloads`

```
cd ~/Downloads && curl https://codeload.github.com/Spacebrew/spacebrew/legacy.zip/master -o spacebrew.zip
unzip spacebrew.zip
cd spacebrew
npm install       # install libraries
```

#### Run spacebrew

**Note:** These folder paths are for the Mac mini. If the account name or folder paths are different on your computer, make sure you `cd` into the right place :)

```
cd /Users/undeed/colorTheTemple/Spacebrew
npm start
```

##### Start a web server for the Spacebrew admin page

Serve up the spacebrew admin page in another terminal and open it up in your web browser

```
cd /Users/undeed/colorTheTemple/Spacebrew/admin
python -m SimpleHTTPServer 8001
open http://localhost:8001
```

##### Start a web server for the Color the Temple admin page

Serve up the colorthetemple controller page in yet another terminal and open it up in whatever you want to control the app

```
cd /Users/undeed/colorTheTemple/openFrameworks/apps/colorthetemple/WebInterfaces/colorthetemple
python -m SimpleHTTPServer 8000
open http://localhost:8000
```

##### Start the openFrameworks app

On the Mac mini, the app is already compiled so you should be able to run SpacebrewController.app without having to re-compile it in Xcode. It should be located at:
`/Users/undeed/colorTheTemple/openFrameworks/apps/colorthetemple/ColorTheTempler/bin` 

##### Connect the applications with Spacebrew

Finally, with everything running, check the Spacebrew admin page (`http://localhost:8001` on the Mac mini) and make sure the controller (CTT Remote) is connectd to the OF app. All of the following connections should be made

To make a connection, click on the text label of one side (e.g. "trigger") and then click the text label of the thing you want to connect it to (e.g. "receiver")

![image](WebInterfaces/spacebrew-conenctions.png)

Enjoy the show!
