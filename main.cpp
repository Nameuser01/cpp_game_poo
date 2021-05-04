#include <iostream>
#include <string>

using namespace std;

class Player
{
	public:
	void define_joueur()
	{
		m_vie = 100;
		cout<<"Quel est votre nom"<<endl;
		cout<<"> ";cin>>m_nom;
		cout<<"\n\n"<<endl;
	}
	void define_bot()
	{
		m_vie = 100;
		m_nom = "nightbot";
	}
	void infos()
	{
		cout<<"== Voici les informations de ce personnage ==\n"<<endl;
		cout<<"Nom: "<<m_nom<<endl;
		cout<<"Vie: "<<m_vie<<"\n\n"<<endl;
	}
	
	private:
	int m_vie;
	string m_nom;
};

//Fonctions
void start_menu();

int main()
{
	//bit_vars
	bool b_continue(true);
	int b_que_faire(100);
	//vars
	
	//programme
	while(b_continue == true)//Boucle principale
	{
		start_menu();
		while((b_que_faire > 3) || (b_que_faire < 0))/*Traitement de l'input du bit choix_menu*/
		{
			cout<<"Que voulez vous faire ?\n> ";cin>>b_que_faire;
			cout<<"\n"<<endl;
		}
		if(b_que_faire == 0)//Quitter le programme
		{
			cout<<"Merci d'avoir utilisé ce programme"<<endl;
			b_continue = false;
		}
		else if(b_que_faire == 1)
		{
			start_menu();
		}
		else if(b_que_faire == 2)
		{
			cout<<"Lancer un combat"<<endl;
		}
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
	cout<<"Que voulez vous faire:\n"<<endl;
	cout<<"0 - Fermer le programme."<<endl;
	cout<<"1 - Réafficher le menu de séléction (ci-présent)"<<endl;
	cout<<"2 - Lancer un combat"<<endl;
	cout<<"3 - Changer le nom de votre personnage"<<endl;
}

void game_menu()
{
	cout<<"Menu de jeu:\n"<<endl;
	cout<<"0 - Retourner au menu principal"<<endl;
	cout<<"1 - Lancer la partie contre un bot"<<endl;
	cout<<"3 - Changer votre nom de personnage"<<endl;
}
