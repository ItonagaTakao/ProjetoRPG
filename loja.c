/*
		 * * * Batalha de RPG (DE TURNOS) * * *
 	No que consiste:
		* Batalhas de turnos
		* Caracteristicas dos personagens---------------------------------------------------------------
			- Atributos:
				* Nome do personagem (Char)
				* Pontos de Vida  (inteiro)
				* Ataque (inteiro)
				* Defesa (inteiro)
				* Nivel (inteiro): A cada 100 pontos de exxperiencia o nivel aumenta 1

			- Personagens base
				* PV (Pontos de vida) = 20;
				* Ataque = 5;
				* defesa = 5;
				* xp (pontos de experiencia) = 0;
				* nivel = 1;
				* gold = 0;
				*PV_MAX = 100;
 		* Inventario (Itens dos personagem)---------------------------------------------------------------
			- Invertario:
				* Armadura:
					- Capacete (5 - quantidade)
					- Peitoral (5 - quantidade)
					- Luva	   (5 - quantidade)
					- Bota	   (5 - quantidade)
				* Arma:
					- arco		(5 - quantidade)
					- espada	(5 - quantidade)
					- martelo	(5 - quantidade)

 				* Itens Consumiveis (limite de 6 itens)
					- Potion

			- Equipamentos quantidade
				* Armadura:
					* Capacete:
						- nome:
						- Defesa: 30;
						- Vida: 40:
					* Capacete:

 		* Caracteristicas dos inimigos---------------------------------------------------------------
				*Inimigo e do tipo personagem:
					* Nome do Inimigo (Char)
					* Pontos de Vida  (inteiro)
					* Ataque (inteiro)
					* Defesa (inteiro)
					* drop de xp (inteiro)
					* Nivel (inteiro)
					* drop de gold

 		* Uma s�rie de batalhas (10 FASES)---------------------------------------------------------------
			-Fases:
				* Fase (1):
					- Inimigo:
						* Nome:
 						* PV = 15;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 1;
						* Drop de Experiencia: randon de 15 - 20;
						* Drop de gold: randon de 10 - 20;
				* Fase (2):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 2;
						* Drop de Experiencia: randon 20 - 25;
						* Drop de gold: randon de 10 - 20;

 				* Fase (3):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 3;
						* Drop de Experiencia: randon 25 - 30;
						* Drop de gold: randon de 10 - 20;

				* Fase (4):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 4;
						* Drop de Experiencia: 30 - 35;
						* Drop de gold: randon de 10 - 20;

				* Fase (5):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 5;
						* Drop de Experiencia: 35 - 40;
						* Drop de gold: randon de 10 - 20;

				* Fase (6):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 6;
						* Drop de Experiencia: 40 - 45;
						* Drop de gold: randon de 10 - 20;

				* Fase (7):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 7;
						* Drop de Experiencia: 45 - 50;
						* Drop de gold: randon de 10 - 20;

				* Fase (8):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 8;
						* Drop de Experiencia: 50 - 65;
						* Drop de gold: randon de 10 - 20;
				* Fase (9):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 9;
						* Drop de Experiencia: 65 - 80;
						* Drop de gold: randon de 10 - 20;

				* Fase (10):
					- Inimigo:
						* Nome:
 						* PV = 20;
						* Ataque = 5;
						* defesa = 5;
						* nivel = 10;
						* Drop de Experiencia: 80 - 95;
						* Drop de gold: randon de 10 - 20;
PENDENTE:
	- Definir PV MAX
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Contantes
#define MAX_ITENS 7
#define POTION 30	//Quantidade maxima que uma po��o pode regenerar


//Structs
struct armadura{
	int capacete;
	int luva;
	int peitoral;
	int bota;
};

struct arma{
	int atk;
};

struct inventario{
	//Bag
	int potion;

	//Equipaveis
	struct armadura usuario;
	struct arma jogador;
};

struct personagem{
	//Caracteristicas
	char nome[100];
	int PV;
	int ataque;
	int defesa;
	int xp;
	int nivel;
	int gold;

	struct inventario bag;
};

//Prototipos
void set_Personagem(struct personagem *);
void imprime_personagem(struct personagem );
void levelup(struct personagem *);
void menu(struct personagem );
void xp(struct personagem *, int);
void loja (struct personagem *);


//Fun��o principal
int main(){
	//Iniciando personagem base
	struct personagem J1;

	//Inicializa��o
	int fase = 1;

	//Iniciando personagem
	printf("Digite o nome do seu personagem: ");
	fgets(J1.nome, sizeof J1.nome, stdin);
	set_Personagem(&J1);

	//Mostra Personagem
	imprime_personagem(J1);

	loja (&J1);

	imprime_personagem(J1);

	//Iniciado as fases
	/*
	switch(fase)
		case(1):
		break;
		case(2):
		break;
	*/

	return 0;
}

