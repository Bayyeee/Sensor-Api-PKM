<?php
include 'koneksi.php';

// Mendapatkan data dari ESP32
$flameValue = $_GET['flameValue'];
$distance = $_GET['distance'];

// Menyiapkan pernyataan SQL untuk menyimpan data ke database
$sql = "INSERT INTO deteksi_api (value_api, jarak_api) VALUES ('$flameValue', '$distance')";

// Menjalankan pernyataan SQL
if ($conn->query($sql) === TRUE) {
    echo "Data inserted successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

// Menutup koneksi database
$conn->close();
