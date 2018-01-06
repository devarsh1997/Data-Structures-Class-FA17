// Your code here!
#include "exam.h"

namespace exam{

Matrix flip_columns(const Matrix &m){
  int row = m.get_num_rows();
  int col = m.get_num_columns();
  Matrix* out = new Matrix(row,col);
  int stop;
  if (col%2 == 1){
    stop = col-1;
    for (int j=0; j<row; j++){
      out->set_coord(j,col-1,m.get_coord(j,col-1));
    }
  }else{
    stop = col;
  }
  for (int i=0; i<stop; i+=2){
    for (int j=0; j<row; j++){
      out->set_coord(j,i,m.get_coord(j,i+1));
      out->set_coord(j,i+1,m.get_coord(j,i));
    }
  }
  return *out;
}

}
