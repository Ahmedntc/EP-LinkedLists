#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.c"


int main(){
    int opt = 0, epAlvo = 0;
    char nomeAlvo[64];
    bool shuffle = false;
    Playlist* playlist = llNewPlaylist();


    do{
        printf("\n1 - Relatorio da Playlist");
		printf("\n2 - Tocar Atual");
		printf("\n3 - Modo shuffle");
		printf("\n4 - Tocar o proximo Podcast");
		printf("\n5 - Adicionar Podcast na playlist");
		printf("\n6 - Remover Podcast");
        printf("\nSua escolha:");

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
                    printf("\nShuffle desativado");
                    shuffle = false;
                }else{
                    shuffle = true;
                    printf("\nShuffle ativado");
                }
                break;
            case 4:
                lltocarNext(playlist, shuffle);
                break;
            case 5:
                llinserePodcast(playlist);
                break;
            case 6:
                llremovePodcast(playlist);
                break;
            default:
                break;
        }





    }while(opt != 0);




    return 0;
}