package aeds3;

public class Cifra {
    public static byte[] cifrar(byte[] b, String chave) {
        byte[] cifrado = new byte[b.length];
        int j = 0;

        for (int i = 0; i < b.length; i++) {
            cifrado[i] = (byte)(((b[i] + chave.charAt(j)) % 127));
            j = (j + 1) % chave.length();
        }

        int numRows = (int) Math.ceil((double) cifrado.length / chave.length());
        byte[][] grid = new byte[numRows][chave.length()];
        int index = 0;

        // Fill the grid with bytes from the plaintext
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < chave.length(); c++) {
                if (index < cifrado.length) {
                    grid[r][c] = cifrado[index++];
                } 
            }
        }

        // Read the columns in reverse order to get the ciphertext
        byte[] ciphertext = new byte[cifrado.length];
        index = 0;
        for (int c = chave.length() - 1; c >= 0; c--) {
            for (int r = 0; r < numRows && index < cifrado.length; r++) {
                ciphertext[index++] = grid[r][c];
            }
        }

        return ciphertext;
    }

    public static byte[] decifrar(byte[] b, String chave) {
        int numRows = (int) Math.ceil((double) b.length / chave.length());
        byte[][] grid = new byte[numRows][chave.length()];

        // Fill the grid column-wise in reverse order based on the key
        int index = 0;
        for (int c = chave.length() - 1; c >= 0; c--) {
            for (int r = 0; r < numRows; r++) {
                if (index < b.length) {
                    grid[r][c] = b[index++];
                }
            }
        }

        // Read the grid row-wise to get the plaintext
        byte[] plaintext = new byte[b.length];
        index = 0;
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c < chave.length() && index < b.length; c++) {
                plaintext[index++] = grid[r][c];
                    
            }
        }

        byte[] decifrado = new byte[plaintext.length];
        int j = 0;

        for (int i = 0; i < plaintext.length; i++) {
            int valorDecifrado = (plaintext[i] - chave.charAt(j)) % 127;
            if (valorDecifrado < 0) {
                valorDecifrado += 127;
            }
            decifrado[i] = (byte)(valorDecifrado);
            j = (j + 1) % chave.length();
        }

        return decifrado;
    }  
}