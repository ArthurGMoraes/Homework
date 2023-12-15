package Ex2;

public class Discussao {
	private int id;
	private String marca;
	private String modelo;
	private String motor;
	private int ano;
	
	public Discussao() {
		this.id = -1;
		this.marca = "";
		this.modelo = "";
		this.motor = "";
		this.ano = -1;
	}
	
	public Discussao(int id, String marca, String modelo, String motor, int ano) {
		this.id = id;
		this.marca = marca;
		this.modelo = modelo;
		this.motor = motor;
		this.ano = ano;
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
		this.marca = marca;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getMotor() {
		return motor;
	}

	public void setMotor(String motor) {
		this.motor = motor;
	}
	
	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	@Override
	public String toString() {
		return "Discussao [Id=" + id + ", Marca=" + marca + ", Modelo=" + modelo + ", Motor=" + motor + ", Ano=" + ano + "]";
	}	
}
