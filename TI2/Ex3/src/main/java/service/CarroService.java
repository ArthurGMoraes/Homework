package service;

import java.util.Scanner;

import java.io.File;

import java.util.List;
import dao.DiscussaoDAO;
import model.Discussao;
import spark.Request;
import spark.Response;


public class DiscussaoService {

	private DiscussaoDAO discussaoDAO = new DiscussaoDAO();
	private String form;
	private final int FORM_INSERT = 1;
	private final int FORM_DETAIL = 2;
	private final int FORM_UPDATE = 3;
	private final int FORM_ORDERBY_ID = 1;
	private final int FORM_ORDERBY_MARCA = 2;
	private final int FORM_ORDERBY_MODELO = 3;
	
	
	public DiscussaoService() {
		makeForm();
	}

	
	public void makeForm() {
		makeForm(FORM_INSERT, new Discussao(), FORM_ORDERBY_MARCA);
	}

	
	public void makeForm(int orderBy) {
		makeForm(FORM_INSERT, new Discussao(), orderBy);
	}

	
	public void makeForm(int tipo, Discussao discussao, int orderBy) {
		String nomeArquivo = "form.html";
		form = "";
		try{
			Scanner entrada = new Scanner(new File(nomeArquivo));
		    while(entrada.hasNext()){
		    	form += (entrada.nextLine() + "\n");
		    }
		    entrada.close();
		}  catch (Exception e) { System.out.println(e.getMessage()); }
		
		String umDiscussao = "";
		if(tipo != FORM_INSERT) {
			umDiscussao += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;<a href=\"/discussao/list/1\">Novo Discussao</a></b></font></td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t</table>";
			umDiscussao += "\t<br>";			
		}
		
		if(tipo == FORM_INSERT || tipo == FORM_UPDATE) {
			String action = "/discussao/";
			String name, buttonLabel;
			if (tipo == FORM_INSERT){
				action += "insert";
				name = "Inserir Discussao";
				
				buttonLabel = "Inserir";
			} else {
				action += "update/" + discussao.getId();
				name = "Atualizar Discussao (ID " + discussao.getId() + ")";
				
				buttonLabel = "Atualizar";
			}
			umDiscussao += "\t<form class=\"form--register\" action=\"" + action + "\" method=\"post\" id=\"form-add\">";
			umDiscussao += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td colspan=\"3\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;" + name + "</b></font></td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td colspan=\"3\" align=\"left\">&nbsp;</td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td>&nbsp;marca: <input class=\"input--register\" type=\"text\" name=\"marca\" value=\""+ discussao.getMarca() +"\"></td>";
			umDiscussao += "\t\t\t<td>modelo: <input class=\"input--register\" type=\"text\" name=\"modelo\" value=\""+ discussao.getModelo() +"\"></td>";
			umDiscussao += "\t\t\t<td>motor: <input class=\"input--register\" type=\"text\" name=\"motor\" value=\""+ discussao.getMotor() +"\"></td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td>&nbsp;ano: <input class=\"input--register\" type=\"text\" name=\"ano\" value=\""+ discussao.getAno() + "\"></td>";
			umDiscussao += "\t\t\t<td align=\"center\"><input type=\"submit\" value=\""+ buttonLabel +"\" class=\"input--main__style input--button\"></td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t</table>";
			umDiscussao += "\t</form>";		
		} else if (tipo == FORM_DETAIL){
			umDiscussao += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td colspan=\"3\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;Detalhar Discussao (ID " + discussao.getId() + ")</b></font></td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td colspan=\"3\" align=\"left\">&nbsp;</td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td>&nbsp;marca: "+ discussao.getMarca() +"</td>";
			umDiscussao += "\t\t\t<td>modelo: "+ discussao.getModelo() +"</td>";
			umDiscussao += "\t\t\t<td>motor: "+ discussao.getMotor() +"</td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t\t<tr>";
			umDiscussao += "\t\t\t<td>&nbsp;ano: "+ discussao.getAno() + "</td>";
			umDiscussao += "\t\t\t<td>&nbsp;</td>";
			umDiscussao += "\t\t</tr>";
			umDiscussao += "\t</table>";		
		} else {
			System.out.println("ERRO! Tipo não identificado " + tipo);
		}
		form = form.replaceFirst("<UM-PRODUTO>", umDiscussao);
		
		String list = new String("<table width=\"80%\" align=\"center\" bgcolor=\"#f3f3f3\">");
		list += "\n<tr><td colspan=\"6\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;Relação de Discussaos</b></font></td></tr>\n" +
				"\n<tr><td colspan=\"6\">&nbsp;</td></tr>\n" +
    			"\n<tr>\n" + 
        		"\t<td><a href=\"/discussao/list/" + FORM_ORDERBY_ID + "\"><b>ID</b></a></td>\n" +
        		"\t<td><a href=\"/discussao/list/" + FORM_ORDERBY_MODELO + "\"><b>Descrição</b></a></td>\n" +
        		"\t<td><a href=\"/discussao/list/" + FORM_ORDERBY_MARCA + "\"><b>Preço</b></a></td>\n" +
        		"\t<td width=\"100\" align=\"center\"><b>Detalhar</b></td>\n" +
        		"\t<td width=\"100\" align=\"center\"><b>Atualizar</b></td>\n" +
        		"\t<td width=\"100\" align=\"center\"><b>Excluir</b></td>\n" +
        		"</tr>\n";
		
		List<Discussao> discussaos;
		if (orderBy == FORM_ORDERBY_ID) {                 	discussaos = discussaoDAO.getOrderByID();
		} else if (orderBy == FORM_ORDERBY_MARCA) {		discussaos = discussaoDAO.getOrderByMarca();
		} else if (orderBy == FORM_ORDERBY_MODELO) {			discussaos = discussaoDAO.getOrderByModelo();
		} else {											discussaos = discussaoDAO.get();
		}

		int i = 0;
		String bgcolor = "";
		for (Discussao p : discussaos) {
			bgcolor = (i++ % 2 == 0) ? "#fff5dd" : "#dddddd";
			list += "\n<tr bgcolor=\""+ bgcolor +"\">\n" + 
            		  "\t<td>" + p.getId() + "</td>\n" +
            		  "\t<td>" + p.getMarca() + "</td>\n" +
            		  "\t<td>" + p.getModelo() + "</td>\n" +
            		  "\t<td align=\"center\" valign=\"middle\"><a href=\"/discussao/" + p.getId() + "\"><img src=\"/image/detail.png\" width=\"20\" height=\"20\"/></a></td>\n" +
            		  "\t<td align=\"center\" valign=\"middle\"><a href=\"/discussao/update/" + p.getId() + "\"><img src=\"/image/update.png\" width=\"20\" height=\"20\"/></a></td>\n" +
            		  "\t<td align=\"center\" valign=\"middle\"><a href=\"javascript:confirmarDeleteDiscussao('" + p.getId() + "', '" + p.getMarca() + "', '" + p.getModelo() + "');\"><img src=\"/image/delete.png\" width=\"20\" height=\"20\"/></a></td>\n" +
            		  "</tr>\n";
		}
		list += "</table>";		
		form = form.replaceFirst("<LISTAR-PRODUTO>", list);				
	}
	
	
	public Object insert(Request request, Response response) {
		String marca = request.queryParams("marca");
		String modelo = request.queryParams("modelo");
		String motor = request.queryParams("motor");
		int ano = Integer.parseInt(request.queryParams("ano"));
		
		String resp = "";
		
		Discussao discussao = new Discussao(-1, marca, modelo, motor, ano);
		
		if(discussaoDAO.insert(discussao) == true) {
            resp = "Discussao (" + marca + ") inserido!";
            response.status(201); // 201 Created
		} else {
			resp = "Discussao (" + marca + ") não inserido!";
			response.status(404); // 404 Not found
		}
			
		makeForm();
		return form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\""+ resp +"\">");
	}

	
	public Object get(Request request, Response response) {
		int id = Integer.parseInt(request.params(":id"));		
		Discussao discussao = (Discussao) discussaoDAO.get(id);
		
		if (discussao != null) {
			response.status(200); // success
			makeForm(FORM_DETAIL, discussao, FORM_ORDERBY_MARCA);
        } else {
            response.status(404); // 404 Not found
            String resp = "Discussao " + id + " não encontrado.";
    		makeForm();
    		form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\""+ resp +"\">");     
        }

		return form;
	}

	
	public Object getToUpdate(Request request, Response response) {
		int id = Integer.parseInt(request.params(":id"));		
		Discussao discussao = (Discussao) discussaoDAO.get(id);
		
		if (discussao != null) {
			response.status(200); // success
			makeForm(FORM_UPDATE, discussao, FORM_ORDERBY_MARCA);
        } else {
            response.status(404); // 404 Not found
            String resp = "Discussao " + id + " não encontrado.";
    		makeForm();
    		form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\""+ resp +"\">");     
        }

		return form;
	}
	
	
	public Object getAll(Request request, Response response) {
		int orderBy = Integer.parseInt(request.params(":orderby"));
		makeForm(orderBy);
	    response.header("Content-Type", "text/html");
	    response.header("Content-Encoding", "UTF-8");
		return form;
	}			
	
	public Object update(Request request, Response response) {
        int id = Integer.parseInt(request.params(":id"));
		Discussao discussao = discussaoDAO.get(id);
        String resp = "";       

        if (discussao != null) {
        	discussao.setMarca(request.queryParams("marca"));
        	discussao.setModelo(request.queryParams("modelo"));
        	discussao.setMotor(request.queryParams("motor"));
        	discussao.setAno(Integer.parseInt(request.queryParams("ano")));
        
        	discussaoDAO.update(discussao);
        	response.status(200); // success
            resp = "Discussao (ID " + discussao.getId() + ") atualizado!";
        } else {
            response.status(404); // 404 Not found
            resp = "Discussao (ID \" + discussao.getId() + \") não encontrado!";
        }
		makeForm();
		return form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\""+ resp +"\">");
	}

	
	public Object delete(Request request, Response response) {
        int id = Integer.parseInt(request.params(":id"));
        Discussao discussao = discussaoDAO.get(id);
        String resp = "";       

        if (discussao != null) {
            discussaoDAO.delete(id);
            response.status(200); // success
            resp = "Discussao (" + id + ") excluído!";
        } else {
            response.status(404); // 404 Not found
            resp = "Discussao (" + id + ") não encontrado!";
        }
		makeForm();
		return form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\""+ resp +"\">");
	}
}