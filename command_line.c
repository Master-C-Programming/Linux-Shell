#include "header.h"

bool command_line()
{
    char *arg[1024];
    bool flag_pipe = false;
    bool flag_redirection = false;
    int type = 0;
    int index = 0;
    int how = 0;

    fgets(input, 1024, stdin);
    tok = tokens;
    ptr = input;
    type = get_token(&arg[index++]);
    while (type != 1)
    {
        type = get_token(&arg[index]);
        if(type==2)
            index++;
    }
    arg[index] = NULL;
    if (!strcmp(arg[0], "quit") || !strcmp(arg[0], "exit"))
        return false;
    else
    {
        if (!strcmp(arg[0], "cd"))
        {
            change_directory(arg, index);
            return true;
        }
        flag_pipe = is_pipe(arg, index);
        flag_redirection = is_redirection(arg, index);
        
        if (flag_redirection)
			;
        else if (flag_pipe)
			process_pipe(arg, index, how);
        else
        {
            int pid = fork();
            int status = 0;

            if(pid==0)
            {
                execvp(*arg, arg);
                exit(1);
            }
            else
                waitpid(-1,&status,0);
            
        }
        return true;
    }
}
   
