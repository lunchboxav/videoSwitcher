#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetVerticalSync(true);

	//mySerial.setup(1, 9600);
	inByte = 0;

	loopMovie.load("movies/Particle_25_mepet_max_baru.mp4");
	loopMovie.setLoopState(OF_LOOP_NORMAL);
	loopMovie.play();

	triggeredMovie.load("movies/FibreFirst_Animation_final.mp4");
	triggeredMovie.setLoopState(OF_LOOP_NONE);
	triggeredMovie.stop();

	isToggled = false;
	mFinished = true;

	state = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

	/*if (mySerial.available()) {
	inByte = mySerial.readByte();
	if (inByte == 1) {
		isToggled = true;
	} else if (inByte == 0) {
		isToggled = false;
		}
	}*/


	state = checkState();

	if (state == 0) {
		triggeredMovie.stop();
		loopMovie.play();
		loopMovie.update();
	}
	else if (state == 1) {
		loopMovie.stop();
		triggeredMovie.play();
		triggeredMovie.update();
		mFinished = false;
		isToggled = false;
		if (triggeredMovie.getIsMovieDone()) {
			mFinished = true;
		}
	}

	cout << "toggled: " << isToggled << " finished: " << mFinished << " state: " << state << endl;

}

//--------------------------------------------------------------
int ofApp::checkState() {
	int state_;
	if (mFinished) {
		state_ = 0;
	}

	if (isToggled || !mFinished) {
		state_ = 1;
	}

	return state_;
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (state == 0) {
		loopMovie.draw(0, 0);
	}
	else if (state == 1) {
		triggeredMovie.draw(0, 0);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if (key == 'r') {
		isToggled = true;
	}
	else if (key == 't') {
		isToggled = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
