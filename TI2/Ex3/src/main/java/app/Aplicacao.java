package app;

import static spark.Spark.*;

import service.CarroService;

public class Aplicacao {
	
	private static CarroService carroService = new CarroService();
	
    public static void main(String[] args) {
        port(9876);

        post("/carro", (request, response) -> carroService.add(request, response));

        get("/caro/:id", (request, response) -> carroService.get(request, response));

        get("/caro/update/:id", (request, response) -> carroService.update(request, response));

        get("/caro/delete/:id", (request, response) -> carroService.remove(request, response));

        get("/caro", (request, response) -> carroService.getAll(request, response));
               
    }
}