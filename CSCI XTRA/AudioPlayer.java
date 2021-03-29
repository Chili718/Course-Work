//********************************************************************
//  AudioPlayer.java       Author: McKim & Lewis/Loftus
//
//  Plays Audio clips.
//********************************************************************

import javax.swing.*;
//import java.awt.*;
//import java.awt.event.*;
//import java.io.*;
import java.applet.*;
import java.net.*;

public class AudioPlayer
{

   private URL url, myURL;
   private AudioClip current, myCurrent;


   //-----------------------------------------------------------------
   //  Constructor: Reads the provided sound file and prepares it for playing.
   //-----------------------------------------------------------------
   public AudioPlayer(String soundFileName)
   {
      
      try
      {
	url = new URL ("file", "localhost", soundFileName);
      }
      catch (Exception exception){};

      current = JApplet.newAudioClip (url);


   }

   //-----------------------------------------------------------------
   //  Constructor: Reads the provided sound file and prepares it for playing.
   //-----------------------------------------------------------------
   public AudioPlayer(){}

   public void play()
	   // Call this routine if you created the player with a sound file.
   {
		current.play();
   }

   public void playFromFile (String soundFileName)
	   // Call this routine to play the sound in the file.
   {

      try
      {
        myURL = new URL ("file", "localhost", soundFileName);
      }
      catch (Exception exception){};
	   if (myCurrent != null){myCurrent.stop();}
      myCurrent = JApplet.newAudioClip (myURL);
      myCurrent.play();
   }

	public void stop()
		// Stops playing
	{
		if (myCurrent != null){myCurrent.stop();}
		if (current != null){current.stop();} // Added by CLPG
	}


}
