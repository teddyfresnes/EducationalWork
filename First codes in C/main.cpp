#include <locale>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <libgen.h>
/*
	Name: KOEHREN Teddy
	Date: 21/09/2002
	Description: Premier programme en C
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void clean()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void algo1() // calculer le volume d'un pav�
{
	float l, L, h, V;
	
	printf("Entrez la longueur du pav� :\n> ");
	fflush(stdin);
	scanf("%f",&l);
	
	printf("Entrez la largeur du pav� :\n> ");
	fflush(stdin);
	scanf("%f",&L);
	
	printf("Entrez la hauteur du pav� :\n> ");
	fflush(stdin);
	scanf("%f",&h);
	
	V = l * L * h;
	printf("\nLe volume de ce pav� est de %f",V);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();
	
	clean();
}


void algo2() // calculer le nombre de secondes �coul�es depuis le d�but de d�but de la journ�e � partir d'une heure donn�e
{
	int h, m, s;
	
	printf("Entrez l'heure :\n> ");
	fflush(stdin);
	scanf("%d",&h);
	
	printf("Entrez le nombre de minutes :\n> ");
	fflush(stdin);
	scanf("%d",&m);
	
	s = (h*60*60)+(m*60);
	
	printf("%d secondes se sont �coul�es depuis le d�but de la journ�e",s);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();
	
	clean();
}


void algo3() // calculer l'heure courante � partir du nombre de secondes �coul�es depuis le d�but de la journ�e
{
	int h, m, s1, s2;
	
	printf("Entrez le nombres de secondes �coul�s :\n> ");
	fflush(stdin);
	scanf("%d",&s2);
	
	h = s2 / 3600;
	m = s2 / 60 % 60;
	s1 = (s2 / 60 % 60 % 60);
	
	printf("Il est %d:%d:%d",h,m,s1);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();
	
	clean();
}


void algo4() // calculer !N
{
	int n, f, i;
	
	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	
	f = 1;
	i = n;
	
	while (i>0)
	{
		f = f * i;
		i = i - 1;
	}
	
	printf("La factorielle de %d est %d",n,f);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();
}


void algo5() // Est ce que N est un nombre premier ?
{
	int n, i;
	bool c;
	
	c = true;
	
	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	
	for (i=2; i<=n-1; i++)
	{
		//printf("%d modulo %d = %d \n",n,i,n%i); // pour voir les �tapes
		if (n%i == 0)
		{
			c = false;
		}
	}
	
	if (c == true)
	{
		printf("Le nombre %d est premier\n",n);
	}
	
	else
	{
		printf("Le nombre %d n'est point premier\n",n);
	}
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();
}


void algo6() // Est ce que N est un nombre parfait ?
{
	int n, somme, i;
	
	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	
	for (i=1; i<=n-1; i++)
	{
		if (n%i == 0)
		{
			somme = somme + i;
		}
		//printf("%d modulo %d = %d \nsomme = %d\n",n,i,n%i,somme); // pour voir les �tapes
	}
	
	if (n == somme) { printf("Le nombre %d est parfait\n",n); }
	
	else { printf("Le nombre %d n'est point parfait\n",n); }
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo7() // Calculer la somme des N premiers entiers positifs
{
	int n, somme, i;
	
	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	
	for (i=1; i<=n; i++)
	{
		somme = somme + i;
	}
	
	printf("La somme des %d premiers nombres entiers positifs est de %d",n,somme);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo8() // Calculer le maximum de 10 nombres saisis par un utilisateur
{
	int max, i, tab[10];
	
	for (i=0; i<=9; i++)
	{
		printf("Entrez le nombre %d/10 :\n> ",i+1);
		fflush(stdin);
		scanf("%d",&tab[i]);
	}

	max = tab[0];

	for (i=0; i<=9; i++)
	{
		if (max <= tab[i])
		{
			max = tab[i];
		}
	}
	
	printf("La valeur la plus �lev� de ces 10 nombres est %d",max);

	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo9() // Calculer tous les nombres de 3 chiffres qui sont �gaux � la somme des cubes de leurs chiffres
{
	int a, b, c, i, j;
	
	for (i=0; i<=999; i++)
	{
		a = i/100;
		b = (i-(a*100))/10;
		c = i-((a*100)+(b*10));
		j = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (i == j)
		{
			printf("La somme des rangs du nombre %d �lev� au cube est �gale � %d.\n",i,j);
		}
	}
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo10() // (BONUS) somme des nombres premiers situ� entre 0 et N
{
	int n, somme, i, j;
	bool c;
	
	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	for (i=1; i<=n-1; i++)
	{
		c = true;
		//printf("\n\npour i = %d\n",i); // pour voir les �tapes
		for (j=2; j<=i-1; j++)
		{
			if (i%j == 0)
			{
				c = false;
			}
			//printf("%d modulo %d = %d \nsomme = %d\n",i,j,i%j,somme); // pour voir les �tapes
		}
		
		if (c == true) { somme = somme + i; } // si le nombre est premier
	}
	
	printf("Somme = %d",somme);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo11() // (BONUS) somme des N premiers entiers positifs
{
	int n, j, i=2, somme=0;
	bool c;

	printf("Entrez un nombre n :\n> ");
	fflush(stdin);
	scanf("%d",&n);
	while(n>0)
	{
		//
		c = true;
		for (j=2; j<=i-1; j++)
		{
			if (i%j == 0)
			{
				c = false;
			}
		}
		if (c == true)
		{
			printf("nombre i = %d premier \n",i); // pour voir les �tapes
			somme = somme + i;
			n = n - 1;
		}
		//

		i = i + 1;
	}
	printf("Somme = %d",somme);
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo12() // Pendu
{
	char  words[16][16] = {"ENCLUME","MARTEAU","BOULOT","FUCKOFF","ARBRE","PIRATE","IGLOO","CRI","CARTE BLEUE","TITUBER","AUJOURD'HUI","QUELQU'UN","ACAJOU","CORBEAU","NINTENDO","TEDDY"};
	int nb_words = sizeof(words)/16; // nb mots
	srand(time(NULL)); // g�n�re une gra�ne al�atoire pour un mot al�atoire
	char* word = words[rand()%nb_words];
	int word_lenght = strlen(word); // taille mot
	char word_found[word_lenght];
	char letters_tried[26] = {""};
	char lettre_input;
	int lives = 9;
	int counter = 0;
	int i;
	
	for (i = 0; i < word_lenght; i++)
	{
        word_found[i] = '-';
        if (word[i] == ' ') // Si le mot a des espaces
        {
        	word_found[i] = ' ';
		}
        if (word[i] == '\'') // Si le mot a des apostrophes
        {
        	word_found[i] = '\'';
		}
    }
	
	bool success = false;
	
	while (not success)
	
	{
		clean();
		
		if (lives == 1)
		{
			printf("  ______\n |      |\n |      O\n |     /|\\\n_|__   /\n");
		}
		if (lives == 2)
		{
			printf("  ______\n |      |\n |      O\n |     /|\\\n_|__\n");
		}
		if (lives == 3)
		{
			printf("  ______\n |      |\n |      O\n |     /|\n_|__\n");	
		}
		if (lives == 4)
		{
			printf("  ______\n |      |\n |      O\n |      |\n_|__\n");	
		}
		if (lives == 5)
		{
			printf("  ______\n |      |\n |      O\n |\n_|__\n");	
		}
		if (lives == 6)
		{
			printf("  ______\n |      |\n |\n |\n_|__\n");
		}
		if (lives == 7)
		{
			printf("  ______\n |\n |\n |\n_|__\n");
		}
		if (lives == 8)
		{
			printf("\n |\n |\n |\n_|__\n");
		}
		if (lives == 9)
		{
			printf("\n\n\n\n___\n");
		}

		printf("\n---------------------------------\n");
		printf("Mot cach�      : %s\n",word_found);
		printf("Lettres entr�s : ");
		for (i=0; i<strlen(letters_tried); i++)
		{
			if ((letters_tried[i] != NULL) || (letters_tried[i] != '\0')) // n'affiche rien si il n'y a pas de caract�re
			{
				printf("%c ",letters_tried[i]);
			}
		}
		printf("\nVies restantes : %d\n",lives);
		
		printf("---------------------------------\nEntrez une lettre :\n> ");		
		fflush(stdin);
		scanf("%c",&lettre_input);
		
		lettre_input = toupper(lettre_input); // met la lettre en majuscule
		letters_tried[counter] = lettre_input;
		
		bool find_a_letter = false;
		for (i=0; i<=word_lenght; i++)
		{
			if (lettre_input == word[i])
			{
				find_a_letter = true;
				word_found[i] = lettre_input;
			}
		}
		if (not find_a_letter)
		{
			lives = lives - 1;
		}
		
		counter = counter + 1;
		
		if (strcmp(word,word_found) == 0) // si le mot secret et le mot trouver est �gal alors
		{
			success = true;
			printf("\n\nVous avez gagn� ! Le mot �tait : %s\n",word);
		}

		if (lives <= 0)
		{
			success = true;
			clean();
			printf("  ______\n |      |\n |      O\n |     /|\\\n_|__   / \\\n");
			printf("\n\nVous avez perdu ! Le mot �tait : %s\n",word);
		}
	}
	
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo13() // allumettes
{
	int nb_allumettes, mode, i;
	bool leave = false;
	
	while (!leave)
	{
		srand(time(NULL)); // g�n�re une nouvelle gra�ne pour rand
		nb_allumettes = rand()%9+16; // nombre entre 16 et 24
		char allumettes[nb_allumettes];
		
		for (i=0; i<nb_allumettes; i++)
		{
		    allumettes[i] = '|';
		}
		
		printf("Quel mode voulez vous essayer ?\n\n[1] Player VS Player\n[2] Player VS Bot\n[3] Quitter le jeu\n\n> ");
		fflush(stdin);
		scanf("%d",&mode);
		
		if (mode == 1)
		{
			int nb_players, player, remove_nb, allumettes_restantes;
			bool undeuxtrois;
			
			clean();
			
			printf("Mode Player VS Player selectionn� !\n\nEntrez le nombre de joueurs :\n> ");
			fflush(stdin);
			scanf("%d",&nb_players);
			
			if (nb_players < 2)
			{
				printf("Pas assez de joueurs !");
			}
			else
			{
				clean();
				
				printf("%d joueurs selectionn�s ! La partie d'allumetes commence !\n\n",nb_players);
				
				while (allumettes[0] != '\0') // tant qu'il y a des allumettes
				{
					player = player + 1;
					allumettes_restantes = strlen(allumettes);
					
					undeuxtrois = false;
					while (!undeuxtrois)
					{
						printf("Allumettes : %s\n\nJoueur %d, � vous de jouer !\nEntrez un nombre entre 1 et 3 :\n> ",allumettes,player);
						fflush(stdin);
						scanf("%d",&remove_nb);
						
						if ((remove_nb >= 1) && (remove_nb <= 3))
						{
							clean();
							printf("Vous avez rentr� %d !\n\n",remove_nb);
							undeuxtrois = true;
						}
						else
						{
							clean();
							printf("\n\nLe nombre %d est incorrect !\nRentrez un nombre entre 1 et 3, ni plus, ni moins.\n\n",remove_nb);
						}
					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, le joueur %d a perdu !\n\n",player);
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
					else
				 	{
						if (player >= nb_players)
						{
							player = 0;
						}
					}
				}
			}
		}
		if (mode == 2)
		{
			int difficulty, turn, old, remove_nb, allumettes_restantes;
			bool undeuxtrois;
			
			clean();
			
			printf("Mode Player VS BOT !\n\nEntrez la difficult� du bot :\n[1] Facile\n[2] Normal\n[3] Difficile\n[4] Impossible\n> ");
			fflush(stdin);
			scanf("%d",&difficulty);
			
			if (difficulty == 4)
			{
				nb_allumettes = 21;
				allumettes[nb_allumettes] = '\0';

				for (i=0; i<nb_allumettes; i++)
				{
				    allumettes[i] = '|';
				    printf("	%d	: | 	/ 	chaine : 	%s\n",i,allumettes);
				}
			}
			
			clean();
			
			turn = 0;
			
			printf("Vous avez selectionn� le mode %d ! La partie d'allumetes commence !\n\n",difficulty);
			
			while (allumettes[0] != '\0') // tant qu'il y a des allumettes
			{
				allumettes_restantes = strlen(allumettes);
				
				turn += 1;
				if (turn == 1)
				{
					undeuxtrois = false;
					while (!undeuxtrois)
					{
						printf("Allumettes : %s\n\nJoueur, � vous de jouer !\nEntrez un nombre entre 1 et 3 :\n> ",allumettes);
						fflush(stdin);
						scanf("%d",&remove_nb);
						
						if ((remove_nb >= 1) && (remove_nb <= 3))
						{
							clean();
							printf("Vous avez rentr� %d !\n\n",remove_nb);
							undeuxtrois = true;
						}
						else
						{
							clean();
							printf("\n\nLe nombre %d est incorrect !\nRentrez un nombre entre 1 et 3, ni plus, ni moins.\n\n",remove_nb);
						}
					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, vous avez!\n\n");
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
				}
				if (turn == 2 && difficulty == 1)
				{
					printf("Veuillez patientez, l'ordinateur r�fl�chi...\n");
					Sleep(2000);
					
					if ((remove_nb >= 1) && (remove_nb <= 3)) // s�curit�
					{
						if (allumettes_restantes<=4 && allumettes_restantes>1)
						{
							remove_nb = allumettes_restantes - 1;
						}
						if (allumettes_restantes==1)
						{
							remove_nb = 1;
						}
						else
						{
							if (allumettes_restantes%4 == 1)
							{
				   			remove_nb = 4 - remove_nb;
							}
							if (allumettes_restantes%4 == 2)
							{
							   remove_nb = 1;
							}
							if (allumettes_restantes%4 == 3)
							{
							   remove_nb = 2;
							}
							if (allumettes_restantes%4 == 0)
							{
							   remove_nb = 3;
							}
							else
							{
								srand(time(NULL));
								remove_nb = rand()%3+1;
							}
						}

					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					clean();
					printf("L'ordinateur a retir� %d allumettes !\n\n\n",remove_nb);
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, l'ordinateur a perdu (En m�me temps tu joues en facile...) !\n\n");
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
				}
				if (turn == 2 && difficulty == 2)
				{
					printf("Veuillez patientez, l'ordinateur r�fl�chi...\n");
					Sleep(2000);
					
					if ((remove_nb >= 1) && (remove_nb <= 3)) // s�curit�
					{
						if (allumettes_restantes<=4 && allumettes_restantes>1) // a la fin
						{
							remove_nb = allumettes_restantes - 1;
						}
						if (allumettes_restantes==1) // derniere allumettes
						{
							remove_nb = 1;
						}
						else
						{
							if (old%4 == 1)
							{
								remove_nb = 4 - remove_nb;
							}
							else
							{
								srand(time(NULL));
								remove_nb = rand()%3+1;
							}
						}

					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					clean();
					printf("L'ordinateur a retir� %d allumettes !\n\n\n",remove_nb);
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, l'ordinateur a perdu (Incroyable...) !\n\n");
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
				}
				if (turn == 2 && difficulty == 3)
				{
					printf("Veuillez patientez, l'ordinateur r�fl�chi...\n");
					Sleep(2000);
					
					if ((remove_nb >= 1) && (remove_nb <= 3)) // s�curit�
					{
						if (allumettes_restantes<=4 && allumettes_restantes>1) // a la fin
						{
							remove_nb = allumettes_restantes - 1;
						}
						if (allumettes_restantes==1) // derniere allumettes
						{
							remove_nb = 1;
						}
						else
						{
							if (old%4 == 1)
							{
								printf("remove nb = %d et old = %d et allumettes r = %d\n",remove_nb,old,allumettes_restantes);
								remove_nb = 4 - remove_nb;
							}
							else
							{
								if (allumettes_restantes%4==0)
								{
									remove_nb = 3;
								}
								if (allumettes_restantes%4==1)
								{
									srand(time(NULL));
									remove_nb = rand()%2+1;
								}
								if (allumettes_restantes%4==2)
								{
					                remove_nb = 1;	
								}
								if (allumettes_restantes%4==3)
								{
									remove_nb = 2;
								}
							}
						}
					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					clean();
					printf("L'ordinateur a retir� %d allumettes !\n\n\n",remove_nb);
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, l'ordinateur a perdu (Incroyable...) !\n\n");
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
				}
				if (turn == 2 && difficulty == 4)
				{
					printf("Veuillez patientez, l'ordinateur r�fl�chi...\n");
					Sleep(2000);
					
					if ((remove_nb >= 1) && (remove_nb <= 3)) // s�curit�
					{
						if (allumettes_restantes<=4 && allumettes_restantes>1) // a la fin
						{
							remove_nb = allumettes_restantes - 1;
						}
						if (allumettes_restantes==1) // derniere allumettes
						{
							remove_nb = 1;
						}
						else
						{
							if (old%4 == 1)
							{
								printf("remove nb = %d et old = %d et allumettes r = %d\n",remove_nb,old,allumettes_restantes);
								remove_nb = 4 - remove_nb;
							}
							else
							{
								if (allumettes_restantes%4==0)
								{
									remove_nb = 3;
								}
								if (allumettes_restantes%4==2)
								{
					                remove_nb = 1;	
								}
								if (allumettes_restantes%4==3)
								{
									remove_nb = 2;
								}
							}
						}
					}
					
					for (i=1; i<=remove_nb; i++)
					{
						allumettes[allumettes_restantes - i] = '\0';
					}
					
					clean();
					printf("L'ordinateur a retir� %d allumettes !\n\n\n",remove_nb);
					
					if (allumettes[0] == '\0')
					{
						clean();
						printf("\n\nAH ! Plus d'allumettes, l'ordinateur a perdu (Incroyable...) !\n\n");
						
						printf("\nEntrez une touche pour continuer...");
						fflush(stdin);
						getchar();
						
						clean();
					}
				}
				else
			 	{
					if (turn >= 2)
					{
						turn = 0;
					}
				}
			}
		}
		if (mode == 3)
		{
			leave = true;
		}
	}
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


void algo14() // palindrome checker
{
 	int i, size;
	char word[16];
 	char palindrome[16];
	
	printf("Entrez un mot :\n> ");
	fflush(stdin);
	scanf("%s",&word);
	
	size = strlen(word);
	
	for (i=0; word[i] != '\0'; i++) // inverse string dans palindrome
	{
        palindrome[i] = word[size - i - 1];
        //printf("word[i] = %c | word[size - i - 1] = %c\n",word[i],word[size - i - 1]); // afficher les �tapes
	}
	
	printf("\nMot	: %s\nInvers�	: %s\n\n",word,palindrome);
	if (strcmp(word,palindrome) == 0)
	{
		printf("Le mot \"%s\" est un palindrome.\n\n",word);
	}
	else
	{
		printf("Le mot \"%s\" n'est pas un palindrome.\n\n",word);
	}
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}


/*void algo15() // 
{
	int i, choice;
	bool leave;
	
	struct VaccCV_19
	{
		char last_name[32];
		char first_name[32];
		long long int social_security_number;
		char birthdate[20];
		char adress[80];
		char zip_code[16];
		char mail[80];
		char phone[16];
		char job[20];
		bool hazardous_job;
		bool chronic_disease;
		bool covid_symptom;
		bool covid_contact;
		bool daily_antibiotic;
		char vaccination_date[20];
		long int vaccination_id;
		char vaccination_name[20];
		char vaccination_lot_name[20];
	};


	class VaccCV_19_data_management
	{
		public:
			void add()
			{
				int empty;
				
				for (i = 0; VaccCV_19_data[i].social_security_number != 0; i++)
				{
					empty = i + 1;
				}
				
				printf("Nom : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].last_name);
				
				printf("Prenom : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].first_name);
				
				printf("Num�ro de s�curit� sociale : ");
				fflush(stdin);
				scanf("%lli",&VaccCV_19_data[empty].social_security_number);
				
				printf("Date de naissance (format : JJ/MM/AAAA) : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].birthdate);
				
				printf("Adresse : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].birthdate);
				
				printf("Code postal : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].zip_code);
				
				printf("Adresse mail : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].mail);
				
				printf("Num�ro de t�l�phone : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].phone);
				
				printf("M�tier : ");
				fflush(stdin);
				scanf("%i",&VaccCV_19_data[empty].job);
				
				printf("M�tier � risque ? Entrez :\n[1] Oui\n[2] Non\n> ");
				fflush(stdin);
				scanf("%i",&choice);
				if (choice == 1)
				{
					VaccCV_19_data[empty].hazardous_job = true;
				}
				if (choice == 2)
				{
					VaccCV_19_data[empty].hazardous_job = false;
				}
				
				printf("Maladie chronique(s) ? Entrez :\n[1] Oui\n[2] Non\n> ");
				fflush(stdin);
				scanf("%i",&choice);
				if (choice == 1)
				{
					VaccCV_19_data[empty].chronic_disease = true;
				}
				if (choice == 2)
				{
					VaccCV_19_data[empty].chronic_disease = false;
				}
				
				printf("Sympt�me du covid ? Entrez :\n[1] Oui\n[2] Non\n> ");
				fflush(stdin);
				scanf("%i",&choice);
				if (choice == 1)
				{
					VaccCV_19_data[empty].covid_symptom = true;
				}
				if (choice == 2)
				{
					VaccCV_19_data[empty].covid_symptom = false;
				}
				
				printf("Cas contact? Entrez :\n[1] Oui\n[2] Non\n> ");
				fflush(stdin);
				scanf("%i",&choice);
				if (choice == 1)
				{
					VaccCV_19_data[empty].covid_contact = true;
				}
				if (choice == 2)
				{
					VaccCV_19_data[empty].covid_contact = false;
				}
				
				printf("Prise d'antibiotique r�guli�re? Entrez :\n[1] Oui\n[2] Non\n> ");
				fflush(stdin);
				scanf("%i",&choice);
				if (choice == 1)
				{
					VaccCV_19_data[empty].daily_antibiotic = true;
				}
				if (choice == 2)
				{
					VaccCV_19_data[empty].daily_antibiotic = false;
				}
	
				printf("Date de vaccination (format : JJ/MM/AAAA) : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].vaccination_date);
				
				printf("Nom du vaccin : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].vaccination_name);
				
				printf("Nom du lot de vaccin : ");
				fflush(stdin);
				scanf("%s",&VaccCV_19_data[empty].vaccination_lot_name);
			}
			
			void remove()
			{
				printf("Entrez l'ID du patient � supprimer des donn�es enregistr�es :\n> ");
				fflush(stdin);
				scanf("%d",&choice);
				
				for (i = 0; VaccCV_19_data[i].social_security_number != 0; i++)
				{
					if (i == choice)
					{
						VaccCV_19_data[i].last_name = NULL;
						VaccCV_19_data[i].first_name = NULL;
						VaccCV_19_data[i].social_security_number = NULL;
						VaccCV_19_data[i].birthdate = NULL;
						VaccCV_19_data[i].adress = NULL;
						VaccCV_19_data[i].zip_code = NULL;
						VaccCV_19_data[i].mail = NULL;
						VaccCV_19_data[i].phone = NULL;
						VaccCV_19_data[i].job = NULL;
						VaccCV_19_data[i].hazardous_job = NULL;
						VaccCV_19_data[i].chronic_disease = NULL;
						VaccCV_19_data[i].covid_symptom = NULL;
						VaccCV_19_data[i].covid_contact = NULL;
						VaccCV_19_data[i].daily_antibiotic = NULL;
						VaccCV_19_data[i].vaccination_date = NULL;
						VaccCV_19_data[i].vaccination_id = NULL;
						VaccCV_19_data[i].vaccination_name = NULL;
						VaccCV_19_data[i].vaccination_lot_name = NULL;
					}
				}
			}
			
			void display()
			{
				for (i = 1; VaccCV_19_data[i].social_security_number != 0; i++)
				{
					
					printf("Patient id : %d	\n",i);
					
					printf("Nom : %s \n",VaccCV_19_data[i].last_name);
					
					printf("Pr�nom : %s	\n",VaccCV_19_data[i].first_name);
					
					printf("Num de S�c. Soc. : %lli	\n",VaccCV_19_data[i].social_security_number);
					
					printf("Date naissance : %s	\n",VaccCV_19_data[i].birthdate);
					
					printf("Adresse : %s \n",VaccCV_19_data[i].adress);
					
					printf("Code postal : %s\n",VaccCV_19_data[i].zip_code);
					
					printf("Adresse mail : : %s\n",VaccCV_19_data[i].mail);
					
					printf("Num�ro de tel. : %s\n",VaccCV_19_data[i].phone);
					
					printf("M�tier : %s\n",VaccCV_19_data[i].job);
					
					printf("M�tier � risque? :");
					if (VaccCV_19_data[i].hazardous_job == true)	{printf(" Oui\n");}
					if (VaccCV_19_data[i].hazardous_job == false)	{printf(" Non\n");}
					
					printf("Maladie chronique? :");
					if (VaccCV_19_data[i].chronic_disease == true)	{printf(" Oui\n");}
					if (VaccCV_19_data[i].chronic_disease == false)	{printf(" Non\n");}
					
					printf("Sympt�me du covid? :");
					if (VaccCV_19_data[i].covid_symptom == true)	{printf(" Oui\n");}
					if (VaccCV_19_data[i].covid_symptom == false)	{printf(" Non\n");}
					
					printf("ID Vaccination : %d\n",VaccCV_19_data[i].vaccination_id);
					
					printf("Nom Vaccin : %s\n",VaccCV_19_data[i].vaccination_name);
					
					printf("Nom lot du vaccin : %s\n",VaccCV_19_data[i].vaccination_lot_name);
					
					printf("------------------------------------------\n");
				}
				printf("\nEntrez une touche pour continuer...");
				fflush(stdin);
				getchar();
			}
		
		private:
			int size = (sizeof VaccCV_19_data / sizeof VaccCV_19_data[0]);
		    struct VaccCV_19 VaccCV_19_data[50] =
			{
		    {"last_name","first_name",1000000000000,"birthdate","adress","zipcode","mail","phone","job",false,false,false,false,false,"20/20/2025",0,"vaccin","vaccinlot"},
		    {"NORRIS","Chuck",1548562468013,"01/01/1950","5 rue de l'inconnu","10800","chucknorris@mail.net","102102102102","trop fort",true,false,false,false,false,"20/20/2025",2532,"astranezecoco","astra-lot2"},
			{"BORIS","John",15485421468012,"03/02/1959","N/A","10800","boris@mail.net","102102102102","trop fort",true,false,false,false,false,"20/20/2020",2532,"astranezecoco","astra-lot2"}
			};
	};

	

	setlocale(LC_CTYPE, "fra"); // pour les accents
	
	VaccCV_19_data_management gestion;
	
	leave = false;
	
	while (!leave)
	{
		clean();
		
		printf("Bienvenue dans le programme VaccCV_19, que voulez vous faire ?\n");
		printf("[1] Ajouter un patient\n");
		printf("[2] Retirer un patient\n");
		printf("[3] Afficher les patients enregistr�s\n");
		printf("[4] Quitter\n");
		
		printf("\nRentre le num�ro de l'algorithme � d�marrer :\n> ");

		fflush(stdin);
		scanf("%d",&choice);
		
		clean();
		
		if (choice == 1)
		{
			gestion.add();
		}
		
		if (choice == 2)
		{
			leave = true;
		}
		
		if (choice == 3)
		{
			gestion.display();
		}
		
		if (choice == 4)
		{
			leave = true;
		}
	}
	
	printf("\nEntrez une touche pour continuer...");
	fflush(stdin);
	getchar();

	clean();	
}*/


