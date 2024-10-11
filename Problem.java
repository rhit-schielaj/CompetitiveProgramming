import java.util.LinkedList;
import java.util.Scanner;

public class Problem {

     public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int rows = input.nextInt();
        int cols = input.nextInt();
        input.nextLine();
        char[][] board1 = new char[rows][cols];
        for(int i =0; i<rows; i++){
            board1[i] = input.nextLine().toCharArray();
        }

        char maxval = '0';
        for(int i =0; i<board1.length; i++){
            for(int j = 0; j<board1[0].length; j++){
                if(board1[i][j]>maxval && board1[i][j]!='.' && board1[i][j] !='A'){
                    maxval = board1[i][j];
                }
            }
        }

        LinkedList<char[][]> queue = new LinkedList<char[][]>();
        queue.add(board1);
        while(!queue.isEmpty()){
            char[][] board = queue.poll();
            int i = 0;
            int j = 0;
            while(board[i][j]!='0'){
                while(board[i][j]!='0'){
                    ++j;
                    if(j==cols){j = 0; break;}
                }
                if(board[i][j]=='0'){break;}
                i++;
            }
            if(j<board[0].length - 1){
                if(board[i][j+1]=='A'){
                    System.out.println("1");
                    return;
                }
                if(board[i][j+1]=='.'){
                    char[][] newBoard = deepClone(board);
                    newBoard[i][j+1] = '0';
                    propogate(newBoard, i, j+1, '0');
                    queue.add(newBoard);
                }
                else if(board[i][j+1]==maxval){
                    char[][] newBoard = deepClone(board);
                    propogate(newBoard, i, j, '1');
                    newBoard[i][j] = '1';
                    newBoard[i][j+1] = '0';
                    queue.add(newBoard);
                }
            }
            if(i<board.length - 1){
                if(board[i+1][j]=='A'){
                    System.out.println("1");
                    return;
                }
                if(board[i+1][j]=='.'){
                    char[][] newBoard = deepClone(board);
                    newBoard[i+1][j] = '0';
                    propogate(newBoard, i+1, j, '0');
                    queue.add(newBoard);
                }
                else if(board[i+1][j]==maxval){
                    char[][] newBoard = deepClone(board);
                    propogate(newBoard, i, j, '1');
                    newBoard[i][j] = '1';
                    newBoard[i+1][j] = '0';
                    queue.add(newBoard);
                }
            }
            if(i>0){
                if(board[i-1][j]=='A'){
                    System.out.println("1");
                    return;
                }
                if(board[i-1][j]=='.'){
                    char[][] newBoard = deepClone(board);
                    newBoard[i-1][j] = '0';
                    propogate(newBoard, i-1, j, '0');
                    queue.add(newBoard);
                }
                else if(board[i-1][j]==maxval){
                    char[][] newBoard = deepClone(board);
                    propogate(newBoard, i, j, '1');
                    newBoard[i][j] = '1';
                    newBoard[i-1][j] = '0';
                    queue.add(newBoard);
                }
            }
            if(j>0){
                if(board[i][j-1]=='A'){
                    System.out.println("1");
                    return;
                }
                if(board[i][j-1]=='.'){
                    char[][] newBoard = deepClone(board);
                    newBoard[i][j-1] = '0';
                    propogate(newBoard, i, j-1, '0');
                    queue.add(newBoard);
                }
                else if(board[i][j-1]==maxval){
                    char[][] newBoard = deepClone(board);
                    propogate(newBoard, i, j, '1');
                    newBoard[i][j] = '1';
                    newBoard[i][j-1] = '0';
                    queue.add(newBoard);
                }
            }
        }
        System.out.println("0");
        
    }

    public static void propogate(char[][] board, int i, int j, char target){
        if(target=='.'){return;}
        boolean check = false;
        // System.out.println(target);
        // System.out.println();
        // printBoard(board);
        // try {
        //     Thread.sleep(500);
        // } catch (InterruptedException e) {
        //     e.printStackTrace();
        // }
        if(i<board.length-1 && board[i+1][j]==target){
            i++;
            if(checkAround(board, i, j)){
                // System.out.println("Before: " +board[i][j]);
                changeTarget(board, i, j);
                // System.out.println("After: " + board[i][j]);
            }
            else{
                board[i][j] = '.';
            }
            
        }
        else if(j < board[0].length-1 && board[i][j+1]==target){
            j++;
            if(checkAround(board, i, j)){
                // System.out.println("Before: " +board[i][j]);
                changeTarget(board, i, j);
                // System.out.println("After: " +board[i][j]);
            }
            else{
                board[i][j] = '.';
            }
        }
        else if(j > 0 && board[i][j-1]==target){
            j--;
            if(checkAround(board, i, j)){
                // System.out.println("Before: " +board[i][j]);
                changeTarget(board, i, j);
                // System.out.println("After: " +board[i][j]);
            }
            else{
                board[i][j] = '.';
            }
        }
        else if(i > 0 && board[i-1][j]==target){
            i--;
            if(checkAround(board, i, j)){
                // System.out.println("Before: " +board[i][j]);
                changeTarget(board, i, j);
                // System.out.println("After: " +board[i][j]);
            }
            else{
                board[i][j] = '.';
            }
        }
        else{
            System.out.println("That's interesting");
        }
        target = board[i][j];
        propogate(board, i, j, target);
    }

    public static boolean checkAround(char[][] board, int i, int j){
        boolean check = false;
        // System.out.println(i);
        char current = returnNext(board[i][j]);
        // System.out.println("Oh I'm getting here: "+ current);
        // System.out.println("i: " + i + " | j: "+ j);
        // printBoard(board);
        if(i<board.length-1){
            if(board[i+1][j]==current){
                check = true;
            }
        }
        if(j < board[0].length-1){
            if(board[i][j+1]==current){
                check = true;
            }
        }
        if(j > 0){
            if(board[i][j-1]==current){
                check = true;
            }
        }
        if(i > 0){
            if(board[i-1][j]==current){
                check = true;
            }
        }
        // System.out.println(check);
        return check;
    }

    public static char returnNext(char input){
        switch(input){
            case '0':
                return '1';
                
            case '1':
                return '2';
                
            case '2':
                return '3';
                
            case '3':
                return '4';
                
            case '4':
                return '5';
                
            case '5':
                return '6';
                
            case '6':
                return '7';
                
            case '7':
                return '8';
                
            case '8':
                return '9';
                
            case '9':
                return 'a';
                
            case 'a':
                return 'b';
                
            case 'b':
                return 'c';
                
            case 'c':
                return 'd';
                
            case 'd':
                return 'e';
                
            case 'e':
                return 'f';
                
            case 'f':
                return '.';
                
            default:
                return '.';
        }    
    }

    public static void changeTarget(char[][] board, int i, int j){
        switch(board[i][j]){
            case '0':
                board[i][j] = '1';
                break;
            case '1':
                board[i][j] = '2';
                break;
            case '2':
                board[i][j] = '3';
                break;
            case '3':
                board[i][j] = '4';
                break;
            case '4':
                board[i][j] = '5';
                break;
            case '5':
                board[i][j] = '6';
                break;
            case '6':
                board[i][j] = '7';
                break;
            case '7':
                board[i][j] = '8';
                break;
            case '8':
                board[i][j] = '9';
                break;
            case '9':
                board[i][j] = 'a';
                break;
            case 'a':
                board[i][j] = 'b';
                break;
            case 'b':
                board[i][j] = 'c';
                break;
            case 'c':
                board[i][j] = 'd';
                break;
            case 'd':
                board[i][j] = 'e';
                break;
            case 'e':
                board[i][j] = 'f';
                break;
            case 'f':
                board[i][j] = '.';
                break;

        }
    }

    public static void printBoard(char[][] board){
        for(int i =0; i<board.length; i++){
            System.out.println(String.valueOf(board[i]));
        }
    }

    public static char[][] deepClone(char[][] board){
        char[][] temp = board.clone();
        for(int i = 0; i<board.length; i++){
            temp[i] = temp[i].clone();
        }
        return temp;
    }
}
