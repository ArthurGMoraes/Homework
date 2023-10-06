package model;

import java.io.Serializable;

public class Discussao implements Serializable {
	private static final long serialVersionUID = 1L;
	private int id;
	private String marca;
	private String modelo;
	private String motor;
	private int ano;
	
	public Discussao() {
		id = -1;
		marca = "nao definido";
		modelo = "nao definido";
		motor = "nao definido";
		ano = -1;
	}

	public Discussao(int id, String marca, String modelo, String motor, int ano) {
		setId(id);
		setMarca(marca);
		setModelo(modelo);
		setMotor(motor);
		setAno(ano);
	}		
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	
	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		if (marca.length() >= 2)
			this.marca = marca;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		if (modelo.length() >= 2)
			this.modelo = modelo;
	}

	public String getMotor() {
		return motor;
	}

	public void setMotor(String motor) {
		if (motor.length() >= 1)
			this.motor = motor;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}
	



	/**
	 * Método sobreposto da classe Object. É executado quando um objeto precisa
	 * ser exibido na forma de String.
	 */
	@Override
	public String toString() {
		return "marca: " + marca + "   modelo: " + modelo + "   motor: " + motor + "   Ano: "
				+ ano ;
	}
	
	@Override
	public boolean equals(Object obj) {
		return (this.getId() == ((Discussao) obj).getId());
	}	
}