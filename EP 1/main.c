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
        printf("\n  MENU\n");
        printf(" -------------------------------");
        printf("\n  1 - Relatorio da Playlist");
		printf("\n  2 - Tocar Atual");
		printf("\n  3 - Modo shuffle");
		printf("\n  4 - Tocar o proximo Podcast");
		printf("\n  5 - Adicionar Podcast no fim da playlist");
		printf("\n  6 - Remover um Podcast");
        printf("\n  Digite sua escolha:");

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
                if(shuffle){
                    printf("\nShuffle desativado\n");
                    shuffle = false;
                }else{
                    shuffle = true;
                    printf("\nShuffle ativado\n");
                }
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