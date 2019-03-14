Setup
========
This is an addon to support the Kinect V2 on Linux/Windows/Mac using the OpenNI driver from Libfreenect2 (https://github.com/OpenKinect/libfreenect2/) 

Tested on openframeworks 0.10.1

The included libfreenect2-openni driver is using the OpenCL back-end. Compile your own version if you need Cuda or any one of the other Libfreenect2 back-ends.

All Platforms
-------------



Linux
-------
Create a project using the project generator, including this addon

Copy the NITE.ini file from the copy_to_bin_folder to your application's bin folder. If you aren't using NITE (no skeleton tracking, just depth) you can ignore this step.

OSX
---
Use project generator and then in xcode:

Add to Run Script

cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/libNiTE2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/libNiTE2.dylib";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE.ini "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/NiTE.ini";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE2 "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/";
install_name_tool -change libOpenNI2.dylib @executable_path/../MacOS/libOpenNI2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";


Visual Studio
-------------
This should just work with the project generator.
