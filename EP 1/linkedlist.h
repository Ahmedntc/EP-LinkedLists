

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// função que faz \n virar \0
void remove_newline_ch(char *line);

//definindo o que os podcasts possuem
 typedef struct podcast{
	int idPodcast;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numEpisodio;
	struct podcast* next;
	struct podcast* prev;

}Podcast;

//ponteiro para a estrutura de podcast
typedef Podcast* PodquestMVP;

//criando  a lista que armazenara os podcasts e seus respectivos episodios, com inicio e fim e um atual que sera usado para tocar o episodio atual 
typedef struct playlist{
	PodquestMVP ini;
	PodquestMVP atual;
	PodquestMVP fim;

	
}Playlist;

//função para criar uma nova playlist com apontamentos para ini atual e fim nulos
Playlist* llNewPlaylist();

//funçao que cria um novo podcast  os dados do podcast que sao dados pelo usuario
PodquestMVP llNewPodcast();

//funçao que insere o podcast criado no final da playlist
void llinserePodcast(Playlist* playlist);

//funçao que recebe o id de um podcast e numero de um episodio do mesmo para ser removido da playlist desejada
void llremovePodcast(Playlist* playlist, char nomePodcast[64], int numEpisodio);

//funçao de busca na playlist para auxiliar na remoçao 
PodquestMVP llBuscaPodcast(Playlist* playlist, char nomePodcast[64], int numEpisodio);

//função que toca o proximo podcast que recebe shuffle como parametro podendo estar ou nao ativado, quando verdadeiro o proximo episodia a ser tocado sera aleatorio
void lltocarNext(Playlist* playlist, bool shuffle);

//funçao que toca o podcast atual
void lltocar(Playlist* playlist);

//função que imprime a playlist
void llimprimeRelatorio(Playlist* playlist);







