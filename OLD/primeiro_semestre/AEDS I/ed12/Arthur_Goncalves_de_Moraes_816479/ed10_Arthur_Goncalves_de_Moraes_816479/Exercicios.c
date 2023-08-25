/*
 Exercicios - v1.0.
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )

void Exemplo1011(int inicio, int fim, int quantidade)
{
    FILE *arquivo = fopen("DADOS.TXT", "w");
    int i = 0, numero = 0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    fprintf(arquivo, "%d\n", quantidade);

    srand(time(NULL));
    for (i = 0; i < quantidade; i++)
    {
        numero = rand() % (fim - inicio + 1) + inicio;
        fprintf(arquivo, "%d\n", numero);
    }
    fclose(arquivo);
}

void method01()
{
    int inicio = 0, fim = 0, quantidade = 0;

    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &inicio);

    printf("Informe o limite superior do intervalo: ");
    scanf("%d", &fim);

    printf("Informe a quantidade de numeros a serem gerados: ");
    scanf("%d", &quantidade);

    Exemplo1011(inicio, fim, quantidade);

    getchar();
    IO_pause("Apertar ENTER para continuar");
}

int Exemplo1012(int valor, int arr[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (arr[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

void method02()
{
    FILE *arquivo = fopen("DADOS.TXT", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        int tamanho;
        fscanf(arquivo, "%d", &tamanho);

        int *arr = (int *)malloc(tamanho * sizeof(int));
        if (arr == NULL)
        {
            printf("Erro ao alocar memoria para o array.\n");
            fclose(arquivo);
        }
        else
        {
            int i;
            for (i = 0; i < tamanho; i++)
            {
                fscanf(arquivo, "%d", &arr[i]);
            }

            fclose(arquivo);

            int valorProcurado;
            printf("Digite o valor a ser procurado: ");
            scanf("%d", &valorProcurado);

            int indice = Exemplo1012(valorProcurado, arr, tamanho);
            if (indice != -1)
            {
                printf("Valor encontrado no indice %d.\n", indice);
            }
            else
            {
                printf("Valor nao encontrado.\n");
            }

            free(arr);
        }
    }
    getchar();
    IO_pause("Apertar ENTER para continuar");
}
int Exemplo1013(int arr1[], int tamanho1, int arr2[], int tamanho2)
{
    if (tamanho1 != tamanho2)
    {
        return 0;
    }

    int i;
    for (i = 0; i < tamanho1; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }

    return 1;
}

void method03()
{
    FILE *arquivo1 = fopen("DADOS.TXT", "r");
    if (arquivo1 == NULL)
    {
        printf("Erro ao abrir o arquivo 1.\n");
    }

    FILE *arquivo2 = fopen("DADOS2.TXT", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo 2.\n");
        fclose(arquivo1);
    }
    else
    {
        int tamanho1 = 0, tamanho2 = 0;
        fscanf(arquivo1, "%d", &tamanho1);
        fscanf(arquivo2, "%d", &tamanho2);

        int *arr1 = (int *)malloc(tamanho1 * sizeof(int));
        if (arr1 == NULL)
        {
            printf("Erro ao alocar memoria para o array 1.\n");
            fclose(arquivo1);
            fclose(arquivo2);
        }

        int *arr2 = (int *)malloc(tamanho2 * sizeof(int));
        if (arr2 == NULL)
        {
            printf("Erro ao alocar memoria para o array 2.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            free(arr1);
        }
        else
        {
            int i;
            for (i = 0; i < tamanho1; i++)
            {
                fscanf(arquivo1, "%d", &arr1[i]);
            }

            for (i = 0; i < tamanho2; i++)
            {
                fscanf(arquivo2, "%d", &arr2[i]);
            }

            fclose(arquivo1);
            fclose(arquivo2);

            int resultado = Exemplo1013(arr1, tamanho1, arr2, tamanho2);
            if (resultado)
            {
                printf("Os arranjos sao iguais.\n");
            }
            else
            {
                printf("Os arranjos sao diferentes.\n");
            }

            free(arr1);
            free(arr2);
        }
    }
    getchar();
    IO_pause("Apertar ENTER para continuar");
}

void Exemplo1014(int arr1[], int tamanho1, int arr2[], int tamanho2, int constante)
{
    if (tamanho1 != tamanho2)
    {
        printf("Tamanhos incompativeis. A soma nao pode ser realizada.\n");
    }

    int i;
    for (i = 0; i < tamanho1; i++)
    {
        arr1[i] += arr2[i] * constante;
    }
}

void method04()
{
    FILE *arquivo1 = fopen("DADOS.TXT", "r");
    if (arquivo1 == NULL)
    {
        printf("Erro ao abrir o arquivo 1.\n");
    }

    FILE *arquivo2 = fopen("DADOS2.TXT", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo 2.\n");
        fclose(arquivo1);
    }
    else
    {
        int tamanho1, tamanho2;
        fscanf(arquivo1, "%d", &tamanho1);
        fscanf(arquivo2, "%d", &tamanho2);

        int *arr1 = (int *)malloc(tamanho1 * sizeof(int));
        if (arr1 == NULL)
        {
            printf("Erro ao alocar memoria para o array 1.\n");
            fclose(arquivo1);
            fclose(arquivo2);
        }

        int *arr2 = (int *)malloc(tamanho2 * sizeof(int));
        if (arr2 == NULL)
        {
            printf("Erro ao alocar memoria para o array 2.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            free(arr1);
        }
        else
        {
            int i;
            for (i = 0; i < tamanho1; i++)
            {
                fscanf(arquivo1, "%d", &arr1[i]);
            }

            for (i = 0; i < tamanho2; i++)
            {
                fscanf(arquivo2, "%d", &arr2[i]);
            }

            fclose(arquivo1);
            fclose(arquivo2);

            int constante;
            printf("Digite a constante de escala: ");
            scanf("%d", &constante);

            Exemplo1014(arr1, tamanho1, arr2, tamanho2, constante);

            printf("Resultado da soma:\n");
            for (i = 0; i < tamanho1; i++)
            {
                printf("%d ", arr1[i]);
            }
            printf("\n");

            free(arr1);
            free(arr2);
        }
    }
    getchar();
    IO_pause("Apertar ENTER para continuar");
}

int Exemplo1015(int arr[], int tamanho)
{
    int i;
    for (i = 1; i < tamanho; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

void method05()
{
    FILE *arquivo = fopen("DADOS.TXT", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        int tamanho;
        fscanf(arquivo, "%d", &tamanho);

        int *arr = (int *)malloc(tamanho * sizeof(int));
        if (arr == NULL)
        {
            printf("Erro ao alocar memoria para o array.\n");
            fclose(arquivo);
        }
        else
        {
            int i;
            for (i = 0; i < tamanho; i++)
            {
                fscanf(arquivo, "%d", &arr[i]);
            }

            fclose(arquivo);

            int resultado = Exemplo1015(arr, tamanho);
            if (resultado)
            {
                printf("O arranjo esta em ordem decrescente.\n");
            }
            else
            {
                printf("O arranjo nao esta em ordem decrescente.\n");
            }

            free(arr);
        }
    }

    getchar();
    IO_pause("Apertar ENTER para continuar");
}

void Exemplo1016(int **matriz, int linhas, int colunas)
{
    int i, j;
    int **transposta = (int **)malloc(colunas * sizeof(int *));
    for (i = 0; i < colunas; i++)
    {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }

    printf("Matriz Transposta:\n");
    for (i = 0; i < colunas; i++)
    {
        for (j = 0; j < linhas; j++)
        {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < colunas; i++)
    {
        free(transposta[i]);
    }
    free(transposta);
}

void method06()
{
    FILE *arquivo = fopen("MATRIZ.TXT", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        int linhas, colunas;
        fscanf(arquivo, "%d %d", &linhas, &colunas);

        int **matriz = (int **)malloc(linhas * sizeof(int *));
        if (matriz == NULL)
        {
            printf("Erro ao alocar memoria para a matriz.\n");
            fclose(arquivo);
        }

        int i, j;
        for (i = 0; i < linhas; i++)
        {
            matriz[i] = (int *)malloc(colunas * sizeof(int));
            if (matriz[i] == NULL)
            {
                printf("Erro ao alocar memoria para a matriz.\n");
                fclose(arquivo);
                for (j = 0; j < i; j++)
                {
                    free(matriz[j]);
                }
                free(matriz);
            }
        }

        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                fscanf(arquivo, "%d", &matriz[i][j]);
            }
        }

        fclose(arquivo);

        Exemplo1016(matriz, linhas, colunas);

        for (i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }
    getchar();
    IO_pause("Apertar ENTER para continuar");
}

int Exemplo1017(int **matriz, int linhas, int colunas)
{
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (matriz[i][j] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void method07()
{
    FILE *arquivo = fopen("MATRIZ.TXT", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    else
    {
        int linhas, colunas;
        fscanf(arquivo, "%d %d", &linhas, &colunas);

        int **matriz = (int **)malloc(linhas * sizeof(int *));
        if (matriz == NULL)
        {
            printf("Erro ao alocar memoria para a matriz.\n");
            fclose(arquivo);
        }

        int i, j;
        for (i = 0; i < linhas; i++)
        {
            matriz[i] = (int *)malloc(colunas * sizeof(int));
            if (matriz[i] == NULL)
            {
                printf("Erro ao alocar memoria para a matriz.\n");
                fclose(arquivo);
                for (j = 0; j < i; j++)
                {
                    free(matriz[j]);
                }
                free(matriz);
            }
        }

        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                fscanf(arquivo, "%d", &matriz[i][j]);
            }
        }

        fclose(arquivo);

        int resultado = Exemplo1017(matriz, linhas, colunas);
        if (resultado)
        {
            printf("A matriz contem apenas valores iguais a zero.\n");
        }
        else
        {
            printf("A matriz contem valores diferentes de zero.\n");
        }

        for (i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }

    IO_pause("Apertar ENTER para continuar");
}

int Exemplo1018(int **matriz1, int **matriz2, int linhas, int colunas)
{
    int i = 0, j = 0;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (matriz1[i][j] != matriz2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void method08()
{
    FILE *arquivo1 = fopen("MATRIZ.TXT", "r");
    if (arquivo1 == NULL)
    {
        printf("Erro ao abrir o arquivo 1.\n");
    }

    FILE *arquivo2 = fopen("MATRIZ2.TXT", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo 2.\n");
        fclose(arquivo1);
    }
    else
    {
        int linhas, colunas;
        fscanf(arquivo1, "%d %d", &linhas, &colunas);

        int **matriz1 = (int **)malloc(linhas * sizeof(int *));
        if (matriz1 == NULL)
        {
            printf("Erro ao alocar memoria para a matriz 1.\n");
            fclose(arquivo1);
            fclose(arquivo2);
        }
        int **matriz2 = (int **)malloc(linhas * sizeof(int *));
        if (matriz2 == NULL)
        {
            printf("Erro ao alocar memoria para a matriz 2.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            free(matriz1);
        }
        else
        {
            int i = 0, j = 0;
            for (i = 0; i < linhas; i++)
            {
                matriz1[i] = (int *)malloc(colunas * sizeof(int));
                matriz2[i] = (int *)malloc(colunas * sizeof(int));
                if (matriz1[i] == NULL || matriz2[i] == NULL)
                {
                    printf("Erro ao alocar memoria para as matrizes.\n");
                    fclose(arquivo1);
                    fclose(arquivo2);
                    for (j = 0; j < i; j++)
                    {
                        free(matriz1[j]);
                        free(matriz2[j]);
                    }
                    free(matriz1);
                    free(matriz2);
                }
            }

            for (i = 0; i < linhas; i++)
            {
                for (j = 0; j < colunas; j++)
                {
                    fscanf(arquivo1, "%d", &matriz1[i][j]);
                }
            }

            for (i = 0; i < linhas; i++)
            {
                for (j = 0; j < colunas; j++)
                {
                    fscanf(arquivo2, "%d", &matriz2[i][j]);
                }
            }

            fclose(arquivo1);
            fclose(arquivo2);

            int resultado = Exemplo1018(matriz1, matriz2, linhas, colunas);
            if (resultado)
            {
                printf("As matrizes sao iguais.\n");
            }
            else
            {
                printf("As matrizes sao diferentes.\n");
            }

            for (i = 0; i < linhas; i++)
            {
                free(matriz1[i]);
                free(matriz2[i]);
            }
            free(matriz1);
            free(matriz2);
        }
    }

    IO_pause("Apertar ENTER para continuar");
}

void Exemplo1019(int **matriz1, int **matriz2, int **resultado, int linhas, int colunas, int constante)
{
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            resultado[i][j] = matriz1[i][j] + (matriz2[i][j] * constante);
        }
    }
}

void method09()
{
    FILE *arquivo1 = fopen("MATRIZ.TXT", "r");
    if (arquivo1 == NULL)
    {
        printf("Erro ao abrir o arquivo 1.\n");
    }

    FILE *arquivo2 = fopen("MATRIZ2.TXT", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo 2.\n");
        fclose(arquivo1);
    }

    int linhas, colunas;
    fscanf(arquivo1, "%d %d", &linhas, &colunas);

    int **matriz1 = (int **)malloc(linhas * sizeof(int *));
    if (matriz1 == NULL)
    {
        printf("Erro ao alocar memoria para a matriz 1.\n");
        fclose(arquivo1);
        fclose(arquivo2);
    }

    int **matriz2 = (int **)malloc(linhas * sizeof(int *));
    if (matriz2 == NULL)
    {
        printf("Erro ao alocar memoria para a matriz 2.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        free(matriz1);
    }

    int **resultado = (int **)malloc(linhas * sizeof(int *));
    if (resultado == NULL)
    {
        printf("Erro ao alocar memoria para a matriz resultado.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        free(matriz1);
        free(matriz2);
    }

    int i, j;
    for (i = 0; i < linhas; i++)
    {
        matriz1[i] = (int *)malloc(colunas * sizeof(int));
        matriz2[i] = (int *)malloc(colunas * sizeof(int));
        resultado[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz1[i] == NULL || matriz2[i] == NULL || resultado[i] == NULL)
        {
            printf("Erro ao alocar memoria para as matrizes.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            for (j = 0; j < i; j++)
            {
                free(matriz1[j]);
                free(matriz2[j]);
                free(resultado[j]);
            }
            free(matriz1);
            free(matriz2);
            free(resultado);
        }
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            fscanf(arquivo1, "%d", &matriz1[i][j]);
        }
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            fscanf(arquivo2, "%d", &matriz2[i][j]);
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);

    int constante;
    printf("Digite a constante: ");
    scanf("%d", &constante);

    Exemplo1019(matriz1, matriz2, resultado, linhas, colunas, constante);

    printf("Matriz resultado:\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < linhas; i++)
    {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);
    getchar();
    IO_pause("Apertar ENTER para continuar");
}

void Exemplo1020(int **matriz1, int **matriz2, int **resultado, int linhas1, int colunas1, int colunas2) {
    int i, j, k;

    for (i = 0; i < linhas1; i++) {
        for (j = 0; j < colunas2; j++) {
            resultado[i][j] = 0; 
            for (k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j]; 
            }
        }
    }
}

void method10() {
    FILE *arquivo1 = fopen("MATRIZ.TXT", "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir o arquivo 1.\n");
        
    }

    FILE *arquivo2 = fopen("MATRIZ2.TXT", "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo 2.\n");
        fclose(arquivo1);
      
    }

    int linhas1, colunas1;
    fscanf(arquivo1, "%d %d", &linhas1, &colunas1); 
    int colunas2;
    fscanf(arquivo2, "%*d %d", &colunas2); 

    if (colunas1 != colunas2) {
        printf("Erro: As matrizes nao possuem tamanhos compativeis para realizar o produto.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        
    }

    int **matriz1 = (int **)malloc(linhas1 * sizeof(int *));
    if (matriz1 == NULL) {
        printf("Erro ao alocar memoria para a matriz 1.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        
    }

    int **matriz2 = (int **)malloc(colunas1 * sizeof(int *));
    if (matriz2 == NULL) {
        printf("Erro ao alocar memoria para a matriz 2.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        free(matriz1);
       
    }

    int **resultado = (int **)malloc(linhas1 * sizeof(int *));
    if (resultado == NULL) {
        printf("Erro ao alocar memoria para a matriz resultado.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        free(matriz1);
        free(matriz2);
        
    }

    int i, j;
    for (i = 0; i < linhas1; i++) {
        matriz1[i] = (int *)malloc(colunas1 * sizeof(int));
        resultado[i] = (int *)malloc(colunas2 * sizeof(int));
        if (matriz1[i] == NULL || resultado[i] == NULL) {
            printf("Erro ao alocar memoria para as matrizes.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            for (j = 0; j < i; j++) {
                free(matriz1[j]);
                free(resultado[j]);
            }
            free(matriz1);
            free(resultado);
           
        }
    }

    for (i = 0; i < colunas1; i++) {
        matriz2[i] = (int *)malloc(colunas2 * sizeof(int));
        if (matriz2[i] == NULL) {
            printf("Erro ao alocar memoria para a matriz 2.\n");
            fclose(arquivo1);
            fclose(arquivo2);
            for (j = 0; j < linhas1; j++) {
                free(matriz1[j]);
                free(resultado[j]);
            }
            free(matriz1);
            free(resultado);
            
        }
    }

    for (i = 0; i < linhas1; i++) {
        for (j = 0; j < colunas1; j++) {
            fscanf(arquivo1, "%d", &matriz1[i][j]); 
        }
    }

    for (i = 0; i < colunas1; i++) {
        for (j = 0; j < colunas2; j++) {
            fscanf(arquivo2, "%d", &matriz2[i][j]);
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);

    Exemplo1020(matriz1, matriz2, resultado, linhas1, colunas1, colunas2);

    printf("Matriz resultado:\n");
    for (i = 0; i < linhas1; i++) {
        for (j = 0; j < colunas2; j++) {
            printf("%d ", resultado[i][j]); 
        }
        printf("\n");
    }

    for (i = 0; i < linhas1; i++) {
        free(matriz1[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(resultado);

    for (i = 0; i < colunas1; i++) {
        free(matriz2[i]);
    }
    free(matriz2);

   IO_pause("Apertar ENTER para continuar");
}
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
               // repetir até desejar parar
    do
    {
        // identificar
        IO_id("EXERCICIOS - Programa - v1.0");

        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Exercicio 1");
        IO_println(" 2 - Exercicio 2");
        IO_println(" 3 - Exercicio 3");
        IO_println(" 4 - Exercicio 4");
        IO_println(" 5 - Exercicio 5");
        IO_println(" 6 - Exercicio 6");
        IO_println(" 7 - Exercicio 7");
        IO_println(" 8 - Exercicio 8");
        IO_println(" 9 - Exercicio 9");
        IO_println("10 - Exercicio 10");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");

        // testar valor
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )