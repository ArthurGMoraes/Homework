TP3 AEDS III  
Arthur Gonçalves de Moraes - 816479  
   
LZW/BitSequence implementados sem nenhuma alteração  
    
Criação do arquivo MenuBackup para gerenciar a interação do usuário com as funções de backup.  
- fazBackup(): cria um diretório com um backup compactados dos arquivos de dados do programa. Gerencia também um arquivo "versao.txt" para que a versão do próximo backup nao seja perdida com a reinicialização do sistema.  
- voltaBackup(): permite que o usuário selecione um backup para ser restaurado entre aqueles disponíveis e sobrescreve os arquivos em dados.  

- Há uma rotina de compactação usando o algoritmo LZW para fazer backup dos arquivos?  
Sim
- Há uma rotina de descompactação usando o algoritmo LZW para recuperação dos arquivos?  
Sim
- O usuário pode escolher a versão a recuperar?  
Sim
- Qual foi a taxa de compressão alcançada por esse backup? (Compare o tamanho dos arquivos compactados com os arquivos originais)  
Aproximadamente 35%
- O trabalho está funcionando corretamente?  
Sim
- O trabalho está completo?  
Sim
- O trabalho é original e não a cópia de um trabalho de um colega?    
Sim
  
