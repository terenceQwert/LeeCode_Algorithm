#pragma once
class BiArraySearchData
{
public:
  int loc_row;
  int loc_col;
  BiArraySearchData(int row, int col) {
    this->loc_row = row;
    this->loc_col = col;
  }
};

BiArraySearchData* testBi_Dimention_Array(const int target);
