
#include "linkedlist.h"

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

Playlist* llNewPlaylist(){
    Playlist* newPlaylist = malloc(sizeof(Playlist));


    newPlaylist->ini = NULL;
	newPlaylist->atual = NULL;
	newPlaylist->fim = NULL;

	return newPlaylist;
}

//cria novo podcast
PodquestMVP  llNewPodcast()
{	
    PodquestMVP newPodcast = (PodquestMVP)malloc(sizeof(Podcast));
	
	printf("\nId do Podcast: ");
	scanf("%d", &newPodcast->idPodcast);
	getchar();

	printf("\nNome do Podcast: ");
	fgets(newPodcast->nomePodcast, 64, stdin);
	remove_newline_ch(newPodcast->nomePodcast);
	
	printf("\nNome do Episodio: ");
	fgets(newPodcast->nomeEpisodio, 64, stdin);
	remove_newline_ch(newPodcast->nomeEpisodio);

	printf("\nNumero do Episodio: ");
	scanf("%d", &newPodcast->numEpisodio);
	getchar();

	newPodcast->next = NULL;
	newPodcast->prev = NULL;

	return newPodcast;
}

void llinserePodcast(Playlist* playlist){
    PodquestMVP newPodcast = llNewPodcast();
    newPodcast->idPodcast = 0;
    for(PodquestMVP aux = playlist->ini; aux != NULL; aux = aux->next){
        if(aux->idPodcast == newPodcast->idPodcast)
            newPodcast->idPodcast++;
    }
    if(playlist->ini == NULL){
        playlist->ini = newPodcast;
        playlist->fim = newPodcast;
        playlist->atual = playlist->ini;
    }   
	playlist->fim->next= newPodcast;
	newPodcast->prev = playlist->fim;
	playlist->fim = newPodcast;
}

PodquestMVP llBuscaPodcast(Playlist* playlist, char nomeAlvo[64], int epAlvo){
    
    for (PodquestMVP aux = playlist->ini; aux != NULL; aux = aux->next)
    {
		if (strcmp(aux->nomePodcast, nomeAlvo) == 0 && aux->numEpisodio == epAlvo) 
			return aux;	
	}
	//Podquest nao encontrado
    printf("\n Podcast nao foi encontrado na playlist");
	return NULL;
}

void llremovePodcast(Playlist* playlist){
    char nomeAlvo[64];
    int epAlvo = 0; 

    printf("\nNome do podcast a ser removido:");
    fgets(nomeAlvo, 64, stdin);
    remove_newline_ch(nomeAlvo);

    printf("\nNumero do episodio a ser removido do podcast:");
    scanf("%d", &epAlvo);
    getchar();

    PodquestMVP targetEpisode = llBuscaPodcast(playlist, nomeAlvo, epAlvo);
    if (targetEpisode != NULL)
    {
        if (targetEpisode == playlist->ini)
        {
            if(playlist->ini->next != NULL) 
            {
                playlist->ini = playlist->ini->next;
			    playlist->ini->prev = NULL;
            } 
            else
            {
                playlist->ini = NULL;
                playlist->fim = NULL;
            }
            printf("Podcast removido!");
			
			return;
		}
		else if (targetEpisode == playlist->fim)
		{
            if(playlist->fim->prev != NULL)
            {
                playlist->fim = playlist->fim->prev;
			    playlist->fim->next = NULL;
            }
            else 
            {
                if(playlist->ini != NULL)
                {
                    playlist->fim = playlist->ini;
                } 
                else
                {
                    playlist->fim = NULL;
                }
            }
            printf("Podcast removido!");
			return;
		}



	}
    else
    {
        printf("nao encontrei");
            
    }
}

void lltocar(Playlist* playlist){
    if(playlist->ini != NULL)
    {
        printf("\n%s", playlist->atual->nomePodcast);
        printf(" #%d- %s", playlist->atual->numEpisodio, playlist->atual->nomeEpisodio);
    }
    else{
        printf("\nPlaylist vazia!");
    }
}

void lltocarNext(Playlist* playlist, bool shuffle){
    if(playlist->ini != NULL)
    {
        if(shuffle){
            while (true)
			{
				srand(time(NULL));
				int aux = rand() % sizeof(playlist) + 1;
                playlist->fim->next = playlist->ini;

                //PodquestMVP ajudante = playlist->atual->next->next;
                for (int i = 0; i < aux; i++)
				{
					playlist->atual = playlist->atual->next->next->next;
				}
            }
        }
        else {
            if(playlist->atual->next != NULL){
                playlist->atual = playlist->atual->next;
                lltocar(playlist);
            }
        }
    }
    else{
        printf("\nPlaylist vazia!");
    }    
}

void llimprimeRelatorio(Playlist* playlist){
    
	if (playlist->ini != NULL)
	{
		//guardando o atual em uma aux para percorrer a playlist sem perde-lo
        PodquestMVP aux = playlist->atual;

		int qtdPodcasts = 0, qtdEpisodios = 0;


		for (playlist->atual = playlist->ini; playlist->atual != NULL; playlist->atual = playlist->atual->next)
		{
			qtdEpisodios++;
			qtdPodcasts++;
		}
        playlist->atual = aux;
		printf("\nSua Playlist possui %d Podcasts e %d episodios diferentes sendo eles: \n", qtdPodcasts, qtdEpisodios);
		
		for (playlist->atual = playlist->ini; playlist->atual != NULL; playlist->atual = playlist->atual->next)
		{
            if(playlist->atual != NULL){
			    printf("\nPodcast: %s",  playlist->atual->nomePodcast);
			    printf("\nEpisodio: %d - %s\n", playlist->atual->numEpisodio, playlist->atual->nomeEpisodio);
            }
		}
		playlist->atual = aux;
	}
	else
	{
		printf("\nA Playlist esta vazia!\n");
	}
}


