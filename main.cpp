#include <fstream>
#include <string>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char gera_arquivo [200];

struct complexo
{
    double real;
    double imaginario;
};

void inicializaComplexo(struct complexo *nc)
{
    nc->real = 0;
    nc->imaginario = 0;
}

void leiaComplexo(struct complexo *nc)
{
    printf("Parte real: ");
    scanf("%lf", &nc->real);
    printf("Parte imaginaria: ");
    scanf("%lf", &nc->imaginario);
}

void escrevaComplexo(char opcao, struct complexo *nc)
{
    if (opcao == 'm'){
        printf("%lf", nc->real);
      }

    else{
      if(nc->imaginario < 0 ){
        if(nc->real == 0 ){
          printf("%lf i", nc->imaginario);
         }
          else{
            printf("%lf %lf i", nc->real, nc->imaginario);
          }
        }

      if(nc->imaginario == 0 ){
        if(nc->real == 0 ){
          printf("0");
         }
          else{
            printf("%lf", nc->real);
          }
        }

      if(nc->imaginario > 0 ){
        if(nc->real == 0 ){
          printf("%lf i", nc->imaginario);
         }
          else{
            printf("%lf + %lf i", nc->real, nc->imaginario);
          }
        }
      }

}

struct complexo* nComplexos(struct complexo *nc)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->real = nc->real;
    ncR->imaginario = nc->imaginario;
    return ncR;
}

struct complexo* somaComplexos(struct complexo *nc, struct complexo *ncA)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->real = nc->real + ncA->real;
    ncR->imaginario = nc->imaginario + ncA->imaginario;
    return ncR;
}

struct complexo* subtracaoComplexos(struct complexo *nc, struct complexo *ncA)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->real = nc->real - ncA->real;
    ncR->imaginario = nc->imaginario - ncA->imaginario;
    return ncR;
}

struct complexo* multiplicacaotComplexos(struct complexo *nc, struct complexo *ncA)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR-> real = ((nc->real*ncA->real) + ((nc->imaginario*ncA->imaginario)*(-1)));
    ncR->imaginario = ((nc->real*ncA->imaginario) + (nc->imaginario*ncA->real));
    return ncR;
}

struct complexo* divisaoComplexos(struct complexo *nc, struct complexo *ncA)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR-> real = ((nc->real * ncA->real) + ((nc->imaginario * (ncA->imaginario*(-1)))*(-1))) / ((ncA->real * ncA->real) + ((ncA->imaginario * (ncA->imaginario*(-1)))*(-1)));
    ncR-> imaginario = ((nc->real * (ncA->imaginario*(-1))) + (nc->imaginario * ncA->real)) / ((ncA->real * ncA->real) + ((ncA->imaginario * (ncA->imaginario*(-1)))*(-1)));
    return ncR;
}

struct complexo* moduloComplexos(struct complexo *nc)
{
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->real = sqrt((nc->real*nc->real) + (nc->imaginario*nc->imaginario));
    return ncR;
}

struct complexo x, y, *resultado;

class No
{
  public:
  double  valor;
  No* proximo;
  double  valor1;
  No* proximo1;

  No (double elemento)
  {
    this -> valor = elemento;
    this -> proximo = NULL;
    this -> valor1 = elemento;
    this -> proximo1 = NULL;
  }

  void definirProximo(No* end)
  {
    proximo = end;
    proximo1 = end;
  }

  double obterValor()
  {
    return valor;
  }

  double obterValor1()
  {
    return valor1;
  }

  No* obterProximo()
  {
    return proximo;
  }

  No* obterProximo1()
  {
    return proximo1;
  }
};

class Lista
{
  public:
  No* inicio;
  No* inicio1;
  No* fim;
  No* fim1;

  Lista()
  {
    inicio = NULL;
    fim = NULL;
    inicio1 = NULL;
    fim1 = NULL;
  }

