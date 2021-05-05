#include <iostream>
#include <string>
using namespace std;

class Player
{
	public:
	void define_joueur()
	{
		m_vie = 10;
		m_categorie = "Joueur";
		cout<<"Quel est votre nom"<<endl;
		cout<<"> ";cin>>m_nom;
	}
	void define_bot()
	{
		m_vie = 10;
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
	void change_nom()
	{
		cout<<"Quel est le nouveau nom ?"<<endl;
		cout<<"> ";cin>>m_nom;
	}
	int nom_length()
	{
		int length;
		length = m_nom.length();
		return length;
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
void game_menu();
void press_enter();

int main()
{
	//bit_vars
	bool b_continue(true);
	int b_que_faire(100);
	int selec_infos_to_print(0);
	
	//vars
	int foo;
	
	Player player, bot;
	game_menu();
	while(b_continue == true)//Boucle principale
	{
		while((b_que_faire > 4) || (b_que_faire < 0))/*Traitement de l'input du bit de choix de menu*/
		{
			cout<<"Que voulez vous faire ?"<<endl;
			cout<<"> ";
			cin>>b_que_faire;
		}
		if(b_que_faire == 0)//Quitter le programme
		{
			cout<<"Au revoir !"<<endl;
			b_continue = false;
		}
		else if(b_que_faire == 1)//Lancer la partie
		{
			if(player.nom_length() > 0)
			{
				//Ne rien faire
			}
			else
			{
				player.define_joueur();
			}
			if (bot.nom_length() > 0)
			{
				//Ne rien faire
			}
			else
			{
				bot.define_bot();
			}
			//C'est ici que le combat prend place ! (Ça va être long à créer)
			cout<<"Le combat !"<<endl;
		}
		else if(b_que_faire == 2)//changer nom personnage
		{
			if(player.nom_length() > 0)
			{
				player.change_nom();
			}
			else
			{
				player.define_joueur();
			}
		}
		else if(b_que_faire == 3)//Afficher les informations des personnages
		{
			cout<<"Voulez vous afficher vos infos (1) ou celles du bot (2) ?"<<endl;
			cout<<"> ";
			cin>>selec_infos_to_print;
			if(selec_infos_to_print == 1)//Afficher les infos du joueur
			{
				if(player.nom_length() > 0 )
				{
					player.infos();
				}
				else
				{
					cout<<"Veuillez créer votre personnage, il n'existe pas encore !"<<endl;
					player.define_joueur();
					player.infos();
				}
			}
			else if(selec_infos_to_print == 2)//Afficher les infos du bot
			{
				if(player.nom_length() > 0)
				{
					bot.infos();
				}
				else
				{
					bot.define_bot();
					bot.infos();
				}
			}
			else//Exeptions
			{
				cout<<"ERREUR: La valeur entrée n'est pas valide !"<<endl;
			}
			selec_infos_to_print = 0;
		}
		else//Gestion d'eventuels cas inattendus
		{
			cout<<"Erreur lors du traitement de la variable de selection. Fin du programme"<<endl;
			b_continue = false;
		}
		b_que_faire = 100;
		cout<<"\n"<<endl;
	}
	return 0;
}

//Fonctions explicites
void game_menu()
{
	cout<<"Menu de jeu:\n"<<endl;
	cout<<"0 - Retourner au menu principal."<<endl;
	cout<<"1 - Lancer la partie contre un bot."<<endl;
	cout<<"2 - Changer votre nom de personnage."<<endl;
	cout<<"3 - Afficher vos informations des personnages."<<endl;
}

void press_enter()
{
	cout<<"Appuyez sur Entrée pour continuer..."<<endl;
	cin.get();
}
