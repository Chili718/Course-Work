//Author: Jon Tice and Jacob Decapua

import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.Random;
import java.awt.event.*;

public class Companion extends JPanel{
	
	private String name, title, town, race, greeting, sound, goodbye, comment, sound2;
	private Random randCompanion, randomSound, randomTreaty;
	private Color companionColor, borderColor;
	private Timer delay;
	private ImageIcon companionPicture, buttonPic;
	private JLabel picLabel, idLabel, dialogueLabel, reportLabel, soundLabel;
	private int numDialogue, respondInt, randSnd, numTreaty, decisionTreaty;
	private Companion lastSpokenTo, speaking;
	private JButton companionMusic;
	private AudioPlayer companionPlayer;
	
	
	public String getName()
	{
		return name;
	}
	public String getTitle()
	{
		return title;
	}
	public String getTown()
	{
		return town;
	}
	public String getRace()
	{
		return race;
	}
	// A series of convenience functions follow
	public String getIdentity()
	{
		return title + " " + name ;
	}
	public String getIdentityWithTown()
	{
		return title + " " + name + " of " + town;
	}
	public String getIdentityWithRace()
	{
		return title + " " + name + " of the wonderful " + race;
	}
	public Companion(String nme, String ttl, String twn, String rce, String grt, Color clr, ImageIcon img, AudioPlayer plyr, String snd, String gby, String cmt, String snd2){
		
		numDialogue = 0;
		
		name = nme;
		
		title = ttl;
		
		town = twn;
		
		race = rce;
		
		greeting = grt;
		
		comment = cmt;
		
		companionColor = clr;
		
		companionPicture = img;
		
		companionPlayer = plyr;
		
		sound = snd;
		
		sound2 = snd2;
		
		goodbye = gby;
		
		randCompanion = new Random();
		
		randomSound = new Random();
		
		randomTreaty = new Random();
		
		setBackground(companionColor);
		
		setPreferredSize(new Dimension(600, 235));
		
		dispGraphics();
		
		setLayout(new BorderLayout());
		
		setBorder(BorderFactory.createLineBorder(Color.black, 4));
		
	}
	public void dispGraphics(){
		
		buttonPic = new ImageIcon("csci button.jpg");
		
		picLabel = new JLabel ("Picture area", SwingConstants.CENTER);
		
		idLabel = new JLabel ("ID area", SwingConstants.CENTER);
		
		reportLabel = new JLabel ("Reporting area", SwingConstants.CENTER);
		
		soundLabel = new JLabel ("Sound area", SwingConstants.CENTER);
		
		dialogueLabel = new JLabel ("Dialogue area", SwingConstants.CENTER);
		
		companionMusic = new JButton(buttonPic);
		
		picLabel.setHorizontalTextPosition(SwingConstants.LEFT);
		
		picLabel.setVerticalTextPosition(SwingConstants.BOTTOM);
		
		companionMusic.addActionListener(new CompanionMusicButtonListener());
		
	}
	public void identify(){
		
		borderColor = new Color(10, 10, 10, 0);
		
		LineBorder border1 = new LineBorder(borderColor, 4);
		
		LineBorder border2 = new LineBorder(Color.black, 4);
		
		Border newBorder = BorderFactory.createCompoundBorder(border1, border2);
		
		add(idLabel, BorderLayout.NORTH);
	    
		add(picLabel, BorderLayout.WEST); 
	    
		add(reportLabel, BorderLayout.SOUTH);
	    
		add(companionMusic, BorderLayout.EAST);
	    
		add(dialogueLabel, BorderLayout.CENTER);
	    
		picLabel.setIcon(companionPicture);
		
		picLabel.setBorder(newBorder);
	    
		picLabel.setHorizontalTextPosition(SwingConstants.CENTER);
	    
		picLabel.setVerticalTextPosition(SwingConstants.BOTTOM);
	   
	}
	public void identifyCompanion(){
		
		picLabel.setText("<html>" + title + " " + name + ".</html>");
		
		idLabel.setText("<html> <h2>" + getIdentityWithTown() + "</h2> </html>");
		
	}
	public void sayGoodbye(){
		
		dialogueLabel.setText("<html>" + goodbye + "</html>");
		
	}
	public void comment(){
		
		dialogueLabel.setText("<html>" + comment + "</html>");
		
	}
	public void sayHiTo(Companion otherCompanion){
		
		numDialogue++;
		
		dialogueLabel.setText("<html>" + greeting + ", " + otherCompanion.getIdentityWithTown() + ", this is " + title + " "+ name + " and I bring greetings from " + town + ".</html>");
		
		lastSpokenTo = otherCompanion;
		
		respondInt = randCompanion.nextInt(3);
		
		if(respondInt == 1){
			
			otherCompanion.respond(this);
			
		}
		
	}
	public void proposeTreatyTo(Companion treatyCompanion){
		
		numTreaty++;
		
		dialogueLabel.setText("<html>" + greeting + ", " + treatyCompanion.getIdentityWithTown() + ", this is " + title + " "+ name + " I would like to propose a treaty?" + "</html>");
		
		decisionTreaty = randomTreaty.nextInt(2);
		
		treatyCompanion.respondTreaty();
	}
	public void respondTreaty(){
		
		if(decisionTreaty == 0){
			
			dialogueLabel.setText("<html>" + "I will accecpt your treaty with flying colors." + "</html>");
			
		}else if(decisionTreaty == 1){
			
			dialogueLabel.setText("<html>" + "I am sorry I am not to fond of what you stand for so no." + "</html>");
			
		}
		
	}
	public void resetCompanions(){
		
		picLabel.setText("Picture area");
		
		idLabel.setText("ID area");
		
		reportLabel.setText("Reporting area");
		
		soundLabel.setText("Sound area");
		
		dialogueLabel.setText("Dialogue area");
		
		numDialogue = 0;
		
	}
	public void respond(Companion responder){
	
		dialogueLabel.setText("<html>" + greeting + " " + responder.getIdentity() + ".</html>");
		
	}
	public void report(){
		
		if(numDialogue == 0){
			
			reportLabel.setText("I need someone to talk to!");
			
		}else if(numDialogue == 1){
			
			reportLabel.setText("I have started only " + numDialogue + " conversation. The last person I spoke to was " + lastSpokenTo.getIdentity() + ".");
			
		}else{
			
			reportLabel.setText("<html>" + "I have started " + numDialogue + " conversations and have proposed " + numTreaty + " treaties. The last person I spoke to was " + lastSpokenTo.getIdentity() + "." + ".</html>");
			
		}
		
	}
	private class CompanionMusicButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
			
			randSnd = randomSound.nextInt(2);
			
			if(randSnd == 1){
				
				companionPlayer.playFromFile(sound);
				
			}else if(randSnd == 0){
				
				companionPlayer.playFromFile(sound2);
				
			}
			
		}
	}
}