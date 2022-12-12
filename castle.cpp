#include<iostream>
#include"piece.h"
#include"castle.h"

using namespace std;

//constructor
Castle::Castle(string c) : Piece(c){
  piece_type = "Castle";
}

//destructor
Castle::~Castle(){

}

/**
 * Function to get king flag
 * return false since its not piece of King.
 **/
bool Castle::get_flag_king(){
  return false;
}


/**
 *Function to see whether it is a valid move for piece Castle from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
 **/

bool Castle:: valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb){
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();
  //source is empty
  if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent(src_row,src_col,des_row,des_col))  return false;
  
  //move toward rank
  if( cb -> is_same_row(src_row,des_row) && cb -> is_row_clear(src_row,src_col,des_row, des_col)) flag = true;
  //move towards file
  if( cb -> is_same_col(src_col,des_col) && cb -> is_col_clear(src_row,src_col, des_row,des_col))  flag = true;

if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
//dont let itself in check
   if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
   }
  return flag;
  
    }

