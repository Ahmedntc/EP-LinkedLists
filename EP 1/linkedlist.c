
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
    PodquestMVP newPodcast = (PodquestMVP*)malloc(sizeof(Podcast));
	
	printf("\nId do Podcast: ");
	scanf("%d", &newPodcast->idPodcast);
	getchar();

	printf("\nNome do Podcast: ");
	fgets(newPodcast->nomePodcast, 64, stdin);
	remove_newline_ch(newPodcast->nomePodcast);
	

	printf("\nNumero do Episodio: ");
	scanf("%d", &newPodcast->numEpisodio);
	getchar();

    printf("\nNome do Episodio: ");
	fgets(newPodcast->nomeEpisodio, 64, stdin);
	remove_newline_ch(newPodcast->nomeEpisodio);


	newPodcast->next = NULL;
	newPodcast->prev = NULL;

	return newPodcast;
}

void llinserePodcastFim(Playlist* playlist){
    PodquestMVP newPodcast = llNewPodcast();

    for(PodquestMVP aux = playlist->ini; aux != NULL; aux = aux->next){
        if(aux->idPodcast == newPodcast->idPodcast)
            newPodcast->idPodcast++;
    }
    if(playlist->ini == NULL){
        playlist->ini = newPodcast;
        playlist->fim = newPodcast;
        playlist->atual = playlist->ini;
        newPodcast->next = NULL;
        newPodcast->prev = NULL;
    }else
    {
        newPodcast->prev = playlist->fim;
        newPodcast->next = NULL;
	    playlist->fim->next= newPodcast;
	    playlist->fim = newPodcast;
    }
    free(newPodcast);
}

PodquestMVP llBuscaPodcast(Playlist* playlist, char nomeAlvo[64], int epAlvo){
    
    for (PodquestMVP aux = playlist->ini; aux != NULL; aux = aux->next)
    {
		if (strcmp(aux->nomePodcast, nomeAlvo) == 0 && aux->numEpisodio == epAlvo) 
			return aux;	
	}
	//Podquest nao encontrado
    printf("\nPodcast nao foi encontrado na playlist");
	return NULL;
}

void llremovePodcast(Playlist* playlist){
    char nomeAlvo[64];
    int epAlvo = 0; 

    printf("\nNumero do episodio a ser removido do podcast:");
    scanf("%d", &epAlvo);
    getchar();

    printf("\nNome do podcast a ser removido:");
    fgets(nomeAlvo, 64, stdin);
    remove_newline_ch(nomeAlvo);

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
}

void lltocar(Playlist* playlist){
    if(playlist->ini != NULL)
    {
        printf("\nPodcast: %s", playlist->atual->nomePodcast);
        printf("\nEpisodio: #%d- %s", playlist->atual->numEpisodio, playlist->atual->nomeEpisodio);
    }
    else if(playlist->ini->next = NULL){
        printf("\nNao tem proximo na fila!");
    }
    else{
        printf("\nPlaylist vazia!");
    }
}

void lltocarNext(Playlist* playlist, bool shuffle){
    PodquestMVP ajudante = playlist->atual;
    if(playlist->ini != NULL)
    {
        if(ajudante != NULL && ajudante->next != NULL)
        {
            if(shuffle)
            {
                while(true)
			    {
                    for(; ajudante->next != NULL; ajudante = ajudante->next)
				    {
					    playlist->atual->next = playlist->atual->next->next->next;
				    }
                }
            }
            else
            {
                printf("\nPodcast: %s", ajudante->next->nomePodcast);
                printf("\nEpisodio: #%d- %s", ajudante->next->numEpisodio, ajudante->next->nomeEpisodio);                
                playlist->atual = playlist->atual->next;
            }
        }
    }else{
        printf("\nPlaylist Vazia!");
    } 
    free(ajudante);

}

void llimprimeRelatorio(Playlist* playlist){
    
	if (playlist->ini != NULL)
	{
		//guardando o atual em uma aux para percorrer a playlist sem perde-lo
        PodquestMVP aux = playlist->atual;

		int qtdPodcasts = 0;


		for (playlist->atual = playlist->ini; playlist->atual != NULL; playlist->atual = playlist->atual->next)
		{
			qtdPodcasts++;
		}
        playlist->atual = aux;
		printf("\nSua Playlist possui %d Podcasts diferentes sendo eles: \n", qtdPodcasts);
		
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
		printf("\nPlaylist vazia!\n");
	}
}


