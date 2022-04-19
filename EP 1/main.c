#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.c"


int main(){
    int opt = 0;
    bool shuffle = false;

    Playlist* playlist = llNewPlaylist();
    //menu do app 
    do{
        printf("\nMENU\n");
        printf("-------------------------------");
        printf("\n1 - Relatorio da Playlist");
		printf("\n2 - Tocar Atual");
		printf("\n3 - Ativar ou desativar o Modo shuffle");
		printf("\n4 - Tocar o proximo Podcast");
		printf("\n5 - Adicionar Podcast no fim da playlist");
		printf("\n6 - Remover um Podcast");
        printf("\nDigite sua escolha:");

        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                llimprimeRelatorio(playlist);    
                break;
            case 2: 
                lltocar(playlist);
                break;
            case 3:
                llshuffleStatus(shuffle);
                break;
            case 4:
                lltocarNext(playlist, shuffle);
                break;
            case 5:
                llinserePodcastFim(playlist);
                break;
            case 6:
                llremovePodcast(playlist);
                break;
            default:
                printf("\nOpcao inexistente tente novamente!");
                break;
        }
    }while(opt != 0);




    return 0;
}