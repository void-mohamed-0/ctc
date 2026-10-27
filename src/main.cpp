#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <print>
#include <string>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//g++ -std=c++23 src/main.cpp -o test && ./test
//sudo rm /usr/local/bin/ctc //to delete the command
//sudo cp '/home/mohamed/code projects/c++/linux/free/test' /usr/local/bin/ctc && sudo chmod +x /usr/local/bin/ctc

int main(int argc,char** argv){
    if (argc<2){std::println("no command choused");return 1;}
    std::string first_command=argv[1];
    // NEW PROJECT
    if (first_command == "new"){
        std::string project_name= "test";
        std::string target_programing_language = "cpp";
        if(argc<3){std::println("no project name choused");return 1;}
        project_name=argv[2];
        if (argc < 4 and argc > 3){target_programing_language = argv[4];}
        std::string src_path = project_name + "/src";
        std::string main_path = src_path + "/main."+target_programing_language;
        if (mkdir(project_name.c_str(),S_IRWXU)==-1){perror("mkdir");return 1;};
        if (mkdir(src_path.c_str(),S_IRWXU)==-1){perror("mkdir");return 1;};

        int compile_flags_fd =open("compile_flags.txt", O_RDWR|O_CREAT,0644);
        if (compile_flags_fd ==-1 ){
            std::println("failed to create compile_flags.txt ");perror("open");return -1;
        }





        int fd = open(main_path.c_str(),O_RDWR|O_CREAT,0644);
        if (fd == -1){perror("open");return 0;}
        std::string main_template ="int main(){}\n";
        if (write(fd,main_template.c_str(),main_template.size())==-1){perror("write");} ;
        close(fd);
        return 0;
    // HELP COMMAND
    }else if (first_command == "help") {
        std::println("possible commandse for now are : \n"
            "   new \n"
            "   build\n"
                    );
        return 0;
    //BUILD COMMAND
    }else if (first_command == "build") {
        //i must learn cmake and git i know
        std::string basic_build_command = "make";
        if(system(basic_build_command.c_str())== -1){perror("system");return 0;};
    }

}
