#include <stdio.h>
#include <string.h>
/*
#include <iostream>
#include <string>

using namespace std;
  string str ="a h ello hello hello asdasd";
  string pattern = "hello";

  size_t found = 0;
  while(true){
    found = str.find(pattern,found);
    if(found==string::npos)
      break;
    cout<<found++<<endl;                                                       
  }

}
*/

void findPattern(const char * str ,const char * pattern){
  int strLength =  strlen(str);
  int patternLength = strlen(pattern);                                                                                                                                      
  int i,j;·
  int size = strLength - patternLength;
  if(size <= 0)
    return ;
  for(i = 0 ;i < size ;i++){
   for(j = 0 ; j< patternLength ; j++){
    if(str[i+j] != pattern[j])
      break;
    if(j == patternLength-1)
      printf("%d\n",i);
   }   
  }


}

int main(){
  const char * str = "hello hello hello hellchosun";
  const char * pattern = "hello";
  findPattern(str,pattern);

}