  Lista(double num)
  {
    inicio = new No(num);
    fim = inicio;
    inicio1 = new No(num);
    fim1 = inicio1;
  }

  virtual ~Lista()
  {
    delete inicio;
    delete inicio1;
  }

  bool seVazia()
  {
    return (inicio == NULL);
    return (inicio1 == NULL);
  }

  void imprimirElementos()
  {
    cout << "ELEMENTOS DA LISTA" << endl;
    No* i = inicio;
    No* k = inicio1;
    if(seVazia())
    {
      cout << "Lista sem elementos" << endl;
    }
    else
    {
      while(i)
      {
        cout << i -> obterValor() << " ";
        i = i -> obterProximo();
        cout << k -> obterValor() << "i" << endl;
        k = k -> obterProximo1();
      }
      cout << endl;
    }
  }

   void insereNoInicio (double  valor)
  {
    No* novo = new No(valor);
    No* novo1 = new No(valor);

    if (seVazia())
    {
      inicio = novo;
      fim = novo;
      inicio1 = novo1;
      fim1 = novo1;
    }

    else
    {
      novo -> definirProximo(inicio);
      inicio = novo;
      novo1 -> definirProximo(inicio1);
      inicio1 = novo1;
    }
  }

  void insereNoFim (double  valor)
  {
    No* novo = new No(valor);
    No* novo1 = new No(valor);

    if (seVazia())
    {
      inicio = novo;
      fim = novo;
      inicio1 = novo1;
      fim1 = novo1;
    }

    else
    {
      fim -> definirProximo(novo);
      fim = novo;
      fim1 -> definirProximo(novo1);
      fim1 = novo1;
    }
  }

  void insereNoFim2 (struct complexo *nc)
  {
	No* novo;
	novo = new No(nc->real);
    No* novo1;
	novo1 = new No(nc->imaginario);

    if (seVazia())
    {
      inicio = novo;
      fim = novo;
      inicio1 = novo1;
      fim1 = novo1;
    }

    else
    {
      fim -> definirProximo(novo);
      fim = novo;
      fim1 -> definirProximo(novo1);
      fim1 = novo1;
    }
  }

  double  tamanhoLista()
  {
    if (seVazia())
    {
      return 0;
    }

    No* i = inicio;
    double  tamanho = 0;

    do
    {
      i = i -> obterProximo();
      tamanho++;
    }

    while(i);

    return tamanho;
  }

  bool existeElemento(double  valor)
  {
    No* i = inicio;
    while (i)
    {
      if (i -> obterValor() == valor)
      {
        return true ;
      }
      else
      {
        i = i ->obterProximo();
      }
    }
    return false;
  }

  void removerDaLista()
  {
    if (!seVazia())
    {
      if (inicio -> obterProximo() == NULL)
      {
        inicio = NULL;
      }
      else if (inicio -> obterProximo() -> obterProximo() == NULL)
      {
        inicio -> definirProximo(NULL);
      }
      else
      {
        No* anteriorDoAnterior = inicio;
        No* anterior = inicio -> obterProximo();
        No* elo = inicio -> obterProximo() -> obterProximo();

        while(elo)
        {
          No* auxiliar = anterior;
          anterior = elo;
          anteriorDoAnterior = auxiliar;
          elo = elo -> obterProximo();
        }

        delete anteriorDoAnterior -> obterProximo();
        anteriorDoAnterior -> definirProximo(NULL);
        fim = anteriorDoAnterior;
      }
    }
  }
};

void entrada(char opcao)
{
    if (opcao == '5'){
        cout << "\nDigite um número complexo:\n\n";
        leiaComplexo(&x);
    }

    else{
        cout << "\nDigite o primeiro número complexo:\n\n";
        leiaComplexo(&x);
        cout << "\nDigite o segundo número complexo:\n\n";
        leiaComplexo(&y);
    }
}

void saida (char op2)
{
    cout << "\nResultado: ";
    escrevaComplexo(op2, resultado);
    cout << "\n\n\n";

}

