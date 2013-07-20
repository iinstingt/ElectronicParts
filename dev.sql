-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Июл 20 2013 г., 12:28
-- Версия сервера: 5.5.25
-- Версия PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `dev`
--

-- --------------------------------------------------------

--
-- Структура таблицы `mcu`
--

CREATE TABLE IF NOT EXISTS `mcu` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` int(11) NOT NULL,
  `package` int(11) NOT NULL,
  `decr` text NOT NULL,
  `Model` varchar(255) NOT NULL,
  `RAM` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Дамп данных таблицы `mcu`
--

INSERT INTO `mcu` (`id`, `pid`, `package`, `decr`, `Model`, `RAM`) VALUES
(1, 14, 3, '', 'ATMega32', '32K'),
(2, 14, 4, '', 'ATMega328', '32K');

-- --------------------------------------------------------

--
-- Структура таблицы `packs`
--

CREATE TABLE IF NOT EXISTS `packs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `photo` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Дамп данных таблицы `packs`
--

INSERT INTO `packs` (`id`, `name`, `photo`) VALUES
(1, '1206', ''),
(2, '0805', ''),
(3, 'DIP40', ''),
(4, 'DIP28', '');

-- --------------------------------------------------------

--
-- Структура таблицы `parent`
--

CREATE TABLE IF NOT EXISTS `parent` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=16 ;

--
-- Дамп данных таблицы `parent`
--

INSERT INTO `parent` (`id`, `pid`, `name`) VALUES
(1, 1, '/'),
(2, 1, 'MCU'),
(4, 1, 'Resistor'),
(5, 1, 'Diode'),
(6, 4, 'SMD'),
(7, 4, 'Ext'),
(8, 6, '1206'),
(9, 6, '0805'),
(10, 2, 'Atmel'),
(11, 2, 'STM'),
(12, 10, '8-bit'),
(13, 10, '32-bit'),
(14, 12, 'Mega'),
(15, 12, 'Tiny');

-- --------------------------------------------------------

--
-- Структура таблицы `resistor`
--

CREATE TABLE IF NOT EXISTS `resistor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` int(11) NOT NULL,
  `Resistanse` int(11) NOT NULL,
  `Power` float NOT NULL,
  `Package` int(11) NOT NULL,
  `Decr` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Дамп данных таблицы `resistor`
--

INSERT INTO `resistor` (`id`, `pid`, `Resistanse`, `Power`, `Package`, `Decr`) VALUES
(1, 9, 1000, 0.125, 2, ''),
(2, 9, 10000, 0.125, 2, ''),
(3, 8, 510, 0.25, 1, ''),
(4, 8, 100, 0.25, 1, '');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