int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "fra"); // pour les accents
	
	clean();
	
	printf("Bienvenue dans mon premier programme, il poss�de quelques algorithmes avec des fonctions diff�rentes, veuillez en choisir un :\n\n");
		
	bool done = false;
	
	while (!done)
	{
		printf("\nPARTIE 1 :\n\n");
		printf("[Algorithme 1] Calcul du volume d'un pav�\n");
		printf("[Algorithme 2] Calcul du nombre de secondes �coul�es depuis le d�but de la journ�e depuis une heure donn�e\n");
		printf("[Algorithme 3] Calcul de l'heure courante � partir du nombre de secondes �coul�s depuis le d�but de la journ�e\n");
		printf("[Algorithme 4] Calculer la factorielle d'un nombre\n");
		printf("[Algorithme 5] Checker un nombre premier\n");
		printf("[Algorithme 6] Checker un nombre parfait\n");
		printf("[Algorithme 7] Calcul de la somme des N premiers entiers positifs\n");
		printf("[Algorithme 8] Calcul le maximum de 10 nombres choisis\n");
		printf("[Algorithme 9] Calcul de tous les nombres de 3 chiffres qui sont �gaux � la somme des cubes de leurs chiffres\n");
		printf("[Algorithme 10] (BONUS) Calcul de la somme des nombres premiers situ� entre 0 et N\n");
		printf("[Algorithme 11] (BONUS) Calcul de la somme des N premiers nombres premiers\n");
		printf("[Algorithme 12] Jeu du pendu\n");
		printf("[Algorithme 13] Jeu des allumettes\n");
		printf("[Algorithme 14] Checker un palindrome\n");
		printf("[Algorithme 15] TP Astrazeneca\n");
		
		printf("\nRentre le num�ro de l'algorithme � d�marrer :\n> ");
		
		int choice;

		fflush(stdin);
		scanf("%d",&choice);
		
		clean();
		
		if (choice == 1) { algo1(); }
		
		if (choice == 2) { algo2(); }	
		
		if (choice == 3) { algo3(); }
		
		if (choice == 4) { algo4(); }
		
		if (choice == 5) { algo5(); }
		
		if (choice == 6) { algo6(); }
		
		if (choice == 7) { algo7(); }
		
		if (choice == 8) { algo8(); }
		
		if (choice == 9) { algo9(); }
		
		if (choice == 10) { algo10(); }
		
		if (choice == 11) { algo11(); }
		
		if (choice == 12) { algo12(); }
		
		if (choice == 13) { algo13(); }
		
		if (choice == 14) { algo14(); }
		
		//if (choice == 15) { algo15(); }
	}
}
