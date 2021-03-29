<?php
//connect to the database
$con = mysqli_connect("deltona.birdnest.org", "my.ticej2", "Chili71814", "my_ticej2_crud");

if(mysqli_connect_errno())
{
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$error = "";

if(isset($_POST['btndisplay']))
{
	
	$att = $con->real_escape_string($_POST['attribute_val']);
	$where = $con->real_escape_string($_POST['where_val']);
	//checking if anything was entered for each input box
	if(strlen($att) != 0 && strlen($where) != 0)
	{
		$selectQ = "SELECT $att FROM PROFILE WHERE $where";
		//$selectQ = $con->prepare("SELECT ? FROM PROFILE WHERE ?");

		//$selectQ->bind_param('ss', $att, $where);
		//$selectQ->execute();

		//echo $selectQ;

		 //$selectQ->close();
	}
	else if(strlen($att) != 0)
	{

		$selectQ = "SELECT $att FROM PROFILE";

		//$selectQ = $con->prepare("SELECT ? FROM PROFILE");

		//$selectQ->bind_param('s', $att);
                //$selectQ->execute();

                //echo $selectQ;

		//$selectQ->close();

	}
	else
	{
		$error = "ERROR: not valid sql query.";
	}
	
}
?>

<form action = "" method = "post">
	<table>
		<tr>
			<td colspan = "2"><span style = "color:red;"><?php echo $error; ?></td>
		</tr>
		<tr>
			<a href = "crud.php">Home</a>			
                </tr>
		<tr>
			<td>SELECT</td>
			<td><input type = "text" name = "attribute_val" value = ""></td>
			<td>FROM PROFILE WHERE</td>
			<td><input type = "text" name = "where_val" value = ""></td>
			<td><input type = "submit" value = "Submit" name = "btndisplay"></td>
		</tr>
	</table>
	<table cellpadding = "5" cellspacing = "0" border = "1">
        <tr>
                <th>id</th>
                <th>Name</th>
                <th>AcctID</th>
                <th>Action</th>
        </tr>
	<?php
	
	//will display the results from the query
	if(isset($_POST['btndisplay']) && strlen($att) != 0)
	{
		$query = mysqli_query($con, $selectQ);
		if(mysqli_num_rows($query)  > 0)
		{
        
        		while($row = mysqli_fetch_object($query))
        		{
		//each record will have an update and delete option
	?>
        <tr>
                <td><?php echo $row->id; ?></td>
                <td><?php echo $row->Name; ?></td>
                <td><?php echo $row->AcctID; ?></td>
                <td>
                        <a href = "insert.php?edited=1&id=<?php echo $row->id; ?>">Edit</a> |
                        <a href = "insert.php?deleted=1&id=<?php echo $row->id; ?>">Delete</a>
                </td>
        </tr>
	<?php
        		}
		}
		else
		{
			echo "0 rows in set.";
		}
		
	}
	?>
	</table>
</form>
