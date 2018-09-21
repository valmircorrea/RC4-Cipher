# RC4 Cipher

Em criptografia, RC4 (ou ARC4) é o algoritmo simétrico de criptografia de fluxo mais usado no software e utilizado nos protocolos mais conhecidos, como Secure Socket Layers (SSL) (para proteger o tráfego Internet) e WEP (para a segurança de redes sem fios). O RC4 não é considerado um dos melhores sistemas criptográficos pelos adeptos da criptografia, e em algumas aplicações podem converter-se em sistemas muito inseguros. No entanto, alguns sistemas baseados em RC4 são seguros o bastante num contexto prático. 

Nesse repositorio contem dois programas: Um que faz a cifragem de um texto (cifra.cpp) e outro um que realiza a decifragem (decifra.cpp) de um texto cifrado pelo RC4.

Para executar o programa:

Nota: O programa deverá ser executado em linha de comando, dentro da pasta principal:

* "make clean" = apaga os arquivos objeto e binário;
* "make" = compila o programa;
* Execute: ./bin/prog chave mensagem.txt saida.txt
 
 Onde:
      
      **prog** é programa que deseja executar (cifra ou decifra)
      
      **chave** é a chave para encripitração ou decripitação
      
      **mensagem.txt** será a mensagem a ser encriptada ou decriptada
      
      **saida.txt** é a saida onde será colocado os dados de cifragem ou decifragem.

