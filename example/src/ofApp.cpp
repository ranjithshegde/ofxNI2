#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

    device.setLogLevel(OF_LOG_WARNING);
    device.setup();
	
    if (depth.setup(device))
	{
		depth.setFps(30);
		depth.start();
	}

    if (ir.setup(device)) // only for xtion device (OpenNI2-FreenectDriver issue)
    {
        ir.setFps(30);
        ir.start();
    }
	
    if (colour.setup(device)) // only for kinect device
    {       
        colour.setFps(60);
        colour.start();
    }
}

void ofApp::exit()
{
    device.exit();
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
