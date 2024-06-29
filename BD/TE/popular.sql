-- Fabrica table
INSERT INTO `mydb`.`Fabrica` (`Cidade`) VALUES ('Betim'), ('Jacareí'), ('Anápolis');

-- Funcionario table
INSERT INTO `mydb`.`Funcionario` (`Nome`, `Cargo`, `Salario`, `Fabrica_Cidade`, `Funcionario_ID`, `Fabrica_Cidade1`)
VALUES 
('Pedro Augusto', 1, 10000.00, 'Betim', 2, 'Betim'),
('Lorenzo Costa', 2, 7000.00, 'Betim', 2, NULL),
('Marcos Silva', 3, 5500.00, 'Betim', 2, NULL);

-- Cliente table
INSERT INTO `mydb`.`Cliente` (`CPF`, `Nome`, `Contato`)
VALUES 
(12345678901, 'Márcia Regina ', 34123456789),
(98765432109, 'Henrique Villefort', 31987654311),
(45612378912, 'Rafael Pena', 31999999999);

-- Carro table
INSERT INTO `mydb`.`Carro` (`Chassi`, `Modelo`, `Ano`, `Fabrica_Cidade`, `Cliente_CPF`)
VALUES 
(1001, 'Model S', '2023-01-01', 'Betim', 12345678901),
(1002, 'Model X', '2023-02-01', 'Betim', 98765432109),
(1003, 'Model 3', '2023-03-01', 'Anápolis', 45612378912);

-- Peça table
INSERT INTO `mydb`.`Peça` (`Numero`, `Descricao`)
VALUES 
(2001, 'Motor'),
(2002, 'Embreagem'),
(2003, 'Freios');

-- Distribuidor table
INSERT INTO `mydb`.`Distribuidor` (`Nome`, `Contato`)
VALUES 
('Ford', 21111111111),
('Bosch', 31222222222),
('Axios', 11333333333);

-- Linha de Montagem table
INSERT INTO `mydb`.`Linha de Montagem` (`Numero`, `Produção`, `Fabrica_Cidade`)
VALUES 
(1, 100, 'Betim'),
(2, 150, 'Betim'),
(3, 200, 'Jacareí');

-- Populating the Usa table
INSERT INTO `mydb`.`Usa` (`Peça_Numero`, `Carro_Chassi`)
VALUES 
(2001, 1001),
(2002, 1002),
(2003, 1003);

-- Populating the Distribui table
INSERT INTO `mydb`.`Distribui` (`Peça_Numero`, `Distribuidor_Nome`, `Preço`)
VALUES 
(2001, 'Ford', 5200.00),
(2002, 'Ford', 3200.00),
(2003, 'Ford', 1700.00);