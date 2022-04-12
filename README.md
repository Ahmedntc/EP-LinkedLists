# EP-LinkedLists

Especificacoes 

    Depois de obter as user stories, nos reunimos com nosso time e pensamos em algumas especificacoes 
    tecnicas, para podermos seguir com o desenvolvimento do MVP. Assim, definimos: ´
    • Um episodio de podcast tera as seguintes informacoes: 
    – Nome do Podcast, com no maximo 64 caracteres 
    – PodcastId, um numero inteiro que identifica aquele podcast 
    – Nome do Episodio, com no maximo 64 caracteres 
    – Um numero inteiro que representar a qual e o episodio 
    – Uma lista com palavras-chave do episodio, cada palavra tendo no maximo 64 caracteres

Funções

    Nosso MVP tera em sua execucao os seguintes comandos obrigatorios dentro de um loop infinito: 
    1. adicionar: pede as informacoes do episodio e o insere no fim da playlist 
    2. remover: pede pelo id do podcast e o numero do episodio para poder remove-lo da lista, 
    avisando o usuario apos a remocao (“Episodio XXX do podcast YYY removido!”) 
    3. tocar: imprime o episodio atual (“Estou no  {Episodio X} do Podcast {Y}...”)
    4. shuffle: ativa/desativa a opc¸ao shuffle a avisa ao usuario (“Opcao shuffle ativada!”, ou 
    “Opçãao shuffle desativada!”) 
    5. proximo: imprime o proximo episodio na lista. Se a opcao shuffle estiver ativada, deve 
    ser um episodio aleatorio, diferente da ordem que foram inseridos
    6. relatorio: o programa imprime quais sao os podcasts que existem na playlist, algo 
    como “2 podcasts na sua playlist! Veja abaixo quais sao:”, com a lista de nomes, um por 
    linha (lembra que e possıvel ter mais de um episodio do mesmo podcast?) 

Comandos do Menu

![menu](https://user-images.githubusercontent.com/80297874/162865331-927a0d06-503e-4811-a736-498ed383fc4b.png)   
    
    
    1 - Relatorio da Playlist: imprime a playlist seus podcasts e seus respectivos episodios.
		2 - Tocar Atual: imprime o podcast e episodio atual que e armazenado em um ponteiro na playlist.
		3 - Modo shuffle: torna o proximo da lista um podcast aleatorio
		4 - Tocar o proximo Podcast: toca o proximo na fila
		5 - Adicionar Podcast no fim da playlist: os podcast sao adicionados no fim da lista apos pedir os parametros para o usuario
		6 - Remover um Podcast: remove o podcast com os parametros digitados pelo usuario.


   
    
