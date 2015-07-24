//
//  main.cpp
//  print_2D_array_in_spiral_order
//
//  Created by Jiancong Guo on 7/24/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
# define COLUMN 4

/*int myarray[][3][4]
The first parameter could be empty, the following parameter could not be emppty
 */
void print_2D_array_in_spiral_order(int arg[][COLUMN], int row){
    //int dir = 0;
    int top = 0;
    int button = row-1;
    int left = 0;
    int right = COLUMN-1;
    while((top<=button) && (left<= right)){
        for(int i=left; i<=right; i++)
            std::cout<< arg[top][i]<<' ';
        ++top;
        std::cout<<std::endl;
        
        for(int i=top; i<= button; i++)
            std::cout<<arg[i][right]<<' ';
        --right;
        std::cout<<std::endl;
        
        for(int i=right; i>=left; i--)
            std::cout<<arg[button][i]<<' ';
        --button;
        std::cout<<std::endl;
        
        for(int i=button; i>=top; i--)
            std::cout<<arg[i][left]<<' ';
        ++left;
        std::cout<<std::endl;
    }    
}

int main(int argc, const char * argv[])
{

    // insert code here...
    int b[5][4];
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            b[i][j] = rand()%100;  // all elements are in range 0 to 100
            std::cout << b[i][j]<<'\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    print_2D_array_in_spiral_order(b, 5);
    
    return 0;
}

