-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 17-11-2018 a las 15:04:04
-- Versión del servidor: 5.7.23
-- Versión de PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `pruebita`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientes`
--

DROP TABLE IF EXISTS `clientes`;
CREATE TABLE IF NOT EXISTS `clientes` (
  `Codcliente` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `Apellido` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `Telefono` varchar(10) COLLATE utf8_spanish_ci NOT NULL,
  `Direccion` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `Correo` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`Codcliente`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `clientes`
--

INSERT INTO `clientes` (`Codcliente`, `Nombre`, `Apellido`, `Telefono`, `Direccion`, `Correo`) VALUES
(1, 'Keny ', 'Torres', '7185-8890', 'Canton El Papalon', 'chavez@gmail.com'),
(2, 'Roberto', 'Hernandez', '2514-5520', 'Col. Bella Vista', 'hernan@hotmail.es'),
(3, 'Luisa', 'Benavidez', '7542-9989', 'Ciudad Pacifica', 'bena@gmail.com');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cotizacion`
--

DROP TABLE IF EXISTS `cotizacion`;
CREATE TABLE IF NOT EXISTS `cotizacion` (
  `Codcotiza` int(11) NOT NULL AUTO_INCREMENT,
  `Codcliente` int(11) NOT NULL,
  `Codproducto` int(11) NOT NULL,
  `Fechacotiza` varchar(10) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`Codcotiza`,`Codcliente`,`Codproducto`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `cotizacion`
--

INSERT INTO `cotizacion` (`Codcotiza`, `Codcliente`, `Codproducto`, `Fechacotiza`) VALUES
(1, 1, 1, '17/11/2018'),
(2, 2, 2, '11/03/2018'),
(3, 3, 3, '31/10/2018');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

DROP TABLE IF EXISTS `productos`;
CREATE TABLE IF NOT EXISTS `productos` (
  `Codproducto` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(25) COLLATE utf8_spanish_ci NOT NULL,
  `Precio` varchar(10) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`Codproducto`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `productos`
--

INSERT INTO `productos` (`Codproducto`, `Nombre`, `Precio`) VALUES
(12, 'Queso', '$2.50 lb'),
(11, 'Javon', '$1.50 of');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
