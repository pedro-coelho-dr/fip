#include <stdio.h>
#include <string.h>

int main(void) {
  char ch;
  char texto[51];
  int i, control_i=1, control_b=1;

  while((ch = getchar()) != EOF){
    i = 0;
    while(ch != '\n'){
      texto[i]=ch;
      i++;
      ch = getchar();
    }
    texto[i] = '\0';
    for (int j=0;j<strlen(texto);j++){
      if (texto[j]=='_' && control_i==1){
        printf("<i>");
        control_i=2;
      }else if(texto[j]=='_' && control_i==2){
        printf("</i>");
        control_i=1;
      }else if(texto[j]=='*' && control_b==1){
        printf("<b>");
        control_b=2;
      }else if(texto[j]=='*' && control_b==2){
        printf("</b>");
        control_b=1;
      }else{
        printf("%c",texto[j]);
      }
    }
    printf("\n");
  }
  return 0;
}