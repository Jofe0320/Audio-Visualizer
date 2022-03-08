#include "ofApp.h"
#include <vector>


using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    sound.loadSound(loaded_sound); //Loads a sound file (in bin/data/)
    sound.setLoop(true); // Makes the song loop indefinitely
    sound.setVolume(1); // Sets the song volume
    ofSetBackgroundColor(0, 255, 191);; // Sets the Background Color
    
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate(); // Updates all sound players
    if (visualizer_running) {
        visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
    }
    if(playback == true){
        
        if(updateCounter%120 == 0){
            if(replayFlag<actions.size()){
                 replayKeys(actions[replayFlag-2]);
               
                 replayFlag += 1;
            }
            else{
                playback = false;
                replayFlag = 0;
            }      
        }
      
        updateCounter+=1;
        
    }  
}



//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if(!playing){
        ofDrawBitmapString("Press 'p' to play some music!", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    vector<float> amplitudes = visualizer.getAmplitudes();
    if(mode == '1'){
        drawMode1(amplitudes);
    }else if(mode == '2'){
        drawMode2(amplitudes);
    }else if(mode == '3'){
        drawMode3(amplitudes);
    }
}
void ofApp::drawMode1(vector<float> amplitudes){
        ofFill(); // Drawn Shapes will be filled in with color
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        for(int i=0; i < amplitudes.size(); i++){
            ofSetColor(rgbMode1[0], rgbMode1[1], rgbMode1[2]); 
            ofDrawRectangle((ofGetWindowWidth()/64)*i, ofGetHeight()-100, ofGetWindowWidth()/64, amplitudes[i]);   
        }
        if(record == true){
            ofSetColor(255,17,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Recording...", (ofGetWindowWidth()-100), 15);
        }
        if(playback == true){
            ofSetColor(0,0,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Replaying...", (ofGetWindowWidth()-100), 15);
        }



        
}
void ofApp::drawMode2(vector<float> amplitudes){
        ofSetLineWidth(5); // Sets the line width
        ofNoFill(); // Only the outline of shapes will be drawn
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Circle Radius Visualizer", 0, 15);
        int bands = amplitudes.size();
        for(int i=0; i< bands; i++){
            ofSetColor((bands - i)*32 %256,rgbMode2[0],rgbMode2[1]); // Color varies between frequencies
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, amplitudes[0]/(i +1));
        }
         if(record == true){
            ofSetColor(255,17,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Recording...", (ofGetWindowWidth()-100), 15);
        }
          if(playback == true){
            ofSetColor(0,0,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Replaying...", (ofGetWindowWidth()-100), 15);
        }
}

void ofApp::drawMode3(vector<float> amplitudes){
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
    // YOUR CODE HERE
    ofFill(); // Drawn Shapes will be filled in with color
    ofSetColor(256); // This resets the color of the "brush" to white
    for(int i=0; i < amplitudes.size(); i++){

        ofSetColor(rgbMode3[0], rgbMode3[1], rgbMode3[2]); 
        ofDrawRectangle(ofGetWindowWidth(),(ofGetWindowWidth()/64)*i, amplitudes[i],ofGetWindowWidth()/64);   
    }
    if(record == true){
            ofSetColor(255,17,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Recording...", (ofGetWindowWidth()-100), 15);
        }
    if(playback == true){
            ofSetColor(0,0,0); // This resets the color of the "brush" to white
            ofDrawBitmapString("Replaying...", (ofGetWindowWidth()-100), 15);
        }
          
}

//--------------------------------------------------------------

void ofApp::replayKeys(char key){
    switch(key){
        case 'p':
            if(playing){
                sound.stop();
            }else{
                sound.play();
            }
            playing = !playing;
            break;
        case '1':
            mode = '1';
            ofSetBackgroundColor(0, 255, 191);
            rgbMode1[0] = ofRandom(256);
            rgbMode1[1] = ofRandom(256);
            rgbMode1[2] = ofRandom(256);
            break;
        case '2':
            mode = '2';
            ofSetBackgroundColor(247, 128, 231);
            rgbMode2[0] = ofRandom(256);
            rgbMode2[1] = ofRandom(256);
            break;
        case '3':
            mode = '3';
            ofSetBackgroundColor(239,231,79);
            rgbMode3[0] = ofRandom(256);
            rgbMode3[1] = ofRandom(256);
            rgbMode3[2] = ofRandom(256);
            break;

        case 'a':
            if (playing) {
                visualizer_running = !visualizer_running;
            }
            if (playing) {
                if (visualizer_running) {
                    sound.play();
                } else {
                    sound.stop();
                }
            }
            break;

        case 'd':
            playSong("geesebeat.wav");
            break;

        case 'f':
            playSong("beat.wav");
            break;

        case 'g':
            playSong("pigeon-coo.wav");
            break;

        case 'h':
            playSong("rock-song.wav");
            break;

        case 'v':
            playSong("lasanta.wav");
            break;

        case 'b':
            playSong("thespins.wav");
            break;

        case 'n':
            playSong("walkingdream.wav");
            break;

        case '-':                   // Decrease volume
            while(sound.getVolume()>0){
                sound.setVolume(sound.getVolume()-0.1);
                break;
            }
            break;
             
          
        case '=':                  // Increase Volume
            while(sound.getVolume()<1){
                sound.setVolume(sound.getVolume()+0.1);
                break;
            }
            break;
    }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed

    
   

    if(playback == false){
        switch(key){
        case 'p':
            if(playing){
                sound.stop();
            }else{
                sound.play();
            }
            playing = !playing;
            break;
        case '1':
            mode = '1';
            ofSetBackgroundColor(0, 255, 191);
            rgbMode1[0] = ofRandom(256);
            rgbMode1[1] = ofRandom(256);
            rgbMode1[2] = ofRandom(256);
            
            break;
        case '2':
            mode = '2';
            ofSetBackgroundColor(247, 128, 231);
            rgbMode2[0] = ofRandom(256);
            rgbMode2[1] = ofRandom(256);

            break;
        case '3':
            mode = '3';
            ofSetBackgroundColor(239,231,79);
            rgbMode3[0] = ofRandom(256);
            rgbMode3[1] = ofRandom(256);
            rgbMode3[2] = ofRandom(256);

            break;

        case 'a':
            if (playing) {
                visualizer_running = !visualizer_running;
            }

            if (playing) {
                if (visualizer_running) {
                    sound.play();
                } else {
                    sound.stop();
                }
            }
            break;

        case 'd':
            playSong("geesebeat.wav");
            break;

        case 'f':
            playSong("beat.wav");
            break;

        case 'g':
            playSong("pigeon-coo.wav");
            break;

        case 'h':
            playSong("rock-song.wav");
            break;

        case 'v':
            playSong("lasanta.wav");
            break;

        case 'b':
            playSong("thespins.wav");
            break;

        case 'n':
            playSong("walkingdream.wav");
            break;

        case '-':                   // Decrease volume
            while(sound.getVolume()>0){
                sound.setVolume(sound.getVolume()-0.1);
                break;
            }
            break;
             
          
        case '=':                  // Increase Volume
            while(sound.getVolume()<1){
                sound.setVolume(sound.getVolume()+0.1);
                break;
            }
            break;
        case 'R':  
            if (record == false){
                record =true;
                actions.clear();
            }
            else{
                record = false;
            }
            break;
        case 'P':
            if (playback == false){
                playback =true;
            }
            else{
                playback = false;
            }
            break;

        
    
        
        }
    }
    else{
        if(key == 'C'){
            playback = false;
        }
    }

    if(record == true){
        actions.push_back(key);
    }
}

void ofApp::playSong(string file) {
    if (playing && loaded_sound != file) {
        sound.stop();
        sound.loadSound(file);
        loaded_sound = file;
        sound.play();
    } else if (!playing) {
        sound.loadSound(file);
        loaded_sound = file;
    }
}     
        

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
