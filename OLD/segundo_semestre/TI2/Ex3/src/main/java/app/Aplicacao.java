package app;

import static spark.Spark.*;
import service.CarroService;


public class Aplicacao {
	
	private static CarroService discussaoService = new CarroService();
	
    public static void main(String[] args) {
        port(6789);
        
        staticFiles.location("/public");
        
        post("/discussao/insert", (request, response) -> discussaoService.insert(request, response));

        get("/carrp/:id", (request, response) -> discussaoService.get(request, response));
        
        get("/discussao/list/:orderby", (request, response) -> discussaoService.getAll(request, response));

        get("/discussao/update/:id", (request, response) -> discussaoService.getToUpdate(request, response));
        
        post("/discussao/update/:id", (request, response) -> discussaoService.update(request, response));
           
        get("/discussao/delete/:id", (request, response) -> discussaoService.delete(request, response));

             
    }
}