TP1 AEDSIII
Nesse exercícios foi implementado um registro em memória secundaria para tipos genéricos. Esse registro utiliza uma tabela hash extensiva como índice direto, e tem a capacidade de reaproveitar espaços de registros marcados como apagados (byte lápide) para a criação ou alteração de outros registros. A estrutura utilizada para armazenar a posição dos registros deletados foi uma lista, implementada como lista encadeada (RegDeletado), que possui os variáveis 'endereco' (endereço no arquivo principal) e 'tam' (tamanho do registro) e as funções:
-inserir: insere um registro no fim lista
-excluir: remove um registro pelo valor 'endereco'
-conferir: confere há um espaço disponível e adequado para inserir um registro e retorna seu endereço
-lerArq: carrega a lista para memoria primária
-escreverArq: carrega a lista para um arquivo


-O que você considerou como perda aceitável para o reuso de espaços vazios, isto é, quais são os critérios para a gestão dos espaços vazios?
Até 30% de perda

-O código do CRUD com arquivos de tipos genéricos está funcionando corretamente?
Sim

-O CRUD tem um índice direto implementado com a tabela hash extensível?
Sim

-A operação de inclusão busca o espaço vazio mais adequado para o novo registro antes de acrescentá-lo ao fim do arquivo?
Sim

-A operação de alteração busca o espaço vazio mais adequado para o registro quando ele cresce de tamanho antes de acrescentá-lo ao fim do arquivo?
Sim

-As operações de alteração (quando for o caso) e de exclusão estão gerenciando os espaços vazios para que possam ser reaproveitados?
Sim

-O trabalho está funcionando corretamente?
Sim

-O trabalho está completo?
Sim

-O trabalho é original e não a cópia de um trabalho de um colega?
Como base do trabalho foi utilizado o código disponibilizado pelo professor, fazendo somente as devidas alterações para cumprir os requisitos do exercício