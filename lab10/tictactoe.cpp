/*TIC TAC TOE LAB
 * Raheema Kadwa
 *
 * Tic Tac Toe simulation through 2D Arrays
 */

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

main(){
	void populate (char [][3]), userInput (char, int[]), updateBoard (char, const int[], char [][3]);
	bool legalMove (const int[], const char [][3]);
	void displayBoard (const char [][3]);
	int winner (const char [][3]);
	
	char board [3][3], player='X';
	int currentMove[2], status, filled=0;
	bool validMove = false, cont=true;
	string line= "~~~~~~~~~~\n";

	cout <<endl<<line<<"TIC TAC TOE"<<endl<<line<<endl;
	populate(board);
	displayBoard(board);

	while (cont){
		while (!validMove){
			userInput(player,currentMove);	
			validMove = legalMove (currentMove, board);
		}
		updateBoard (player, currentMove, board);
		displayBoard(board);
		filled++;

		status = winner(board);
		if (status<2){
			cont = false;
			cout <<player <<" wins!\n"<<line<<endl;
		}	
		else if(filled==9){
			cont=false; 
			cout <<"Stalemate!\n"<<line<<endl;
		}

		//update player
		if (player=='X')
			player='O';
		else
			player='X';
		validMove=false;
	}
	cout <<"Thank you for playing..."<<endl<<line<<endl;	
}
	
//intial board/array: every character is a space (empty)
void populate(char board[][3]){
	for (int x=0; x<3; x++)
		for (int y=0; y<3; y++)
			board[x][y]=' ';
}

//prints array by going through the board
void  displayBoard (const char board [][3]){
	string line = "+--+--+--+\n";
	cout <<line;
	for (int x=0; x<3; x++){
		for (int y=0; y<3; y++)
			cout << '|' << board[x][y] << " ";
		cout << "|\n" << line;
	}	
	cout <<endl;
}

//asks user for the input and stores it in an array of size 2:{x,y}
void userInput(char player, int move[]){
	char comma; 

	cout << "Player "<< player << ", Enter a move in the form x,y: ";
	cin >> move[0]>>comma >>move[1];
	
	//user will enter indexes with an increment of 1
	move[0] -=1;
	move [1] -=1;

	//cout << move[0] << ", " << move[1];
}

//checks to see if the coordinates entered are valid
//they have to be within the range
//user cannot enter coordinates of a spot on the board that is already filled
bool legalMove (const int move [], const char  board[][3]){
	bool valid = true;
	
	//if not within range
	if (move[0]>2 || move[1]>2 || move[0]<0 || move[1]<0){
		valid = false;
		cout << "Invalid coordinates...\n\n";
	}
	//if those coodinates are not empty
	else{
		char space = board [move[0]][move[1]];
		if (space != ' '){
			valid = false;
			cout << "That spot is occupied...\n\n";
		}
	}
	return valid;
}

//add the new  character in the board array
void updateBoard (char move, const int moveCoord[], char  board[][3]){
	board[moveCoord[0]][moveCoord[1]]=move;
}

//checks to see if there is a winner
//will check diagonals, rows, then columns
//will print 0 if O wins
//will print 1 if x wins
//will print 2 is there is no winner
int winner (const char board [][3]){
	int checkDiagonals (const char[][3]), checkRows (const char [][3]), checkColumns (const char [][3]);
	int status;
	//0 :O
	//1: X
	//2: no winner
	
	status= checkDiagonals (board);
	//if diagonal dont have a winner, then check rows, then check columns
	if (status==2){
		status= checkRows (board);
		if (status==2)
			status=checkColumns(board);
	}
	return status;
}

//winner helper functions: 
int checkDiagonals(const char board[][3]){
	int check (const char[]);
	int status;

	char diagonals[3];
	
	//populate diagonals with coordinates of left to right diagonal
	diagonals[0]=board[0][0];
	diagonals[1]=board[1][1];
	diagonals[2]=board[2][2];

	//cout <<"["<<diagonals[0]<<" | "<<diagonals[1] << " | " << diagonals[2]<<"]"<<endl;

	//check to see if they are all equal
	status=check (diagonals);	
	
	//if they are not equal then update coordinates from right to left diagonal
	if (status==2){
		diagonals[0]=board[2][0];
		diagonals[2]=board[0][2];
		status=check(diagonals);
	}		
	return status;
}


//check to see if there are equalities within the rows
int checkRows (const char board[][3]){
	int check (const char[]);
	int status;	
	char rows[3];

	for (int x=0; x<3; x++){
		for (int y=0; y<3; y++)
			rows[y]=board[x][y];
			//cout <<"board: " << board[x][y] <<"rows: " << rows[x] << endl;	
		//cout << "row array:" <<  rows[0]<<rows[1]<<rows[2]<<endl;
		status=check(rows);
		if (status<2)
			break;
	}	
	return status;
}

//check to see if there are equalities within the columns
int checkColumns (const char board[][3]){
	int check (const char[]);
	int status;
	char columns[3];
	
	for (int x=0; x<3; x++){
		for (int y=0; y<3; y++)
			columns[y]=board[y][x];
			//cout <<"columns: " <<columns[y];
		//cout <<"COLUMNS: " <<columns[0]<<columns[1]<<columns[2];
		status=check (columns);
		if (status<2)
			break;
	}
	return status;
}

//takes array of 3 and checks if they are all equal
int check (const char current[]){
	int status=2;

	if (current[0]==current[1]&&current[1]==current[2]){
		//cout << "CURRENT: " <<current[0]<<current[1]<<current[2]<<endl;
		if (current[0]==' ')
			status=2;
		else if (current[0]=='O')
			status=0;
		else
			status=1;
	}
	//cout <<"status: " <<status<<endl;
	return status;
}


