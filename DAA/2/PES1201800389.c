int len(char *word);
int len(char *word){
int j=0;
while(word[j]){
        j++;
}

return j;
}



int searchFirstOccurrence(char *pattern, char *text)
{
        int l1=len(pattern);
        int l2=len(text);
        for(int i=0;i<(l2-l1+1);i++)
        {
           int j=0;
           while(j<l1 && pattern[j]==text[i+j] )
           {
                j++;
           }
           if(j==l1)
           {
                return i;
           }
               
        }
        return -1;
}

int searchLastOccurrence(char *pattern, char *text){
 int l1=len(pattern);
 int l2=len(text);
 int c=-1;
for(int i=l2-l1;i>=0;i++)
{
       int j=0;
       while(j<l1 && pattern[j]==text[i+j] )
       {
            j++;
       }
       if(j==l1)
       {
            c=i;
       }
               
    }
    return c;
}

int numOccurrences(char *pattern, char *text)
{
int count=0;
int l1=len(pattern);
int l2=len(text);
for(int i=l2-l1;i>=0;i--)
{
        int j=0;
        while(j<l1 && pattern[j]==text[i+j] )
        {
            j++;
        }
        if(j==l1)
        {
            count++;
        }
               
        }
   return count;
}

int longestPrefix(char *pattern, char *text)
{
        int l1=len(pattern);
        int l2=len(text);
        int c=0;
        for(int i=0;i<(l2-l1+1);i++)
        {
           int j=0;
           while(j<l1 && pattern[j]==text[i+j])
           {
                j++;
           }
           if(j>c)
           {
                c=j;
           }      
        }
        return c;
}

int charactersCompared(char *pattern, char *text)
{      
        int count=0;
        int l1=len(pattern);
        int l2=len(text);
        for(int i=0;i<(l2-l1+1);i++)
        {
           int j=0;
           while(j<l1)
           {
               if(pattern[j]==text[i+j])
               {
                 j++;
                 count++;
               }
               else
               {
                count++;
                break;
               }
               
           }
         
                         
        }
        return count;
}

