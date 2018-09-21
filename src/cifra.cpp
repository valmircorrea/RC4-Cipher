/**
* @file	    cifra.cpp
* @brief    Programa de cifragem usando o algoritmo RC4
* @author   Valmir Correa (valmircsjr@gmail.com)
* @date	    08/2018
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <bitset>
using std::bitset;

#include <cstring>

/**
* @brief    algoritmo RC4 para cifragem
* @param    chave Chave para cifragem
* @param    msg Mensagema ser cifrada
* @param    jj posição 2
*/
string RC4Cipher (char *chave, string msg);

/**
* @brief    Troca de valores
* @param    S vetor 
* @param    ii posiçao 1
* @param    jj posição 2
*/
void swap (int *S, int ii, int jj);

/**
* @brief    Faz a leitura do conteudo do arquivo
* @param    arq Nome do arquivo a ser lido
* @return   Mensagem lida do arquivo
*/
string leitura (string arq);

/**
* @brief    Faz a escrita de uma mensagem em um arquivo
* @param    arq Nome do arquivo a ser aberto
*/
void escrita (string msg, string nome_arq);

/**
 * Função principal
 */
int main (int argc, char *argv[]) {
     
    // Valida os argumentos
    if (argc != 4) {
        cerr << "--> Argumentos invalidos !" << endl;
        cerr << "Use: ./cifrar chave mensagem.txt mensagem_saida.txt" << endl;
        exit(1);
    }

    // Arquivo de saida da para msg cifrada
    string saida = argv[3];

    // leitura da mensagem
    string msg = leitura(argv[2]);

    // Chave
    char *chave = argv[1];

    // Cifra o texto com RC4
    string texto_cifrado = RC4Cipher(chave, msg);

    // Texto escrito em arquivo
    escrita(texto_cifrado, saida);

    return 0;
}

/**
* @brief    Faz a leitura do conteudo do arquivo
* @param    arq Nome do arquivo a ser lido
* @return   Mensagem lida do arquivo
*/
string leitura (string arq) {
    
    ifstream arquivo (arq);
    
    if (!arquivo) {
        cerr << "Erro ao ler o arquivo " << arq << "!" << endl;
        exit (1);
    }

    string msg;
    while (!arquivo.eof()) {
        string str_temp;
        getline(arquivo, str_temp);
        msg += str_temp;
        msg += '\n';
    }

    if (msg == "") {
        cerr << "Não há mensagem para ser cifrada!" << endl;
        exit(1);
    }

    return msg;
}

/**
* @brief    Faz a escrita de uma mensagem em um arquivo
* @param    arq Nome do arquivo a ser aberto
*/
void escrita (string msg, string nome_arq) {
    
    ofstream arquivo (nome_arq, std::ofstream::ate);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo " << nome_arq << "!" << endl;
        exit (1);
    }

    arquivo << msg << endl;
    arquivo.close();
}

/**
* @brief    Troca de valores
* @param    S vetor 
* @param    ii posiçao 1
* @param    jj posição 2
*/
void swap (int *S, int ii, int jj) {
    int aux = S[ii];
    S[ii] = S[jj];
    S[jj] = aux;
}

/**
* @brief    algoritmo RC4 para cifragem
* @param    chave Chave para cifragem
* @param    msg Mensagema ser cifrada
* @param    jj posição 2
*/
string RC4Cipher (char *chave, string msg) {

    int S[256];
    char T[256];
    int ii, jj = 0;
    string texto_cifrado = "";

    int keylen = strlen(chave);
    char *K = new char [keylen];
    K = chave;
    
    /* Inicialização*/
    for(ii = 0; ii < 256; ii++) {
        S[ii] = ii;
        T[ii] = K[ii % keylen];
    }

    /* Permutação inicial de S */
    for(int ii = 0; ii < 256; ii++) {
        jj = (jj + S[ii] + T[ii]) % 256;

        swap(S, ii, jj);
    }

    /* Geração de fluxo*/
    ii = 0;
    jj = 0;
    for (int cont = 0; cont < (int)msg.length(); cont++) {
        
        ii = (ii + 1) % 256;
        jj = (jj + S[ii]) % 256;

        swap(S, ii, jj);
    
        int t = (S[ii] + S[jj]) % 256;
        int k = S[t];

        bitset<8> k_bit (k);
        bitset<8> caracter_bit (msg[cont]);
        bitset<8> XOR = (k_bit ^= caracter_bit);

        texto_cifrado += char (XOR.to_ulong()); 
    }

    return texto_cifrado;
}