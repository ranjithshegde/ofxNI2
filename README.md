Setup
========
This is an addon to support the Kinect V2 on Linux/Windows/Mac using the Openni driver from Libfreenect2 (https://github.com/OpenKinect/libfreenect2/) 

Tested on openframeworks 0.10.1

The included libfreenect2-driver is using the OpenCL back-end. Comppile your own version if you need Cuda or any one of the other Libfreenect2 back-ends.

##All Platforms
Copy the NITE2 folder from the copy_to_bin_folder to your application's bin folder
Also copy the platform specific driver to the bin folder. The folder is called "OpenNI2" and a platform specific version of this folder is found in the copy_to_bin_folder as well.

##Linux
This should just work with the project generator.

##OSX
Use project generator and then in xcode:

Add to Run Script

cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/libNiTE2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/libNiTE2.dylib";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE.ini "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/NiTE.ini";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE2 "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/";
install_name_tool -change libOpenNI2.dylib @executable_path/../MacOS/libOpenNI2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";


##Visual Studio
This should just work with the project generator.
