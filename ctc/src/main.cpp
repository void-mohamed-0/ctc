#include <cstdio>
#include <print>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//g++ -std=c++23 src/main.cpp -o test && ./test
//sudo rm /usr/local/bin/ctc //to delete the command
//sudo cp '/home/mohamed/code projects/c++/linux/free/test' /usr/local/bin/ctc && sudo chmod +x /usr/local/bin/ctc

int main(int argc,char** argv){
    std::string project_name= "test";
    if(argc<2){std::println("no project name choused");return 1;}
    project_name=argv[1];
    std::string src_path = project_name + "/src";
    std::string main_path = src_path + "/main.cpp";
    if (mkdir(project_name.c_str(),S_IRWXU)==-1){perror("mkdir");};
    if (mkdir(src_path.c_str(),S_IRWXU)==-1){perror("mkdir");};

    int fd = open(main_path.c_str(),O_RDWR|O_CREAT,0644);
    if (fd == -1){perror("open");return 0;}
    std::string main_template ="int main(){}\n";
    if (write(fd,main_template.c_str(),main_template.size())==-1){perror("write");} ;
    close(fd);
}
