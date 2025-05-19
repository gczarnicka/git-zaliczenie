#include <LPC21xx.H>


#define NULL '\0'


void CopyString (char pcSource[], char pcDestination[]) {
    unsigned char ucCharCounter = 0;

    for(ucCharCounter = 0; pcSource[ucCharCounter] != NULL; ucCharCounter++) {
    pcDestination[ucCharCounter] = pcSource[ucCharCounter];
    }
    pcDestination[ucCharCounter] = NULL;
}

enum CompareResult{ DIFFERENT,EQUAL };
	
enum CompareResult eCompareString(char pcStr1[], char pcStr2[]) {
    unsigned char ucCharCounter = 0;

    for (ucCharCounter = 0; pcStr1[ucCharCounter] == pcStr2[ucCharCounter]; ucCharCounter++) {
        if (pcStr1[ucCharCounter] == NULL) {
            return EQUAL;
        }
    }
    return DIFFERENT;
}

void AppendString (char pcSourceStr[],char pcDestinationStr[]) {
    unsigned char ucCharCounter = 0;
    
    for(ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL; ucCharCounter++){}
    
    CopyString(pcSourceStr, pcDestinationStr + ucCharCounter);
}

void ReplaceCharactersInString (char pcString[], char cOldChar, char cNewChar) {
    unsigned char ucCharCounter = 0;
    
    for (ucCharCounter = 0; pcString[ucCharCounter] != NULL; ucCharCounter++) {
        if (pcString[ucCharCounter] == cOldChar) {
        pcString[ucCharCounter] = cNewChar;
        }
    }
}


int main() {	
    /*char pcSource[] = "Gabriela"; 
    char pcDestination[] = "Czarnicka" ;
	  CopyString(pcSource, pcDestination);
    
	  char pcStr1[] = "Gabriela";
    char pcStr2[] = {'G','a','b','r','i','e','l','a'};
    eCompareString(pcStr1, pcStr2);
    
    char pcSourceStr[] = "Czarnicka";
    char pcDestinationStr[] = "Gabriela";
    AppendString (pcSourceStr, pcDestinationStr);*/
    
    char pcString[] = "gaga";
    ReplaceCharactersInString (pcString, 'g', 'b');
}
