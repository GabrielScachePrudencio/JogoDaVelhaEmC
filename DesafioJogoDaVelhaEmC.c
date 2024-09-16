/* Um exemplo de jogo da velha simples */
#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; /* a matriz do jogo */

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void){
    char done, numeroDeVezes = 1;
    printf("Jogo da velha.\n");
    printf("Voce jogara contra o computador.\n");
    done = ' ';
    init_matrix();
    do {
        
        disp_matrix();
        numeroDeVezes++;
        get_player_move();
        numeroDeVezes++;
        done = check();  /* verifica se ha vencedor */
        if(done!=' ') break;  /* vencedor! */
        get_computer_move();
        done = check();  /* verifica se ha vencedor */
        if(numeroDeVezes == 11) {
          printf("empate\n");
          exit(0);
          break;
        }
        
    } while(done==' ');
    disp_matrix();  /* mostra as posicoes finais */
    if(done=='X') printf("\n Humano ganhou! \n");
    else printf("\n Computador ganhou! \n");
    return 0;
}

/* Inicializa a matriz */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
     for(j=0; j<3; j++) matrix[i][j] = ' ';
}

/* Obtem a sua jogada */
void get_player_move(void)
{
    int x, y;

    printf("Entre com as coordenadas para o X: ");
    scanf("%d %d", &x, &y);
    x--; y--;
    if(matrix[x][y]!=' ') {
          printf("Posicao invalida, tente novamente. \n");
          get_player_move();
    }
    else     matrix[x][y] = 'X';
}

/* Obtem uma jogada do computador */
void get_computer_move(void)
{
  int i, j;

  int contJogadas = 0, contPontas = 0;
  
        // analisa se tem alguma jogada com chance de ganhar
        for (i = 0; i < 3; i++){
          for (j = 0; j < 3; j++){
              if (matrix[i][j] == ' '){
                matrix[i][j] = 'O';
                if(check() == 'O'){ // ele busca na função check que retorna
               //  se os numeros forem iguais na ordem certa para ganhar ela retornara '0' 
               // e se for 0
                  return;
                }
                matrix[i][j] = ' ';
              }
          }
        }


        // ve se o oponente vai ganhar
        for (i = 0; i < 3; i++){
          for (j = 0; j < 3; j++){
              if (matrix[i][j] == ' '){
                matrix[i][j] = 'X';
                if(check() == 'X'){ 
                  matrix[i][j] = 'O';
                  return;
                }
                matrix[i][j] = ' ';
              }
          }
        }


        // tentar fazer a melhor jogada

        //sempre buscar o meio
        if(matrix[1][1] == ' ' && matrix[0][0] == ' ' && matrix[0][2] == ' ' && matrix[2][0] == ' ' && matrix[2][2] == ' '){ matrix[1][1] = 'O'; return; } // colocar smepre return pq ela terminara pq ela 
        //encerra as jogadas dos if

        //tentar os cantos
        if(matrix[0][0] == ' ') { matrix[0][0] = 'O'; return;}
        if(matrix[0][2] == ' ') { matrix[0][2] = 'O'; return;}
        if(matrix[2][0] == ' ') { matrix[2][0] = 'O'; return;}
        if(matrix[2][2] == ' ') { matrix[2][2] = 'O'; return;}
  

        // se o jogador colocar em um dos cantos
        if(matrix[0][0] == 'X' && matrix[2][2] == ' ') { matrix[2][2] = 'O'; return;}
        if(matrix[0][2] == 'X' && matrix[2][0] == ' ') { matrix[2][0] = 'O'; return;}
        if(matrix[2][0] == 'X' && matrix[0][2] == ' ') { matrix[0][2] = 'O'; return;}
        if(matrix[2][2] == 'X' && matrix[0][0] == ' ') { matrix[0][0] = 'O'; return;}


        // para jgoar em qualquer momento que nao houver outra opção
        for (i = 0; i < 3; i++){
          for (j = 0; j < 3; j++){
            if(matrix[i][j] == ' '){
              matrix[i][j] = 'O'; 
              return;
            }           
           }
        }
        
  }
        

    
    
/* Mostra a matriz na tela */
void disp_matrix(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ", matrix[t][0], matrix[t][1],
         matrix[t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}

/* Verifica se ha um vencedor */
char check(void)
{
  int i;

  for(i=0; i<3; i++) /* verifica as linhas */
    if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] && matrix[i][0] != ' ') return matrix[i][0];

  for(i=0; i<3; i++) /* verifica as colunas */
    if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i] && matrix[0][i] != ' ') return matrix[0][i];

  /* testa as diagonais */
  if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[0][0] != ' ') return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[0][2] != ' ')return matrix[0][2];
  
  return ' ';
}
