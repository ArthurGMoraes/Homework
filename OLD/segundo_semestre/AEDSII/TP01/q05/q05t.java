import java.util.Scanner;

class q05t {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;

      do{
         n = scanner.nextInt();

        if (n > 0) {
            int[] terms = new int[n];
            for (int i = 0; i < n; i++) {
                terms[i] = scanner.nextInt();
            }

            String expression = scanner.next();
            boolean result = evaluateExpression(terms, expression);
            System.out.println(result);

            }
         } while (n > 0);

        scanner.close();
    }

    public static boolean evaluateExpression(int[] terms, String expression) {
        String[] tokens = expression.split(" ");
        boolean[] values = new boolean[terms.length];

        for (int i = 0; i < terms.length; i++) {
            values[i] = terms[i] != 0;
        }

        for (String token : tokens) {
            if (token.equals("and")) {
                boolean operand1 = values[values.length - 2];
                boolean operand2 = values[values.length - 1];
                values[values.length - 2] = operand1 && operand2;
                values[values.length - 1] = false;
            } else if (token.equals("or")) {
                boolean operand1 = values[values.length - 2];
                boolean operand2 = values[values.length - 1];
                values[values.length - 2] = operand1 || operand2;
                values[values.length - 1] = false;
            } else if (token.equals("not")) {
                boolean operand = values[values.length - 1];
                values[values.length - 1] = !operand;
            }
        }

        return values[0];
    }
}