void set_Personagem(struct personagem *A)
{
	A->PV = 20;
	A->ataque = 5;
	A->defesa = 5;
	A->xp = 0;
	A->nivel = 1;
	A->gold = 100;
}

void imprime_personagem(struct personagem A)
{
	printf("\nNome: %s", A.nome);
	printf("Pontos de vida: %d\n", A.PV);
	printf("Ataque: %d\n", A.ataque);
	printf("Defesa: %d\n", A.defesa);
	printf("Experiencia: %d\n", A.xp);
	printf("Nivel: %d\n", A.nivel);
	printf("Gold: %d\n", A.gold);
}

void imprime_inimigo(struct personagem A)
{
	printf("\n	INIMIGO\n");
	printf("\nNome: %s", A.nome);
	printf("Pontos de vida: %d\n", A.PV);
	printf("Ataque: %d\n", A.ataque);
	printf("Defesa: %d\n", A.defesa);
	printf("Nivel: %d\n", A.nivel);
}

void menu(struct personagem A)
{
	//Inicializa�ao
	int op;

	//Op�oes
	printf("\n	--MENU--\n");
	printf("(1) - Ver status do personagem\n");
	printf("(2) - \n");
	printf("(3) - \n");
	printf("(4) - Iniciar proxima fase\n\n");

	printf("Digite uma op��o: ");
	scanf("%d", &op);

	while(op < 1){
		printf("Op��o invalida!!! Digite novamente: ");
		scanf("%d", &op);
	}

	/*
	while(){
		case(1):

		break;
		case(2):
		break;
	}
	*/
}

void levelup(struct personagem *A)
{
	A->PV = A->PV + 5;		//PV + 5
	A->ataque = A->ataque + 5;	//ataque + 5
	A->defesa = A->defesa + 5;	//defesa + 5
	A->xp = 0;			//xp = 0
	A->nivel++;			//nivel + 1
}

void xp(struct personagem *A, int experiencia)
{
	A->xp += experiencia;
}

void imprime_pocoes(struct personagem *A)
{
	printf("	Itens\n");
	int i;
	for(i = 0; i < MAX_ITENS; i++)
	{
		if( i <= A->bag.potion)
			printf("(%d) - potion\n", i);
		else
			printf("(%d) - potion\n", i);
	}
}

/*
 Input:
 Output: Retorna 1 se o item foi usado e 0 caso contrario
 Paremetros:
*/
int usa_iten(int opcao, struct personagem *A)					//PENDENTE------------------------
{
	if(A->PV + POTION < 100)
		A->PV = A->PV + POTION;

}

