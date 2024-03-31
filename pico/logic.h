void find_str(char *input, char search, char *output){
    char temp[100] = {'\0'};;
    sprintf(temp, "None");
    int o = 0;
    int i = 0;
    int len = strlen(input);
    
    bool arg_found = false;
    //Find the beggining of the string
    for(i = 0; i<len; i++){
        if (input[i] == '-'){
            if (input[i+1] == search){
                arg_found = true;
                break;
            }
        }
    }
    //Get arg
    if(arg_found == true){
        for(int n = i+3; n<len; n++){
            if ((input[n] == '\n') || (input[n] == '\0') || (input[n+1] == '-')){
                break;
            }
            temp[o] = input[n];
            o++;
        }
    }
    //Return arg
    sprintf(output, "%s", temp);
    return;
}

int intlen(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}

void jointnstr(char *str1, char *str2, int n){
  int j = 0;
  for(int i = strlen(str1); i<n; i++){
    if(j<strlen(str2)){
      str1[i] = str2[j];
      j++;  
    }
  }
}
