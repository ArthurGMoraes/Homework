TP1 AEDSIII
Arthur Gonçalves de Moraes - 816479

Nesse exercício foi implementado um registro em memória secundaria para tipos genéricos. Esse registro utiliza uma tabela hash extensiva como índice direto, e tem a capacidade de reaproveitar espaços de registros marcados como apagados (byte lápide) para a criação ou alteração de outros registros. A estrutura utilizada para armazenar a posição dos registros deletados foi uma lista com tamanho máximo 300 (valor escolhido para não gerar uma pesquisa sequencial muito grande), implementada como lista encadeada (RegDeletado), que possui os variáveis 'endereco' (endereço no arquivo principal) e 'tam' (tamanho do registro) e as funções:  
-inserir: insere um registro no fim lista  
-excluir: remove um registro pelo valor 'endereco'  
-conferir: confere há um espaço disponível e adequado para inserir um registro e retorna seu endereço  
-lerArq: carrega a lista para memoria primária  
-escreverArq: carrega a lista para um arquivo  
  
Durante a execução da tarefa tive mais dificuldade quanto a implementação do indice com os campos deletados na parte de arquivos, porém após entender um pouco mais consegui criar meus próprios métodos para descarregar o lista em memória e no arquivo. Esses métodos não seguem o padrao utilizado na hash (toByteArray() e fromByteArray) e por isso creio que não sejam uma opção muito boa, já que alteram o arquivo registro por registro ao invés de por blocos. Também fiquei em duvida sobre qual estrutura de dados utilizar e acabei escolhendo uma lista encadeada por ser mais familiar com sua implentação, apesar de achar que uma árvore B+ seja mais eficiente.  
  
- O que você considerou como perda aceitável para o reuso de espaços vazios, isto é, quais são os critérios para a gestão dos espaços vazios?  
Até 30% de perda

- O código do CRUD com arquivos de tipos genéricos está funcionando corretamente?  
Sim

- O CRUD tem um índice direto implementado com a tabela hash extensível?  
Sim

- A operação de inclusão busca o espaço vazio mais adequado para o novo registro antes de acrescentá-lo ao fim do arquivo?  
Sim

- A operação de alteração busca o espaço vazio mais adequado para o registro quando ele cresce de tamanho antes de acrescentá-lo ao fim do arquivo?  
Sim

- As operações de alteração (quando for o caso) e de exclusão estão gerenciando os espaços vazios para que possam ser reaproveitados?  
Sim

- O trabalho está funcionando corretamente?  
Sim

- O trabalho está completo?  
Sim

- O trabalho é original e não a cópia de um trabalho de um colega?  
Como base do trabalho foi utilizado o código disponibilizado pelo professor, fazendo somente as devidas alterações para cumprir os requisitos do exercício
