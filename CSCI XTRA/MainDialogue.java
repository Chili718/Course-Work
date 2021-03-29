//Author: Jon Tice

import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class MainDialogue{
	
	public static void main(String[] args){
		
		Dialogue talk = new Dialogue();
		
		JFrame wind = new JFrame("Fallout 4 Companions");
		
		wind.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		wind.getContentPane().add(talk);
		wind.pack();
		wind.setVisible(true);
	}
	
}