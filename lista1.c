/*lista1
Escreva um programa com OpenGL e freeglut que trate os seguintes eventos:
Redimensionamento de tela: escreva no terminal o valor da nova largura e altura da tela.
Pressionamento de tecla: escreva no terminal qual tecla foi pressionada e qual a posição do mouse quando isso ocorreu.
Clique do mouse: escreva no terminal qual botão foi pressionado (ex: esquerdo), o estado dele (ex: soltou) e a posição do mouse quando isso ocorreu.
Movimento do mouse: escreva no terminal a posição do mouse.
*/

#include <stdio.h>
#include <GL/glew.h>     
#include <GL/freeglut.h>

unsigned int vetor[26];
char alfabeto [27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
'q','r','s','t','u','v','w','x','y','z'};
//letra 'a' na tabela ASC2
unsigned int letra = 97;

void desenhaMinhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void movimentoMouse (int x, int y) {
    printf("Posição do mouse x = %d, y = %d\n", x, y);
}

void movimentoMouseClicando(int x, int y) {
    printf("Posição do mouse x = %d, y = %d\n", x, y);
}

void cliqueMouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON)
            printf("Botão esquerdo do mouse pressionado  ");
        else if(button == GLUT_RIGHT_BUTTON)
            printf("Botão direito do mouse pressionado  ");
        else if(button == GLUT_MIDDLE_BUTTON)
            printf("Botão do meio do mouse pressionado  ");
        printf("Posição x = %d, e y = %d\n", x, y);
    }else if(state == GLUT_UP){
         if(button == GLUT_LEFT_BUTTON)
            printf("Botão esquerdo do mouse foi solto  ");
        else if(button == GLUT_RIGHT_BUTTON)
            printf("Botão direito do mouse foi solto  ");
        else if(button == GLUT_MIDDLE_BUTTON)
            printf("Botão do meio do mouse foi solto  ");
        printf("Posição do mouse x = %d, e y = %d\n", x, y);
    }
}

void teclaPressionada(unsigned int key, int x, int y) {
    
    int i;
    for(i=0; i<27; i++){
        if(key == vetor[i])
            break;
    }
    if(i<=25){
        printf("Tecla Pressionada: '%c'", alfabeto[i]);
    }else{
        printf("Tecla Pressionada não registrada");
    }
    printf(" e a posição do mouse x = %d, e y = %d\n", x, y);

}

void redimensionaTela(int width, int height) {
   glViewport(0, 0, width, height);
   
   printf("Janela redimensionada nova largura = %d e altura = %d\n",width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 100, 0, 100, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv) {
    //inicializa o vetor de tabelas ASC2 começa no 97 que é a letra 'a'
    for(int i=0; i<26; i++){
        vetor[i] = letra;
        letra ++;
    }   
    glutInit(&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lista1");

    glutDisplayFunc(desenhaMinhaCena);
    glutKeyboardFunc(teclaPressionada);
    glutReshapeFunc(redimensionaTela);
    glutPassiveMotionFunc(movimentoMouse);
    glutMotionFunc(movimentoMouseClicando);
    glutMouseFunc(cliqueMouse);

    glutMainLoop();
    return 0;
}