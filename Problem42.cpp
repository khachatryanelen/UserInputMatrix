#include <iostream>

void initMatrix(int** matrix,int line,int column){
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            matrix[i][j]=rand()%10;
        }
    }
}
void printMatrix(int** matrix,int line,int column){
    for(int i=0;i<line;i++){
        for(int j=0;j<column;j++){
            std::cout<< matrix[i][j] << " ";            
        }
        std::cout << std::endl;
    }
}
int digit(char a){
    int result=0;
    switch (a) {
        case '1':
            result= 1;
            break;
        case '2':
            result= 2;
            break;
        case '3':
            result= 3;
            break;
        case '4':
            result= 4;
            break;
        case '5':
            result= 5;
            break;
        case '6':
            result= 6;
            break; 
        case '7':
            result= 7;
            break;
        case '8':
            result= 8;
            break;
        case '9':
            result= 9;
            break;
        case '0':
            result= 0;
            break;  
        default:
            result=-1;
            break;
    }
    return result;
}
int convertToInt(std::string& str){
    int i=0,result=0,sign=1;
    if(str.at(i)=='-') {
        sign=-1;
        i++;
    }
    while(str.at(i)!='*'){
        result=result*10+digit(str.at(i));
        i++;
    }
    return result*sign;
}

int main(int argc,const char* argv[]) {
    std::string x,y;
    if(argc!=3){
        std::cout<<"You should give exactly two number."<<std::endl;
        return 0;
    }
    else{
        x=argv[1];
        y=argv[2];
        x=x+"*";
        y=y+"*";
    }
    int line=convertToInt(x);
    int column=convertToInt(y);
    if(line<=0 || column<=0){
        return 0;
    }
    int ** matrix=(int**)malloc(line*sizeof(int*));
    for(int i=0;i<line;i++){
        matrix[i]=(int*)malloc(column*sizeof(int));
    }
    initMatrix(matrix,line,column);
    printMatrix(matrix,line,column);
    
    for(int i=0;i<line;i++){
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
