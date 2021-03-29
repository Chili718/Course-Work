<!--
Assignment Number: 6

Description:Processes the form submitted and writes the appointments to a file

Name: Jon Tice

Class: CSCI 297

Date: 10/19/2018
-->
<html>
<body>
<P>
<center>

<?php
	//if the student did not enter a first/last name or choose an appointment time 
	//the appropriate error message will be given 
	if($_POST['stud_f_name'] == "" || $_POST['stud_l_name'] == "")
	{
		echo "ERROR: Students must enter first and last name!";
	}
	else if(!isset($_POST['aptslot']))
        {
                echo "ERROR: No appointment was selected!";
	}
	else
	{

		//remove the appointment time from the ones availiable
		$remtext = $_POST['aptslot'];
      
      		$filelines = file("/tmp/apptTimesJT.txt");  // get contents of file
      		$fh = fopen("/tmp/apptTimesJT.txt", "w");   // overwrite old file
      		foreach ($filelines as $lines)
        	{
        		$lines = trim($lines);             // remove the \n character
        		if (strcmp($remtext, $lines) != 0)    //re write all the lines but the one to be removed
            			fwrite($fh, $lines . "\n");
        	}
      		fclose ($fh); //close the file
		//write the appointment time to the file
		$fp = fopen("/tmp/schedTimeJT.txt", "a") or die ("File was not able to be opened");
		
		$appt = $_POST['stud_l_name'] . " " . $_POST['stud_f_name'] . " ". $_POST['aptslot'];
		fwrite($fp, $appt . "\n");

		fclose($fp);

		echo "You have successfully registered for an appointment at: " . $_POST['aptslot'];	
	}
?>

</body>
</html>
