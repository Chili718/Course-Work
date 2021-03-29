-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Mar 05, 2019 at 10:26 PM
-- Server version: 5.7.24
-- PHP Version: 7.0.33-0+deb9u2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `assm3`
--

-- --------------------------------------------------------

--
-- Table structure for table `cardCollection`
--

CREATE TABLE `cardCollection` (
  `PrimaryKey` int(5) NOT NULL,
  `userPrimaryKey` int(11) NOT NULL,
  `cardName` varchar(100) NOT NULL,
  `cardNumber` varchar(10) NOT NULL,
  `cardValue` varchar(10) NOT NULL,
  `amountOwned` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `cardCollection`
--

INSERT INTO `cardCollection` (`PrimaryKey`, `userPrimaryKey`, `cardName`, `cardNumber`, `cardValue`, `amountOwned`) VALUES
(13, 9, '1983 Topps Tony Gwynn RC', '482', '75.21', '2'),
(14, 9, '1984 Fleer Update Roger Clemens', '27', '120.00', '2'),
(15, 9, '1983 Topps Ryne Sandberg', '83', '20.00', '4'),
(16, 9, '1984 Donruss Joe Carter RC', '41', '8', '3'),
(17, 9, '1984 Donruss Don Mattingly', '248', '40', '10'),
(18, 9, '1984 Donruss Darryl Strawberry', '68', '12', '5'),
(19, 10, '1983 Topps Tony Gwynn RC', '482', '75.21', '1'),
(20, 10, '1984 Fleer Update Roger Clemens', '27', '120.00', '2'),
(21, 10, '1983 Topps Ryne Sandberg', '83', '20.00', '0'),
(22, 10, '1984 Donruss Darryl Strawberry', '68', '12', '8'),
(23, 11, '1983 Topps Tony Gwynn RC', '482', '75.21', '1'),
(24, 11, '1984 Fleer Update Roger Clemens', '27', '120.00', '2'),
(25, 11, '1983 Topps Ryne Sandberg', '83', '20.00', '1'),
(26, 11, '1984 Donruss Joe Carter RC', '41', '8', '4'),
(27, 11, '1984 Donruss Darryl Strawberry', '68', '12', '4'),
(28, 11, '1984 Donruss Don Mattingly', '248', '40', '5');

-- --------------------------------------------------------

--
-- Table structure for table `saleCollection`
--

CREATE TABLE `saleCollection` (
  `PrimaryKey` int(5) NOT NULL,
  `cardName` varchar(100) NOT NULL,
  `cardNumber` varchar(10) NOT NULL,
  `cardCost` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `saleCollection`
--

INSERT INTO `saleCollection` (`PrimaryKey`, `cardName`, `cardNumber`, `cardCost`) VALUES
(1, '1984 Donruss Don Mattingly', '248', '40'),
(2, '1984 Donruss Joe Carter RC', '41', '8'),
(3, '1984 Donruss Darryl Strawberry', '68', '12');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `userPrimaryKey` int(11) NOT NULL,
  `userName` varchar(20) NOT NULL,
  `userPassword` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`userPrimaryKey`, `userName`, `userPassword`) VALUES
(9, 'jon', 'tice'),
(10, 'pat', 'pat'),
(11, 'bob', 'bob');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cardCollection`
--
ALTER TABLE `cardCollection`
  ADD PRIMARY KEY (`PrimaryKey`);

--
-- Indexes for table `saleCollection`
--
ALTER TABLE `saleCollection`
  ADD PRIMARY KEY (`PrimaryKey`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`userPrimaryKey`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cardCollection`
--
ALTER TABLE `cardCollection`
  MODIFY `PrimaryKey` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;
--
-- AUTO_INCREMENT for table `saleCollection`
--
ALTER TABLE `saleCollection`
  MODIFY `PrimaryKey` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `userPrimaryKey` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
