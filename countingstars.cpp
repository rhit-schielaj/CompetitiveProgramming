#include <bits/stdc++.h>

int main(){
    // char* buf[512];
    int n, m;
    // FILE* input = stdin;
    std::ifstream file("input.txt"); // Open the file in read mode
    

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> n >> m;
    }

    file.close();

/*
    FILE* input = fopen("input.txt", "r");
    while(fscanf(input, "%d %d", &n, &m)!=EOF){
        char* grid[n];
        for(int i=0; i<n; i++){
            char row[m];
            // fscanf(input, "%s", row);
            // int j =0;
            // char in;
            // do{
            //     in = fgetc(input);
            //     row[j] = in;
            //     j++;
            // }while(in!='\n');
            std::string line;
            std::getline(input, line);
            printf("%*.s\n",m, row);
            grid[i] = row;
        }
    printf("This is what I read:\n");
    for(int i=0; i<n; i++){
        printf("%*.s\n",m, grid[i]);
    }
    }
    */
}