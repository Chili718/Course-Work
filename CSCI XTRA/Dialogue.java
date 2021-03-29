//Author: Jon Tice and Jacob Decapua

import java.util.Random;
import java.awt.*;
import javax.swing.*; 
import java.awt.event.*;

public class Dialogue extends JPanel{
	
	private int numCompanions, speakerIndex, listenerIndex, randomCompan, randomNum, randomCompanStore, randMainSong, proposerIndex, reponderIndex;
	private JPanel buttonPanel, companionPanel;
	private Companion companionList[];
	private Random rand;
	private Timer dialogueTimer, exitTimer;
	private JButton reportButton, startButton, stopButton, exitButton, stopMusicButton, playMusicButton, identifyButton, resetButton, commentButton, treatyButton;
	private AudioPlayer player;
	
	public Dialogue(){
		
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		
		player = new AudioPlayer();
		
		setButtonPanel();
		
		setCompanionPanel();
		
		identifyCompanions();
		
		randomCompan = rand.nextInt(8);
		
	}
	public void createCompanions(){
		
		companionList[0] = new Companion("Danse", "Paladin", "The Prydwen", "Brotherhood", "Ad Victorian", Color.gray, new ImageIcon("danse.jpg"), player, "atom.au", "Ad Victorian civilian!", "I will do whatever it takes to protect the Commonwealth.", "day n night.au");
		companionList[1] = new Companion("Codsworth", "Sir", "Sanctuary", "Rob-Co", "Salutations", Color.cyan, new ImageIcon("codsworth.jpg"), player, "wanderer.au", "Have a great day sir!", "I am here to serve the wanderer of the Commonwealth.", "Cky.au");
		companionList[2] = new Companion("Deacon", "Agent", "The Old North Church", "Railroad", "Whats shakin'", Color.magenta, new ImageIcon("deacon.jpg"), player, "ama.au", "Keep it rocking dude!", "Why can't we have a nuclear winter?", "dirty harry.au");
		companionList[3] = new Companion("Hancock", "Mayor", "Goodneighbor", "Goul", "Whats Up", Color.red, new ImageIcon("hancock.jpg"), player, "19.au", "See you later.", "It's all about the freedom of the people in Goodneighbor.", "do it for love.au");
		companionList[4] = new Companion("Nick", "Detective", "Diamond City", "Synth", "Greetings", Color.orange, new ImageIcon("nick.jpg"), player, "clint.au", "Catch you later.", "If I could onyl remove the mystery behind the mysterious stranger.", "lalala.au");
		companionList[5] = new Companion("Piper", "Reporter", "Diamond City", "Publick Occurrences", "Hey", Color.pink, new ImageIcon("piper.jpg"), player, "demon.au", "Remember trust nobody.", "The people have the right to the information they want.", "remember the name.au");
		companionList[6] = new Companion("Preston", "Commander", "Fort Strong", "Minute Men", "Hello", Color.green, new ImageIcon("preston.jpg"), player, "feel.au", "Goodbye!", "I will make sure the Minute Men are restored to there former glory.", "stylo.au");
		companionList[7] = new Companion("Strong", "Mutant", "Trinity Tower", "Super Mutant", "'Loud Giberish'", Color.white, new ImageIcon("strong.jpg"), player, "el.au", "'More Loud Giberish'", "Strong wants to find the milk of humans that make them strong.", "we rise.au");
		
	}
	public void identifyCompanions(){
		
		for(int i = 0; i <= numCompanions-1; i++){
			
			companionList[i].identify();
			
		}
		
	}
	public void reportCompanions(){
		
		for(int i = 0; i <= numCompanions-1; i++){
			
			companionList[i].report();
			
		}
		
	}
	public void addCompanions(){
		
		for(int i = 0; i <= numCompanions-1; i++){//see about changing the 8 to numCompanions
			
			companionPanel.add(companionList[i]);
			
		}
		
	}
	public void stateIdentity(){
		
		for(int i = 0; i <= numCompanions-1; i++){//see about changing the 8 to numCompanions
			
			companionList[i].identifyCompanion();
			
		}
		
	}
	public void goodbyeCompanions(){
		
		for(int i = 0; i <= numCompanions-1; i++){//see about changing the 8 to numCompanions
			
			companionList[i].sayGoodbye();
			
		}
		
	}
	public void makeComments(){
		
		randomNum = rand.nextInt(8)+1;
		
		for(int i = 0; i <= randomNum; i++){
			
			randomCompanStore = randomCompan;
			
			companionList[randomCompan].comment();
			
			randomCompan = rand.nextInt(8);
			
			while(randomCompan == randomCompanStore){
				
				randomCompan = rand.nextInt(8);
				
			}

		}

	}
	public void talk(){
		
		speakerIndex = rand.nextInt(numCompanions);
		listenerIndex = rand.nextInt(numCompanions);
		
		while(speakerIndex == listenerIndex){
			speakerIndex = rand.nextInt(numCompanions);
		}
		
		companionList[speakerIndex].sayHiTo(companionList[listenerIndex]);
		
	}
	public void treaty(){
		
		proposerIndex = rand.nextInt(numCompanions);
		reponderIndex = rand.nextInt(numCompanions);
		
		while(proposerIndex == reponderIndex){
			reponderIndex = rand.nextInt(numCompanions);
		}
		
		companionList[proposerIndex].proposeTreatyTo(companionList[reponderIndex]);
		
	}
	public void setCompanionPanel(){
		
		companionPanel = new JPanel();
		
		add(companionPanel);
		
		rand = new Random();
		
		numCompanions = 8;
		
		companionList = new Companion[numCompanions];
		
		dialogueTimer = new Timer(rand.nextInt(3000)+500, new DialogueTimerListener());
		
		exitTimer = new Timer(4000, new ExitTimerListener());
		
		companionPanel.setLayout(new GridLayout(4,2));
		
		createCompanions();
		
		addCompanions();
		
	}
	public void setButtonPanel(){
		
		buttonPanel = new JPanel();
		
		add(buttonPanel);
		
		reportButton = new JButton("Report");
		
		startButton = new JButton("Start Conversation");
		
		stopButton = new JButton("Stop Conversation");
		
		exitButton = new JButton("Exit");
		
		stopMusicButton = new JButton("Stop Music");
		
		playMusicButton = new JButton("Play Music");
		
		identifyButton = new JButton("Identify Companions");
		
		resetButton = new JButton("Reset");
		
		commentButton = new JButton("Comment");
		
		treatyButton = new JButton("Propose A Treaty");
		
		reportButton.addActionListener(new ReportButtonListener());
		
		startButton.addActionListener(new StartButtonListener());
		
		stopButton.addActionListener(new StopButtonListener());
		
		exitButton.addActionListener(new ExitButtonListener());
		
		stopMusicButton.addActionListener(new StopMusicButtonListener());
		
		playMusicButton.addActionListener(new PlayMusicButtonListener());
		
		identifyButton.addActionListener(new IdentifyCompanionButtonListener());
		
		resetButton.addActionListener(new ResetButtonListener());
		
		commentButton.addActionListener(new CommentButtonListener());
		
		treatyButton.addActionListener(new TreatyButtonListener());
		
		buttonPanel.add(reportButton);
		
		buttonPanel.add(identifyButton);
		
		buttonPanel.add(commentButton);
		
		buttonPanel.add(treatyButton);
		
		buttonPanel.add(startButton);
		
		buttonPanel.add(stopButton);
		
		buttonPanel.add(playMusicButton);
		
		buttonPanel.add(stopMusicButton);
		
		buttonPanel.add(resetButton);
		
		buttonPanel.add(exitButton);
		
	}
	public void reset(){
		
		for(int i = 0; i <= numCompanions-1; i++){//see about changing the 8 to numCompanions
			
			companionList[i].resetCompanions();
			
		}
		
	}
	private class DialogueTimerListener implements ActionListener{

		public void actionPerformed(ActionEvent evt){
			
			talk();
			
		}
	}
	private class ReportButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			reportCompanions();
			
		}
	}
	private class StartButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			dialogueTimer.start();
			
		}
	}
	private class StopButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			dialogueTimer.stop();
			
		}
	}
	private class ExitTimerListener implements ActionListener{

		public void actionPerformed(ActionEvent evt){ 
		
			System.exit(0);
		}
	}
	private class StopMusicButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			player.stop();
			
		}
	}
	private class PlayMusicButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 	
			
			randMainSong = rand.nextInt(2);
			
			if(randMainSong == 1){
				
				player.playFromFile("main.au");
				
			}else if(randMainSong == 0){
				
				player.playFromFile("Dan Croll.au");
				
			}
		}
	}
	private class IdentifyCompanionButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			stateIdentity();
			
		}
	}
	private class ResetButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			reset();
			
		}
	}
	private class CommentButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			makeComments();
			
		}
	}
	private class TreatyButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			treaty();
			
		}
	}
	private class ExitButtonListener implements ActionListener{
		
		public void actionPerformed(ActionEvent evt){ 
		
			dialogueTimer.stop();
			goodbyeCompanions();
			exitTimer.start();
		}
	}
}