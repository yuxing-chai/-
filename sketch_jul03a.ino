#include <Mouse.h>

char MORSE[][4]={
  {'.','-','*','*'},
  {'-','.','.','.'},
  {'-','.','-','.'},
  {'-','.','.','*'},
  {'.','*','*','*'},
  {'.','.','-','.'},
  {'-','-','.','*'},
  {'.','.','.','.'},
  {'.','.','*','*'},
  {'.','-','-','-'},
  {'-','.','-','*'},
  {'.','-','.','.'},
  {'-','-','*','*'},
  {'-','.','*','*'},
  {'-','-','-','*'},
  {'.','-','-','.'},
  {'-','-','.','-'},
  {'.','-','.','*'},
  {'.','.','.','*'},
  {'-','*','*','*'},
  {'.','.','-','*'},
  {'.','.','.','-'},
  {'.','-','-','*'},
  {'-','.','.','-'},
  {'-','.','-','-'},
  {'-','-','.','.'},
};

void setup(){
  Serial.begin(9600);//
}
void loop(){
  String str = "";
  String morse = "";
  int i,t,temp=0;
  int n=0;
  while(Serial.available()>0){
    temp=1;
    str +=char(Serial.read());
    delay(2);
    n++;
  }
  if(temp){
    for(i=0;i<n;i++)
    {
      for(t=0;t<4;t++)
      {
        if(str[i]>=97&&str[i]<=122)
        {
          morse += char(MORSE[int(str[i]-97)][t]);
        }
      }
    }
    Serial.println(morse);
  }
  delay(2);
}
