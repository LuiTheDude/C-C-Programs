 #include <stdio.h> 
/* count lines, tabs and blanks in input */    
int main(){
    int c, nl; 

    nl = 1;        
    while ((c = getchar()) != EOF)  
        if (c == '\n' || c == '\t' || c == '\b')                
            ++nl;
    printf("%d\n", nl);
}