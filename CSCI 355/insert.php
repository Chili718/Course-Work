<?php
//connect to the database
$con = mysqli_connect("deltona.birdnest.org", "my.ticej2", "Chili71814", "my_ticej2_crud");

if(mysqli_connect_errno())
{
        echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$error = "";
$delte = "";
$profName = "";
$acctId = "0";

//echo $_GET['id'];
//if the save button is clicked
if(isset($_POST['btnsave']))
{
	//retrieving the data entered/selected
	$nme = $_POST['txt_name'];
	$num = $_POST['acct_id'];
	//first checking that the entered data meets the criterion for the profile name
	if(strlen($nme) == 0)
	{
		$error = "Profile name must be at least 1 character!.";
	}
	else if(strlen($nme) > 64)
	{
		$error = "Profile name cannot be more than 64 characters!";	
	}
	else
	{
		if($_POST['txtid'] == "0")
		{
			//using prepared statements to prevent sql injection
			$cmd = $con->prepare("INSERT INTO PROFILE (Name, AcctID) VALUES (?, ?)");

			$cmd->bind_param('si', $nme, $num);
                        $cmd->execute();
			
			//echo $cmd;

			//$con->query($cmd);	

			$cmd->close();
	
			header('Refresh:0; crud.php');
		}
		else
		{
			//using prepared statements to prevent sql injection
			$cmd = $con->prepare("UPDATE PROFILE SET Name = ?, AcctID = ? WHERE id = ?");

			$cmd->bind_param('sii', $nme, $num, $_POST['txtid']); 
			$cmd->execute();

			//$con->query($cmd);

			//echo $cmd;

			$cmd->close();

			header('Refresh:0; crud.php');
		}

	}
}
//will check for the different parameters passed through the url to determine 
//if it is an update or delete if not an insert
if(isset($_GET['edited']))
{
        $stmt = $con->prepare("SELECT * FROM PROFILE WHERE id = ?");

	$stmt->bind_param('i', $_GET['id']);
	$stmt->execute();
        $query = $stmt->get_result();
        //$query = mysqli_query($con, $stmt);
        //$rw = mysqli_fetch_object($query);
	$rw = $query->fetch_assoc();
        $profName = $rw['Name'];
        $acctId = $rw['id'];
	//echo $acctId;
	$stmt->close();        
}

if(isset($_GET['deleted']))
{
	//using prepared statements to prevent sql injection
        $delte = $con->prepare("DELETE FROM PROFILE WHERE id = ?");

	$delte->bind_param('i', $_GET['id']);
        $delte->execute();

	//$con->query($delte);

	$delte->close();

	header('Refresh:0; crud.php');

}


?>

<form action = "" method = "post">
	<table>
		<tr>
			<td colspan = "2"><span style = "color:red;"><?php echo $error; ?></td>
		</tr>
		<tr>
			<td>Profile Name</td>
			<td><input type = "text" name = "txt_name" value = "<?php echo $profName; ?>"><input type = "hidden" name = "txtid" value = <?php echo $acctId; ?>></td>
		</tr>
		<tr>
			
		</tr>
		<tr>
			<td>Account ID</td>
			<td>
			
			<select name = 'acct_id'>
			<?php
			//display all the options for the Accoutn ID in a dropdown
			$sql = mysqli_query($con, "SELECT * FROM  USER_ACCOUNT");

			while ($row = mysqli_fetch_object($sql))
			{
			
				echo "<option  value = $row->id > $row->Email </option>";
			
			}
			?>

			</select>
			</td>
		</tr>
		<tr>
			<td></td>
			<td><input type = "submit" value = "Save" name = "btnsave"></td>
		</tr>
	</table>
</form>
