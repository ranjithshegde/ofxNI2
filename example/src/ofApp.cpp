#include "ofApp.h"

#include "ofxNI2.h"
#include "ofxLibfreenect2.h"

ofxNI2::Device *device;
ofxNI2::IrStream ir;
ofxNI2::ColorStream colour;
ofxNI2::DepthStream depth;

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	device = new ofxNI2::Device;
    device->setup();
	
	if (depth.setup(*device))
	{
		depth.setFps(30);
		depth.start();
        ofLogNotice() << "depth stream: " << depth.getWidth() << " x " << depth.getHeight();
	}

    if (ir.setup(*device)) // only for xtion device (OpenNI2-FreenectDriver issue)
    {
        ir.setFps(30);
        ir.start();
        ofLogNotice() << "ir stream: " << ir.getWidth() << " x " << ir.getHeight();
    }
	
    if (colour.setup(*device)) // only for kinect device
    {       
        colour.setFps(60);
        colour.start();
        ofLogNotice() << "colour stream: " << colour.getWidth() << " x " << colour.getHeight();
    }
}

void ofApp::exit()
{
	device->exit();
	delete device;
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ir.draw(0,0,640,480);
    colour.draw(640,0,640,480);
    depth.draw(640,480,640,480);

    ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 20,ofGetHeight()-30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
