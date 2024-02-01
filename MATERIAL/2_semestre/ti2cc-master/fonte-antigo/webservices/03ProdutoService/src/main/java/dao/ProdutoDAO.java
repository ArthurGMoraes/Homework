package dao;

import model.Discussao;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;


public class DiscussaoDAO {
	private List<Discussao> produtos;
	private int maxId = 0;

	private File file;
	private FileOutputStream fos;
	private ObjectOutputStream outputFile;

	public int getMaxId() {
		return maxId;
	}

	public DiscussaoDAO(String filename) throws IOException {
		file = new File(filename);
		produtos = new ArrayList<Discussao>();
		if (file.exists()) {
			readFromFile();
		}

	}

	public void add(Discussao produto) {
		try {
			produtos.add(produto);
			this.maxId = (produto.getId() > this.maxId) ? produto.getId() : this.maxId;
			this.saveToFile();
		} catch (Exception e) {
			System.out.println("ERRO ao gravar o produto '" + produto.getDescricao() + "' no disco!");
		}
	}

	public Discussao get(int id) {
		for (Discussao produto : produtos) {
			if (id == produto.getId()) {
				return produto;
			}
		}
		return null;
	}

	public void update(Discussao p) {
		int index = produtos.indexOf(p);
		if (index != -1) {
			produtos.set(index, p);
			this.saveToFile();
		}
	}

	public void remove(Discussao p) {
		int index = produtos.indexOf(p);
		if (index != -1) {
			produtos.remove(index);
			this.saveToFile();
		}
	}

	public List<Discussao> getAll() {
		return produtos;
	}

	private List<Discussao> readFromFile() {
		produtos.clear();
		Discussao produto = null;
		try (FileInputStream fis = new FileInputStream(file);
				ObjectInputStream inputFile = new ObjectInputStream(fis)) {

			while (fis.available() > 0) {
				produto = (Discussao) inputFile.readObject();
				produtos.add(produto);
				maxId = (produto.getId() > maxId) ? produto.getId() : maxId;
			}
		} catch (Exception e) {
			System.out.println("ERRO ao gravar produto no disco!");
			e.printStackTrace();
		}
		return produtos;
	}

	private void saveToFile() {
		try {
			fos = new FileOutputStream(file, false);
			outputFile = new ObjectOutputStream(fos);

			for (Discussao produto : produtos) {
				outputFile.writeObject(produto);
			}
			outputFile.flush();
			this.close();
		} catch (Exception e) {
			System.out.println("ERRO ao gravar produto no disco!");
			e.printStackTrace();
		}
	}

	private void close() throws IOException {
		outputFile.close();
		fos.close();
	}

	@Override
	protected void finalize() throws Throwable {
		try {
			this.saveToFile();
			this.close();
		} catch (Exception e) {
			System.out.println("ERRO ao salvar a base de dados no disco!");
			e.printStackTrace();
		}
	}
}