void escrevaComplexo2(char opcao, struct complexo *nc)
{
    ofstream saida (gera_arquivo, ios::app);
        saida << (nc->real) << " ";
        if (nc->imaginario > 0){
            saida << "+" <<" ";
        }
        saida << (nc->imaginario) << " " << "i" << endl;
        saida.close();
}

void grava_arquivo(No* x, No* y)
{
    No* i = x;
    No* k = y;

    while (i) {

        ofstream saida (gera_arquivo, ios::app);

        saida << i -> obterValor() << " ";
        i = i -> obterProximo();

        if(k -> obterValor1() > 0){
            saida << "+ ";
        }

        saida << k -> obterValor1() <<" i" << endl;
        k = k -> obterProximo1();

        saida.close();
    }
}

int main ()
{
    bool op = true;
    int num, contador = 0, numcomplexo;
    char op1, op2, op3;

    Lista l;

    inicio:

    while (op){

        cout << "\nDigite a opção desejada:\n\n";
        cout << "1 - Gravar arquivo \n2 - Ler arquivo \n3 - SAIR\n\n";
        cin >> op1;
        cout << endl;

        switch (op1) {
            case '1':
                cout << "Escreva o nome do arquivo: \n";
                cin >> gera_arquivo;

                cout << "Deseja criar o arquivo com quantos números complexos? \n";
                cin >> num;

                while (contador < num) {
                    cout << "Escreva o " << contador + 1 << "º" << "número complexo: " << endl;
                    entrada('5');
                    resultado = nComplexos(&x);
                    l.insereNoFim2(resultado);
                    contador++;
                }

                l.imprimirElementos();
                grava_arquivo(l.inicio, l.inicio1);

                goto inicio;
                break;

            case '2':
                cout << "Escreva o nome do arquivo: \n\n";
                cin >> gera_arquivo;
                goto le_arquivo;

                break;

            case '3':
                cout << "\nVocê pediu para sair.\n";
                op=false;
                goto inicio;
                break;
            default:
                cout << "\nVocê deve escolher uma opção valida.\n";
                goto inicio;
        }

        le_arquivo:

       char n[30];
        double num;
        int i=1, k=0;
        ifstream ent (gera_arquivo);
        while(ent)  {
            ent >> n;
              num = atof(n);
              if((num!=0)){
                l.insereNoFim(num);
              }
        }

        cout << endl << endl;

        l.imprimirElementos();

        cout << "tamanho da lista: "<< l.tamanhoLista() << endl;


        cout << "\n\nEscolha a opção desejada para operações com números complexos:\n\n";
        cout << "1 - Soma \n2 - Subtração \n3 - Multiplicação \n4 - Divisão \n5 - Modulo \n6 - SAIR\n\n";
        cin >> op2;
        op3 = 'n';

        switch (op2) {
            case '1':
                cout << "\nSoma:\n";
                entrada(op2);
                resultado = somaComplexos(&x, &y);
                saida(op3);
                break;
            case '2':
                cout << "\nSubtração:\n";
                entrada(op2);
                resultado = subtracaoComplexos(&x, &y);
                saida(op3);
                break;
            case '3':
                cout << "\nMultiplicação:\n";
                entrada(op2);
                resultado = multiplicacaotComplexos(&x, &y);
                saida(op3);
                break;
            case '4':
                cout << "\nDivisão:\n";
                entrada(op2);
                resultado = divisaoComplexos(&x, &y);
                saida(op3);
                break;
            case '5':
                op3 = 'm';
                cout << "\nModulo:\n";
                entrada(op2);
                resultado = moduloComplexos(&x);
                saida(op3);
                break;
            case '6':
                cout << "\nVocê pediu para sair.\n";
                op=false;
                break;
                default:
                cout << "\nVocê deve escolher uma opção valida.\n";
                goto inicio;
        }
    }

  return 0;
}
