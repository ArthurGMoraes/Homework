TP2 AEDS III  
Arthur Gonçalves de Moraes - 816479  
  
ListaInvertida implementada sem nenuma alteração
  
ArquivoLivros:  
- getFileContentAsList(): lê as stopwords de um arquivo e retorna uma lista.  
- removeStopWords(): trata a entrada removendo as stopwords e retirando os acentos. Após isso retorna uma lista contendo as palavras separadas.
- buscar(): chama listaInvertida.read() para cada termo da entrada e adiciona os arrays a uma lista. Após isso percorre a lista e conta a ocorrência dos ids em outro array. Ao final confere qual id está presente em todos os resultados confererindo se o valor da posição é igual ao tamanho da primeira lista.
- alteração em create(): para cada termo do título faz-se a adição na lista invertida.
- alteração em delete(): para cada termo do título faz-se a deleção na lista invertida.
- alteração em update(): antes de alteração cada termo do título antigo é excluído e após isso os termos do novo título são adicionados.
  
MenuLivros:
- pesquisar(): opção do menu para chamar a função buscar de ArquivosLivros
- readString(): para resolver o problema ao ler caracteres acentudados do console utilizei a implementação do MyIO para leitura, utilizando o BufferedReader.
  
O trabalho foi no geral bem tranquilo. A única implementação mais complicada foi a de busca na parte de conferir quais eram os resultados corretos. 
  
- A inclusão de um livro acrescenta os termos do seu título à lista invertida?  
Sim
- A alteração de um livro modifica a lista invertida removendo ou acrescentando termos do título?  
Sim
- A remoção de um livro gera a remoção dos termos do seu título na lista invertida?  
Sim
- Há uma busca por palavras que retorna os livros que possuam essas palavras?  
Sim
- Essa busca pode ser feita com mais de uma palavra?  
Sim
- As stop words foram removidas de todo o processo?  
Sim
- Que modificação, se alguma, você fez para além dos requisitos mínimos desta tarefa?  
Nenhuma
- O trabalho está funcionando corretamente?  
Sim
- O trabalho está completo?  
Sim
- O trabalho é original e não a cópia de um trabalho de um colega?   
Sim
