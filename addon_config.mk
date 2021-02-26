meta:
	ADDON_NAME = ofxNI2
	ADDON_DESCRIPTION = An addon for the using OpenNI2 and NiTE2 with the Kinect V2 sensor
	ADDON_AUTHOR = Pierre Proske
	ADDON_TAGS = "kinect" "kinectv2" "libfreenect" "libfreenect2" "openni2" "NITE2"
	ADDON_URL = https://github.com/pierrep/ofxNI2

osx:
	ADDON_LIBS=
	ADDON_LIBS     += libs/NiTE2/lib/osx/libNiTE2.dylib
	ADDON_LIBS     += libs/OpenNI2/lib/osx/libOpenNI2.dylib

	ADDON_LIBS_EXCLUDE =    libs/OpenNI2/lib/osx/OpenNI2/Drivers/libfreenect2-openni2.0.dylib
	ADDON_LIBS_EXCLUDE =    libs/OpenNI2/lib/osx/OpenNI2/Drivers/libfreenect2.dylib






linux64:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libusb-1.0 OpenCL

	# when parsing the file system looking for include paths exclude this for all or
	# a specific platform
	ADDON_INCLUDES_EXCLUDE = libs/libusb/%

linux:
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES = libusb-1.0 OpenCL

	# when parsing the file system looking for include paths exclude this for all or
	# a specific platform
	ADDON_INCLUDES_EXCLUDE = libs/libusb/%
	
vs:
	ADDON_LIBS_EXCLUDE = libs/OpenNI2/lib/vs/x64/OpenNI2/Drivers/%
	ADDON_LIBS_EXCLUDE += libs/NiTE2/lib/vs/x64/NiTE2.dll	
	ADDON_DLLS_TO_COPY  = copy_to_bin_folder/vs/x64/
