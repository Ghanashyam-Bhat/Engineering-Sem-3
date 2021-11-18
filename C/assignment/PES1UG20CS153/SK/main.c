#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    START s;
    init(&s);
    Q q;
    initialize(&q);
    int s_r;
    int s_c;
    int d_r;
    int d_c;
    int row_no;
    int col_no;
    FILE *fp = fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("file doest exsist or permission denied");
    }
    else
    {
        char buffer[80];
        fgets(buffer,80,fp);
        char *coord=strtok(buffer," ");
        s_r=atoi(coord);
        coord=strtok(NULL," ");
        s_c=atoi(coord);
        fgets(buffer,80,fp);
        coord=strtok(buffer," ");
        d_r=atoi(coord);
        coord=strtok(NULL," ");
        d_c=atoi(coord);
        printf("start location : %d %d\n",s_r,s_c);
        printf("destination : %d %d\n",d_r,d_c);
        read_map(fp,&s);
        fclose(fp);
        int res=traversal(&s,&q,s_r,s_c,d_r,d_c);
        store_path(&q,res);
    }
    return 0;
}