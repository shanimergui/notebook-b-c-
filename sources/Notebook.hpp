#pragma once
#include <string>
#include "Direction.hpp"
#include <unordered_map>
#include <vector>

const int colLimit=100;
const int ch_1 = 32;
const int ch_2 = 126;

struct ch{
  char c = '_';
};
namespace ariel
{
    class Notebook
    {
        private:

       // key:1 -> min_page     key:2 -> max_page   key:5 -> min_col
       // key:3 -> min_row     key:4 -> max_row   key:6 -> max_col

        std::unordered_map<int,int> _size;
        std::unordered_map<int,std::unordered_map<int,std::unordered_map<int,ch>>> notebook; 
        //int,int,char

        int min_page_key=1;
        int max_page_key=2;
        int min_row_key=3;
        int max_row_key=4;
        int min_col_key=5;
        int max_col_key=6;


  public:
      Notebook(){
        _size[1]=0;
        _size[2]=UINT16_MAX;
        _size[3]=0;
        _size[4]=UINT16_MAX;
        _size[5]=0;
        _size[6]=colLimit;

      };
            void write(int page, int row, int col, ariel::Direction e,const std::string &stringToWrite);
            std::string read(int page, int row, int col, ariel::Direction e, int length);
            void erase(int page, int row, int col, ariel::Direction e, int length);
            void show(int page);
    };
}