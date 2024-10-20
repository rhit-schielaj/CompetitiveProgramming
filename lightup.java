import java.util.Scanner;

class lightup{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        char[][] board = new char[n+2][n+2];
        // System.out.println(n);
        for(int i =0; i<n+2; i++){
            char[] temp = new char[1];
            if(i>0 && i<n+1) temp= input.nextLine().toCharArray();
            for(int j = 0; j<n+2; j++){
                if(i==0 || j==0 || i==n+1 || j==n+1){
                    board[i][j] = 'w';
                }
                else{
                    board[i][j] = temp[j-1];
                }
            }
            // board[i+1] = input.nextLine().toCharArray();
        }
        // printBoard(board);
        // checkLight(1, 7, board);
        for(int i=1; i<n+1; i++){
            for(int j =1; j<n+1; j++){
                if(board[i][j] == '?'){
                    if(!checkLight(i, j, board)){
                        System.out.println("0");
                        return;
                    }
                }
                else if(isBarrier(board[i][j])){
                    if(!checkBarrier(i, j, board)){
                        System.out.println("0");
                        return;
                    }
                }
            }
        }
        // printBoard(board);
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                if(board[i][j]=='.'){
                    System.out.println("0");
                    return;
                }
            }
        }
        System.out.println("1");
        return;
        
    }

    public static boolean checkLight(int i, int j, char[][] board){
        int row = i+1;
        int col = j;
        while(true){
            char temp = board[row][col];
            // System.out.println("Row: " + row + " | Col: " + col + " | temp: " + temp);
            if(temp == '?'){
                return false;
            }
            if(isBarrier(temp) || temp=='X' || temp=='w'){
                break;
            }
            board[row][col] = 'T';
            ++row;
        }

        row = i-1;
        col = j;
        while(true){
            char temp = board[row][col];
            // System.out.println("Row: " + row + " | Col: " + col + " | temp: " + temp);
            if(temp == '?'){
                return false;
            }
            if(isBarrier(temp) || temp=='X' || temp=='w'){
                break;
            }
            board[row][col] = 'T';
            --row;
        }

        row = i;
        col = j+1;
        while(true){
            char temp = board[row][col];
            // System.out.println("Row: " + row + " | Col: " + col + " | temp: " + temp);
            if(temp == '?'){
                return false;
            }
            if(isBarrier(temp) || temp=='X' || temp=='w'){
                break;
            }
            board[row][col] = 'T';
            ++col;
        }

        row = i;
        col = j-1;
        while(true){
            char temp = board[row][col];
            // System.out.println("Row: " + row + " | Col: " + col + " | temp: " + temp);
            if(temp == '?'){
                return false;
            }
            if(isBarrier(temp) || temp=='X' || temp=='w'){
                break;
            }
            board[row][col] = 'T';
            --col;
        }

        return true;
    }

    public static boolean checkBarrier(int i, int j, char[][] board){
        int num = 0;
        if(board[i-1][j] == '?'){++num;}
        if(board[i+1][j] == '?'){++num;}
        if(board[i][j-1] == '?'){++num;}
        if(board[i][j+1] == '?'){++num;}
        if(num!=(board[i][j] - '0')){
            return false;
        }
        return true;
    }

    public static boolean isBarrier(char check){
        if(check == '0' ||
        check == '1' ||
        check == '2' ||
        check == '3' ||
        check == '4' ){
            return true;
        }
        return false;
    }

    public static void printBoard(char[][] board){
        for(int i=1; i<board.length-1; i++){
            for(int j =1; j<board[0].length-1; j++){
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }
}