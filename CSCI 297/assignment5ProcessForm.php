<!--
Assignment Number: 5

Description:Processes the form submitted and writes the times added to a file

Name: Jon Tice

Class: CSCI 297

Date: 10/19/2018
-->
<html>
<body>
<P>
<center>

<?php
	//checking if the professor chose a day and or time(s)
	if(!isset($_POST['date']))
	{
		echo "ERROR: No day selected!";
	}
	else if(!isset($_POST['timee']))
	{
		echo "ALERT: You did not pick any time for the day!";
	}
	else
	{
		$date = $_POST['date'];
		$timeRay = $_POST['timee'];
		//open the file for append to not get rid of previous times added
		$fp = fopen("/tmp/apptTimesJT.txt", "a") or die ("Could not open file for append.");
		
		sort($timeRay);
		//add the times with the date to the file for each time that day
		foreach($timeRay as $val)
		{
			fwrite($fp, $date . " " . $val . "\n");
		}

		echo sizeof($timeRay) . " new time(s) have been added.";

		fclose($fp);

		//remove dupicate lines if any 
		$cmd = "sort /tmp/apptTimesJT.txt | uniq";
		exec ($cmd, $output, $status);
		//if the command executed successfully then write out the new 
		//file containing no duplicates
		if ($status)
		{
         		echo "command failed<br>";
		}
		else
        	{
         		$fd = fopen ("/tmp/apptTimesJT.txt", "w"); // overwrite the old file
			foreach ($output as $line)// write each line into new file
			{
				fwrite ($fd, $line . "\n");
			}
         		fclose ($fd);
 		}

	}

?>

</body>
</html>
