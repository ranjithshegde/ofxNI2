#include "ofApp.h"


ofEasyCam cam;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);

    device.setup(0);
    tracker.setup(device);
}

void ofApp::exit()
{
    tracker.exit();
    device.exit();
}

//--------------------------------------------------------------
void ofApp::update()
{
    device.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    depthPixels = tracker.getPixelsRef(1000, 4000);
    depthTexture.loadData(depthPixels);

    // draw in 2D
    ofSetColor(255);
    depthTexture.draw(0, 0);

    ofPushView();
    tracker.getOverlayCamera().begin(ofRectangle(0, 0, depthTexture.getWidth(), depthTexture.getHeight()));
    ofDrawAxis(100);
    tracker.draw();
    tracker.getOverlayCamera().end();
    ofPopView();

/*
    // draw in 3D
    cam.begin();
    ofDrawAxis(100);
    tracker.draw();

    // draw box
    ofNoFill();
    ofSetColor(255, 0, 0);
    for (int i = 0; i < tracker.getNumUser(); i++)
    {
        ofxNiTE2::User::Ref user = tracker.getUser(i);
        const ofxNiTE2::Joint &joint = user->getJoint(nite::JOINT_HEAD);

        joint.transformGL();
        ofDrawBox(300);
        joint.restoreTransformGL();
    }

    cam.end();

*/

    ofDrawBitmapString(ofToString(ofGetFrameRate()),20,ofGetHeight()-20);

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
