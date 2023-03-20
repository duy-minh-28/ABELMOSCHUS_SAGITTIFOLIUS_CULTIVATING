<?php
$servername = "localhost";
$username = "khoa";
$password = "123";
$dbname = "iop_db1";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$date_value = $_GET['date_value'];
$temp_value = $_GET['temp_value'];
$light_value = $_GET['light_value'];
$soil_moisture_value = $_GET['soil_moisture_value'];

$sql = "INSERT into sensorvaluetb(date_value, temp_value, light_value, soil_moisture_value) 
        values('$date_value','$temp_value','$light_value','$soil_moisture_value')"; 

if ($conn->query($sql) === TRUE) {
    echo "sensorvaluetb updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?>
