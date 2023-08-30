package Ex2;
import java.util.Scanner;
import java.lang.String;

public class Principal {
	public static DAO dao = new DAO();
	public static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		dao.conectar();
		
		boolean exit = false;
	    
	    while (!exit) {
	        System.out.println("Menu:");
	        System.out.println("1. Create");
	        System.out.println("2. Read");
	        System.out.println("3. Update");
	        System.out.println("4. Delete");
	        System.out.println("5. Sair");
	        
	        System.out.print("Digite o numero da opcao: ");
	        int choice = scanner.nextInt();
	        scanner.nextLine(); 
	        
	        switch (choice) {
	            case 1:
	                create();
	                break;
	            case 2:
	                read();
	                break;
	            case 3:
	                update();
	                break;
	            case 4:
	                delete();
	                break;
	            case 5:
	                exit = true;
	                System.out.println("Saindo...");
	                break;
	            default:
	                System.out.println("Invalid choice");
	        }
	    }
        
		dao.close();
		scanner.close();
	}
	
	public static void create() {
		dao.conectar();
		
		//Inserir um elemento na tabela
		int id = dao.getLastId() + 1;
		
		System.out.println("Marca: ");
		String marca = scanner.nextLine();
		
		System.out.println("Modelo: ");
		String modelo = scanner.nextLine();
		
		System.out.println("Motor: ");
		String motor = scanner.nextLine();
		
		System.out.println("Ano: ");
		int ano = scanner.nextInt();
		
		Carro carro = new Carro(id, marca, modelo, motor, ano);
		if(dao.createCarro(carro) == true) {
			System.out.println("Insercao com sucesso -> " + carro.toString());
		}
	}
	
	public static void read() {
		dao.conectar();
		
		//Mostrar carros
		Carro[] carros = dao.getCarros();
		System.out.println("=== Mostrar carros === ");		
		for(int i = 0; i < carros.length; i++) {
			System.out.println(carros[i].toString());
		}
		
		scanner.nextLine();
	}
	
	public static void update() {
	    dao.conectar();
	    
	    // Update ano do carro por Id
	    System.out.println("Id do carro: ");
	    int carId = scanner.nextInt();
	    scanner.nextLine(); 
	    
	    Carro carroToUpdate = dao.getCarroById(carId);
	    if (carroToUpdate != null) {
	        System.out.println("Novo ano: ");
	        int newAno = scanner.nextInt();
	        
	        carroToUpdate.setAno(newAno);
	        
	        if (dao.updateCarro(carroToUpdate)) {
	            System.out.println("Ano atualizado: " + carroToUpdate.toString());
	        }
	    } else {
	        System.out.println("Carro com ID " + carId + " nao existe.");
	    }
	}
	
	public static void delete() {
	    dao.conectar();

	    // Delete carro by Id
	    System.out.println("Id do carro a ser excluido: ");
	    int carId = scanner.nextInt();
	    scanner.nextLine();

	    if (dao.excluirCarro(carId)) {
	        System.out.println("Carro com ID " + carId + " excluido com sucesso.");
	    } else {
	        System.out.println("Carro com ID " + carId + " nao existe.");
	    }
	}
}



