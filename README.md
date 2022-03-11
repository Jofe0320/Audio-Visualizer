# PA1: Openframeworks Audiovisualizer
The objective for this first project is to complete this audiovisualizer with the help of OpenFrameworks!

# What it can do out of the box
After compiling and running the project for the first time, you should be able to do a couple of things:

- Using the "P" key, you should be able to play music from "beat.wav" 
- Using different number keys, you can visualize the music in different ways:
    - 1: Rectangle Height Visualizer
    - 2: Circle Radius Visualizer
    - 3: Rectangle Width Visualizer (to be implemented)
    - 4: Custom Visualizer (to be implemented)

# Classes
This project contains two classes that should be of your concern: ofApp and AudioVisualizer.

## ofApp
This is the class that brings most things together. Here, you will find the code that causes the audio to play and pause. It is also to where the visualization happens. Here, you can observe how the code to change between modes works, and how the song is actually played. 

## AudioVisualizer
The AudioVisualizer class provides us with the data needed to do the visualization. Using some of the tools OpenFrameworks provides us and math, we can obtain information such as the amplitude of the sound.


***********************************************
Yamil Morales - yamil.morales7@upr.edu
José Ortiz - jose.ortiz107@upr.edu

Songs:
'd' key plays geesebeat.wav
'f' key plays beat.wav
'g' key plays pigeon-coo.wav
'h' key plays rock-song.wav
'v' key plays La Santa by Bad Bunny
'b' key plays The Spins by Mac Miller
'n' key plays Walking On A Dream by Empire of the Sun
'z' key plays La Cura by Frankie Ruiz

Record-Mode
Used the the update method to cheq when every two second is complete using the % operator. Then proceeded to do every action again every 120 ticks (2s)
 record with 'r'
 replay with 't'


Bonus Specs
Mode 4 : 3d representation of mode 1; Instead of bars there are boxes move with the music.
      - Using the mouse you can:
         - navegate through the 3d world to see the shapes from different angles 
         -zoom in an zoom out as you will do in any web page
Skip foward and backwards:
       -with the left arrow key skip backward a song in the vector of songs
       -with the righ arrow key skip fowards a song in the vector
        



