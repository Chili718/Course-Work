<!--
Assignment Number: 4

Description:Processes the form submitted and prints an itemized receipt of the order

Name: Jon Tice

Class: CSCI 297

Date: 10/4/2018
-->
<html>
<body>
<P>
<center>

<?php

$name = $_POST['name'];
$address = $_POST['address'];
//$print will contain the boolean value that will prevent or allow 
//the receipt to be printed
$print = TRUE;
//if the user did not enter a name and or an address the reciept will not print
if(strlen($name) == 0)
{
	echo "ERROR - Must Enter Name for Shipping. <br>";
	$print = FALSE;
	
}
if(strlen($address) == 0)
{
        echo "ERROR - Must Enter Address for Shipping. <br>";
	$print = FALSE;
}

//if the user gave a non integer, negative integer, or did not order anything the receipt will not print
if(is_numeric($_POST['PBJ']) != TRUE || is_numeric($_POST['Turkey']) != TRUE || is_numeric($_POST['Ham']) != TRUE || is_numeric($_POST['Grilled']) != TRUE )
{
	echo "ERROR - non integer value given.";
        $print = FALSE;
}
else
{
       	$sumT = $_POST['PBJ']+$_POST['Ham']+$_POST['Turkey']+$_POST['Grilled'];

	if($sumT == 0)
	{
        	echo "ALERT - You didn't order anything!";
        	$print = FALSE;
	}
	elseif(($_POST['PBJ']*$_POST['Ham']*$_POST['Turkey']*$_POST['Grilled']) < 0)
	{
        	echo "ERROR - You cannot order a negative number of items.";
        	$print = FALSE;
	}
	elseif(is_int($sumT) == FALSE)
	{
        	echo "ERROR - integers must be entered for amount.";
        	$print = FALSE;
	}
}

if($print == TRUE)
{
	//calculate the total
	$total = ($_POST['PBJ']*2.00);
	$total += ($_POST['Ham']*3.50);
	$total += ($_POST['Turkey']*3.00);
	$total += ($_POST['Grilled']*3.50);
	//calculate the sales tax and add it to the total
	$salesT = $total * 0.09;
	$total += $salesT;

	//echo money_format('$%i', $total);
	
	//print the itemized receipt
	echo "Your Orders Receipt: <br>";
	echo "<div align='left'>";
       	echo "------------------------------------------------------------------------<br>";	
	echo "Customer Name: " . $name . "<br>";
	echo "Delivery Address: " . $address . "<br>";

	echo "------------------------------------------------------------------------<br>";
	echo "<table style = 'width:50%''><tr><th>Item</th><th>Count</th><th>Price</th></tr>";
	//if the user did not order it then there is no need to print that
	if($_POST['PBJ'] != 0)
	{
		echo "<tr>";
        	echo "<td>Peanut Butter and Jelly</td>";
        	echo "<td>" . $_POST['PBJ'] . "</td>";
        	echo "<td>" . money_format('$%i',($_POST['PBJ']*2.00)) . "</td>";
        	echo "</tr>";
	}

	if($_POST['Ham'] != 0)
        {
		echo "<tr>";
        	echo "<td>Ham and Cheese</td>";
		echo "<td>" . $_POST['Ham'] . "</td>";
		echo "<td>" . money_format('$%i',($_POST['Ham']*3.50)) . "</td>";
		echo "</tr>";
	}

	if($_POST['Turkey'] != 0)
        {
		echo "<tr>";
        	echo "<td>Turkey</td>";
        	echo "<td>" . $_POST['Turkey'] . "</td>";
        	echo "<td>" . money_format('$%i',($_POST['Turkey']*3.00)) . "</td>";
		echo "</tr>";
	}

	if($_POST['Grilled'] != 0)
        {
		echo "<tr>";
        	echo "<td>Grilled Cheese</td>";
        	echo "<td>" . $_POST['Grilled'] . "</td>";
        	echo "<td>" . money_format('$%i',($_POST['Grilled']*3.50)) . "</td>";
        	echo "</tr>";
	}

	echo "<tr>";
        echo "<td></td><td> Sales Tax: </td>";
	echo "<td>" . money_format('$%i', $salesT) . "</td>";
        echo "</tr>";

	echo "<tr>";
        echo "<td></td><td> Total: </td>";
	echo "<td>" . money_format('$%i', $total) . "</td>";
	echo "</tr></table>";
	echo "------------------------------------------------------------------------";
	echo "</div>";
	
}

?>

</body>
</html>
