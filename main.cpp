#include <iostream>
#include <string>

using namespace std;

class Player
{
	public:
	void define_joueur()
	{
		m_vie = 100;
		m_categorie = "Joueur";
		cout<<"Quel est votre nom"<<endl;
		cout<<"> ";cin>>m_nom;
	}
	void define_bot()
	{
		m_vie = 100;
		m_nom = "Mr Bot";
		m_categorie = "Bot";
	}
	void infos()
	{
		cout<<"== Voici les informations sur le personnage =="<<endl;
		cout<<"Nom: "<<m_nom<<endl;
		cout<<"Catégorie: "<<m_categorie<<endl;
		cout<<"Vie: "<<m_vie<<endl;
	}
	void change_nom_joueur()
	{
		cout<<"Quel est le nouveau nom ?"<<endl;
		cout<<"> ";cin>>m_nom;
	}
	string affiche_nom_joueur()
	{
		return m_nom;
	}
	
	private:
	int m_vie;
	string m_nom, m_categorie;
};

//Fonctions
void start_menu();
void game_menu();
void press_enter();
//int check_int(int var_verif);//Input = entrée de l'utilisateur -> OUTPUT = int vérifié et non null.

int main()
{
	//bit_vars
	bool b_continue(true), b_game_continue(true);
	int b_que_faire(100), b_game_que_faire(100);
	//vars
	int foo;
	
	//programme
	Player joueur, bot;
	while(b_continue == true)//Boucle principale
	{
		start_menu();
		while((b_que_faire > 2) || (b_que_faire < 0))/*Traitement de l'input du bit de choix de menu*/
		{
			cout<<"Que voulez vous faire ?"<<endl;
			cout<<"> ";cin>>b_que_faire;
		}
		if(b_que_faire == 0)//Quitter le programme
		{
			cout<<"Merci d'avoir utilisé ce programme"<<endl;
			b_continue = false;
		}
		else if(b_que_faire == 1)//Entrer dans la phase de jeu
		{
			do//boucle principale de la section "jeu"
			{
				game_menu();
				do//Traitement de l'input du bit de selection de la section "jeu"
				{
					cout<<"Que voulez vous faire ?"<<endl;
					cout<<"> ";cin>>b_game_que_faire;
					//Vérifier que l'input est bien de type int
				}while((b_game_que_faire > 5) || (b_game_que_faire < 0));
				if(b_game_que_faire == 0)//Quitter la section "jeu"
				{
					b_game_continue = false;//On quitte la boucle principale de la section "jeu"
				}
				else if(b_game_que_faire == 1)//Lancer la partie contre un bot
				{
					joueur.define_joueur();
					bot.define_bot();
					press_enter();
					cin.get();
					joueur.infos();
					press_enter();
				}
				else if(b_game_que_faire == 2)//changer de nom
				{
					cout<<"Votre nom était : "<<joueur.affiche_nom_joueur()<<endl;
					joueur.change_nom_joueur();
					cin.get();
					press_enter();
				}
				else if (b_game_que_faire == 3)//afficher les informations du personnage (joueur)
				{
					joueur.infos();
					cin.get();
					press_enter();
				}
				else if(b_game_que_faire == 4)//afficher les informations du bot
				{
					bot.infos();
					cin.get();
					press_enter();
				}
				else//gestion des chiffres non recensés
				{
					cout<<"Erreur: le chiffre que vous avez entré ne correspond à aucune option du menu de jeu"<<endl;
					b_game_continue == false;
				}
				b_game_que_faire = 100;//reset de la variable
			}while(b_game_continue == true);
			b_game_continue = true;//reset de la variable pour pouvoir revenir dans la boucle
		}//FIN CONDITION "Phase Jeu"
		else//Gestion d'eventuels cas inattendus...
		{
			cout<<"Erreur lors du traitement de la variable de selection. Fin du programme"<<endl;
			b_continue = false;
		}
		b_que_faire = 100;
	}
	return 0;
}

//Fonctions explicites
void start_menu()
{
	cout<<"Menu du programme:\n"<<endl;
	cout<<"0 - Fermer le programme."<<endl;
	cout<<"1 - Aller dans le menu de Jeu."<<endl;
}

void game_menu()
{
	cout<<"Menu de jeu:\n"<<endl;
	cout<<"0 - Retourner au menu principal."<<endl;
	cout<<"1 - Lancer la partie contre un bot."<<endl;
	cout<<"2 - Changer votre nom de personnage."<<endl;
	cout<<"3 - Afficher vos informations de personnage."<<endl;
	cout<<"4 - Afficher les informations du bot."<<endl;
}

void press_enter()
{
	cout<<"Appuyez sur Entrée pour continuer..."<<endl;
	cin.get();
}

//int check_int(int var_verif)//Input = entrée de l'utilisateur -> OUTPUT = int vérifié et non null.
//{
//	int var_out = stoi(var_verif);//Vérification de la nature (int) de la variable
//	ostringstream oss;
//	oss<<var_out;
//	if((oss.str().size()) <= 0)//On vérifie que le int est existant
//	{
//		var_out = 100;
//	}
//	else{}
//	return var_out;	
//}
