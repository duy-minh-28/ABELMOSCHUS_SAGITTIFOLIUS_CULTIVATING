<?php
$servername = "localhost";
$username = "root";
$password = "Ditmecuocdoi2806";
$dbname = "smart_trash_bin";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sectionID = $_GET['sectionID'];
$organicWaste_kg = $_GET['organicWaste_kg'];
$inorganicWaste_kg = $_GET['inorganicWaste_kg'];

$sql = "INSERT into Section(SectionID, OrganicWaste_kg, InorganicWaste_kg) values('$sectionID','$organicWaste_kg','$inorganicWaste_kg')";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?>