void menu_batalha(struct personagem *A, struct personagem *inimigo)		//PENDENTE------------------------
{
	//Apresenta��o
	printf("\n\n	***A BATALHA IRA COME�AR***\n\n");
	imprime_inimigo(*inimigo);
	imprime_personagem(*A);

	//Iniciando a batalha
	do{


		//Inicializa�oes
		int op, op_inventario, controle = 1;			//op�oes do menu

		//Menu de sele��o
		do{
			printf("\n	**Op�oes**\n");
			printf("(1) - Atacar	(2) - Inventario\n");
			printf("Digite uma op��o: ");
			scanf("%d", &op);

			if(op == 2)	//Inventario
			{
				imprime_pocoes(A);
				printf("(0) - Voltar ou Item vazio\n");
				printf("Digite o item desejado: ");

				do{
					scanf("%d", &op_inventario);
				}while(op_inventario > -1 && op_inventario < MAX_ITENS);		//Limite de intens no inventario � de 6

				if(usa_iten(op_inventario, &A))
				{
					controle = 0;
				}
			}

		}while(op != 1 && controle != 0);

		//ATAQUE
		if(controle == 1)
		{
			inimigo->PV = inimigo->PV + ( inimigo->defesa/(100 + inimigo->defesa) ) * A->ataque;		//Dano considerando a defesa
		}

		//Turno do inimigo
		A->PV = A->PV + ( A->defesa/(100 + A->defesa) ) * inimigo->ataque;

	}while(inimigo->PV < 0 && A->PV < 0);
}

/*
void fase(struct personagem A, struct personagem inimigo)	//PENDENTE-----------------------
{
	//Apresenta��o
	printf("\n\n	***A BATALHA IRA COME�AR***\n\n");
	imprime_inimigo(inimigo);
	imprime_personagem(A);
	//Iniciando a batalha
	do{
		menu_batalha(&A, &inimigo);
	}while(inimigo->PV < 0 && A->PV < 0);
}
*/

void loja (struct personagem *A) { //PENDENTE--------------------------
    //parte visual aqui, prints e afins para aparecer a loja
    int opPrincipal, opSecao;
    //Execu��o da loja em si
    do {
        printf ("Opcoes: (0) Sair da loja, (1) Comprar da secao Rare, (2) Comprar da secao Epic, (3) Comprar da secao Legendary");
        printf (",(4) Ir para a proxima pagina\n");
        scanf ("%d", &opPrincipal);
        switch (opPrincipal) {
            case 0:
                break;
            case 1:
                printf ("Opcoes: (0) Voltar, (1) Comprar o 1o item, (2) Comprar o 2o item, (3) Comprar o 3o item\n");
                scanf ("%d", &opSecao);
                switch (opSecao) {
                    case 0:
                        break;
                    case 1:
                        printf ("Esse item ...\n"); //descri��o do item, lida no arquivo
                        if (A->gold < 100)  //100 � um exemplo
                            printf ("Voce ainda nao pode comprar esse item.\n");
                        else {
                            printf ("Deseja compra-lo? Digite 1 se sim e 0 se nao:\n");
                            scanf ("%d", &opSecao);
                            if (opSecao == 1) {
                                //registrar o item como comprado no arquivo
                                printf ("Parabens, voce acabou de comprar a Espada de Ferro!\n"); //exemplo
                                A->gold -= 100; //deveria carregar o valor de compra do arquivo/matriz
                            }
                            else if (opSecao == 0)
                                printf ("E uma pena...\n");
                            else
                                printf ("Opcao invalida!");
                            break;
                        }
                    case 2:
                        //identico ao 1, s� que deve-se ler outro item do arquivo
                        break;
                    case 3:
                        //identico ao 1, s� que deve-se ler outro item do arquivo
                        break;
                    default:
                        printf ("Opcao invalida!\n");
                }
                break;
            case 2:
                //s� muda a se��o em rela��o ao primeiro e tem dois itens ao inv�s de tr�s
                break;
            case 3:
                //s� muda a se��o em rela��o ao primeiro, e tem um item ao inv�s de tr�s
                break;
            //case 4:
                //muda de p�gina, provavelmente usar� outra linha de uma matriz que contenha o que foi lido no arquivo
            default:
                printf ("Opcao invalida!\n");
        }
    } while (opPrincipal != 0);
}