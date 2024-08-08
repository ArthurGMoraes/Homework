-- MySQL Script generated by MySQL Workbench
-- Fri Jun 28 00:08:12 2024
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Fabrica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Fabrica` (
  `Cidade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Cidade`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Funcionario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Funcionario` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `Nome` VARCHAR(45) NULL,
  `Cargo` INT NULL,
  `Salario` FLOAT NULL,
  `Fabrica_Cidade` VARCHAR(45) NOT NULL,
  `Funcionario_ID` INT NOT NULL,
  `Fabrica_Cidade1` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Funcionario_Fabrica_idx` (`Fabrica_Cidade` ASC) VISIBLE,
  INDEX `fk_Funcionario_Funcionario1_idx` (`Funcionario_ID` ASC) VISIBLE,
  INDEX `fk_Funcionario_Fabrica1_idx` (`Fabrica_Cidade1` ASC) VISIBLE,
  CONSTRAINT `fk_Funcionario_Fabrica`
    FOREIGN KEY (`Fabrica_Cidade`)
    REFERENCES `mydb`.`Fabrica` (`Cidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funcionario_Funcionario1`
    FOREIGN KEY (`Funcionario_ID`)
    REFERENCES `mydb`.`Funcionario` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Funcionario_Fabrica1`
    FOREIGN KEY (`Fabrica_Cidade1`)
    REFERENCES `mydb`.`Fabrica` (`Cidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Cliente`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Cliente` (
  `CPF` INT(11) NOT NULL,
  `Nome` VARCHAR(45) NULL,
  `Contato` INT(11) NULL,
  PRIMARY KEY (`CPF`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Carro`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Carro` (
  `Chassi` INT NOT NULL,
  `Modelo` VARCHAR(45) NULL,
  `Ano` DATE NULL,
  `Fabrica_Cidade` VARCHAR(45) NOT NULL,
  `Cliente_CPF` INT(11) NOT NULL,
  PRIMARY KEY (`Chassi`),
  INDEX `fk_Carro_Fabrica1_idx` (`Fabrica_Cidade` ASC) VISIBLE,
  INDEX `fk_Carro_Cliente1_idx` (`Cliente_CPF` ASC) VISIBLE,
  CONSTRAINT `fk_Carro_Fabrica1`
    FOREIGN KEY (`Fabrica_Cidade`)
    REFERENCES `mydb`.`Fabrica` (`Cidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Carro_Cliente1`
    FOREIGN KEY (`Cliente_CPF`)
    REFERENCES `mydb`.`Cliente` (`CPF`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Peça`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Peça` (
  `Numero` INT NOT NULL,
  `Descricao` VARCHAR(45) NULL,
  `Preço` FLOAT NULL,
  PRIMARY KEY (`Numero`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Distribuidor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Distribuidor` (
  `Nome` VARCHAR(45) NOT NULL,
  `Contato` INT(11) NULL,
  `Distribuidorcol` VARCHAR(45) NULL,
  PRIMARY KEY (`Nome`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Linha de Montagem`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Linha de Montagem` (
  `Numero` INT NOT NULL,
  `Produção` INT NULL,
  `Fabrica_Cidade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Numero`, `Fabrica_Cidade`),
  INDEX `fk_Linha de Montagem_Fabrica1_idx` (`Fabrica_Cidade` ASC) VISIBLE,
  CONSTRAINT `fk_Linha de Montagem_Fabrica1`
    FOREIGN KEY (`Fabrica_Cidade`)
    REFERENCES `mydb`.`Fabrica` (`Cidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Usa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Usa` (
  `Peça_Numero` INT NOT NULL,
  `Carro_Chassi` INT NOT NULL,
  PRIMARY KEY (`Peça_Numero`, `Carro_Chassi`),
  INDEX `fk_Peça_has_Carro_Carro1_idx` (`Carro_Chassi` ASC) VISIBLE,
  INDEX `fk_Peça_has_Carro_Peça1_idx` (`Peça_Numero` ASC) VISIBLE,
  CONSTRAINT `fk_Peça_has_Carro_Peça1`
    FOREIGN KEY (`Peça_Numero`)
    REFERENCES `mydb`.`Peça` (`Numero`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Peça_has_Carro_Carro1`
    FOREIGN KEY (`Carro_Chassi`)
    REFERENCES `mydb`.`Carro` (`Chassi`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Distribui`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Distribui` (
  `Peça_Numero` INT NOT NULL,
  `Distribuidor_Nome` VARCHAR(45) NOT NULL,
  `Preço` FLOAT NULL,
  PRIMARY KEY (`Peça_Numero`, `Distribuidor_Nome`),
  INDEX `fk_Peça_has_Distribuidor_Distribuidor1_idx` (`Distribuidor_Nome` ASC) VISIBLE,
  INDEX `fk_Peça_has_Distribuidor_Peça1_idx` (`Peça_Numero` ASC) VISIBLE,
  CONSTRAINT `fk_Peça_has_Distribuidor_Peça1`
    FOREIGN KEY (`Peça_Numero`)
    REFERENCES `mydb`.`Peça` (`Numero`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Peça_has_Distribuidor_Distribuidor1`
    FOREIGN KEY (`Distribuidor_Nome`)
    REFERENCES `mydb`.`Distribuidor` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;