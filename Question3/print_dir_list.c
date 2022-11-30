#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <dirent.h>
#include <string.h>
#include<unistd.h>
#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif

void print_dir(DIR *pdir, char *path);

int main(int argc, char *argv[]) 
{ int i = 0;
	DIR *pdir; 
	char strBuffer[_MAX_PATH] = { 0, };
	char *path = NULL;
	struct dirent *pde;
	
	path = getcwd( strBuffer, _MAX_PATH );
	
	printf("%s:\n", path);
	if ((pdir = opendir(argv[1])) < 0 ) { 
		perror("opendir"); 
		exit(1); 
	}
	//print_dir(pdir, path);
	while ((pde = readdir(pdir)) != NULL) {
		printf("%10s ", pde->d_name);
		if (++i % 4 == 0) 
			printf("\n"); 
	}
	printf("\n");
	closedir(pdir);
	return 0; 
} 

void print_dir(DIR *pdir, char *path){
	
	struct dirent *pde;
	int i = 0; 
	char *dir_path;
	
	
	while ((pde = readdir(pdir)) != NULL) {
		printf("%10s ", pde->d_name);
				if (++i % 4 == 0) 
					printf("\n"); 
		/*
		if(!strcmp(pde->d_name, ".") || !strcmp(pde->d_name, "..")){
        	    continue;
        	}// 현재 또는 상위일 경우 제외
        	
		if(pde->d_type == 4){
			sprintf(dir_path, "%s/%s", path, pde->d_name);
			print_dir(pdir, dir_path);
		}else{
			printf("%10s ", pde->d_name);
			if (++i % 4 == 0) 
				printf("\n");
		}*/	
	}
	printf("\n");
}



