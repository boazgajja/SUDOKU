#include <stdio.h>
#include <stdlib.h>

int sudoku_solver(int **, int );
int isSafe(int **,int,int,int,int);
void print(int **,int);
int main()
{   int n;
    printf("ENTER THE N IN NXN MATRIX :");
    scanf("%d",&n);
     int **arr = (int **)malloc(n * sizeof(int *));
	 for (int i = 0; i < n; i++) {
	       arr[i] = (int *)malloc(n * sizeof(int));
    }
    printf("ENTER THE ELEMENTS IN MATRIX:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    if (sudoku_solver(arr, n)) {
	        // SOLUTION FOUND.
	        printf("SOLUTION FOUND\n");
	        print(arr,n);
	}     
    else{
        printf("NO SOLUTION EXISTS\n");
    }
    getchar();
}
int isSafe(int **arr, int row, int col, int val, int n) {
	    for (int i = 0; i < n; i++) {
	        if (arr[row][i] == val || arr[i][col] == val)
	            return 0;
	    }
        return 1;
}
int sudoku_solver(int **arr, int n) {
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            if (arr[i][j] == 0) {
	                for (int val = 1; val <= n; val++) {
	                    if (isSafe(arr, i, j, val, n)) {
	                        arr[i][j] = val;
	                        if (sudoku_solver(arr, n)) {
	                            if (i == (n - 1) && j == (n - 1)) {
	                                print(arr, n);
	                                arr[i][j] = 0;// backtracking for multiple solutions after find the solution 
	                            } else
	                                return 1;
	                        } else
	                            arr[i][j] = 0; // backtracking for solution
	                    }
	                }
	                return 0;
	            }
	        }
	        
	    }
	    return 1;
	}

void print(int **arr, int n) {
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++)
	            printf("%d ", arr[i][j]);
	        printf("\n");
	    }
	}
	