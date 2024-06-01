-- phpMyAdmin SQL Dump
-- version 5.2.1deb1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 01, 2024 at 12:15 PM
-- Server version: 10.11.4-MariaDB-1~deb12u1
-- PHP Version: 8.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `api`
--

-- --------------------------------------------------------

--
-- Table structure for table `deteksi_api`
--

CREATE TABLE `deteksi_api` (
  `id` int(11) NOT NULL,
  `value_api` int(11) DEFAULT NULL,
  `jarak_api` int(11) DEFAULT NULL,
  `waktu_input` timestamp NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `deteksi_api`
--

INSERT INTO `deteksi_api` (`id`, `value_api`, `jarak_api`, `waktu_input`) VALUES
(1, 3886, 9, '2024-06-01 11:46:35'),
(2, 3169, 35, '2024-06-01 11:52:30'),
(3, 4, 150, '2024-06-01 11:53:01'),
(4, 2, 150, '2024-06-01 11:53:02');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `deteksi_api`
--
ALTER TABLE `deteksi_api`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `deteksi_api`
--
ALTER TABLE `deteksi_api`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
