<!--
Assignment Number: 8

Description:Allows us to add and delete records from the warehouse table 

Name: Jon Tice

Class: CSCI 297

Date: 11/6/2018
-->
<html>
<hr>
<table rules=all border=5>
<tr>
<td bgcolor=black colspan=4 align=center><font color=white>Existing Warehouses
<tr>
<td bgcolor=lightgrey>WhNumb</td>
<td bgcolor=lightgrey>City</td>
<td bgcolor=lightgrey>Floors</td>
<td bgcolor=lightgrey></td>
</tr>

<?php
// connect the database

// connect the database
$DBconn = new mysqli ("deltona.birdnest.org", "my.ticej2", "ihw8f18v", "my_ticej2_default");
//check if the connection was successful
if ($DBconn->connect_error) {
    die("Connection failed: " . $DBconn->connect_error);
}
//if the recid is set then that record will be deleted
if(isset($_POST['recid']))
{
	$del = $_POST['recid'];
	$query  = "DELETE FROM warehouse WHERE WhNumb = '$del'";
        $result = mysqli_query ($DBconn, $query);
}
else if (isset($_POST['City']) && isset($_POST['WhNumb']) && isset($_POST['Floors']))
{
   	$WhNumb = $_POST['WhNumb'];
   	$City   = $_POST['City'];
   	$Floors = $_POST['Floors'];
   	$query  = "INSERT INTO warehouse VALUES ('$WhNumb', '$City', $Floors)";
   	$result = mysqli_query ($DBconn, $query);
}

// submit and process the query for existing warehouses
$query = "select * from warehouse;";
$result = mysqli_query ($DBconn, $query);

while ($row = mysqli_fetch_object ($result))
{
	//create a form for each record that will allow them to be deleted
	echo ("<tr> <td> $row->WhNumb </td><td> $row->City </td><td> $row->Floors </td>");
	echo("<td> <form action=assignment8.php method=post>"); 
	echo("<input type='hidden' name='recid' value='$row->WhNumb'> <input type=submit value='Delete'> ");
	echo("</form></td></tr>");
}

?>

</table>
<P>
<hr>
<P>

<form action=assignment8.php method=post>
<pre>
       New Warehouse Info:
WhNumb <input type=text name="WhNumb">
  City <input type=text name="City">
Floors <input type=text name="Floors">
       <input type=submit value="Add Record">
</pre>
</form>
<P>
<hr>
</html>
