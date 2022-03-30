#include "Notebook.hpp"
#include <iostream>

using namespace std;
namespace ariel
{
             void Notebook::write(int page, int row, int col, ariel::Direction e, const std::string &stringToWrite)
             {
                 int len = stringToWrite.length();

                 if(page<0 || row<0 || col<0 || col>=colLimit || (e==Direction::Horizontal && (col + len >= colLimit)) )
                 {
                     throw invalid_argument ("Negative values");
                 }

                 this->_size[min_page_key] = min(this->_size[min_page_key],page);
                 this->_size[max_page_key] = max(this->_size[max_page_key],page);
                 this->_size[min_row_key] = min(this->_size[min_row_key],row);
                 this->_size[max_row_key] = max(this->_size[max_row_key],row);
                 this->_size[min_row_key] = min(this->_size[min_row_key],col);
                 this->_size[max_row_key] = max(this->_size[max_row_key],col);

 
                
                vector<char> vc = {'~','\n','\r','\t','\v'};
                for (size_t i = 0; i < vc.size(); i++)
                {
                    if (stringToWrite.find(vc.at(i)) != string::npos )
                    {
                         throw invalid_argument ("bad string");
                    }
                    
                }
                
                for (char ch : stringToWrite) {
                     if(!(ch >= ch_1 && ch <= ch_2)){
                         throw invalid_argument("bad char");
                     }
                }
                 for(unsigned long i = 0; i < len; i++) 
                 {
                     if(this->notebook[page][row][col].c == '_') 
                     { 
                         this->notebook[page][row][col].c = stringToWrite[i];
                        if(e==Direction::Horizontal){
                          col++;
                        }else{
                          row++;
                        }
                      }else{
                           throw invalid_argument("bad input");

                      }
                 }

             }

            string Notebook::read(int page, int row, int col, ariel::Direction e, int length)
            {
                 if(page<0 || row<0 || col<0 || length<0 || col>=colLimit || (e==Direction::Horizontal && col + length > colLimit) )
                 {
                     throw invalid_argument ("Negative values");
                 }

                string answer;

                for (size_t i = 0; i < length; i++)
                 {
                     answer+=this->notebook[page][row][col].c;
                      
                      if(e==Direction::Horizontal) 
                      {
                          col++;
                      }else{
                          row++;
                      }
                  }
                  return answer;
            }

            void Notebook::erase(int page, int row, int col, ariel::Direction e, int length)
            {
                 if(page<0 || row<0 || col<0 || col>=colLimit || length<0 || (e==Direction::Horizontal && col + length > colLimit))
                 {
                     throw invalid_argument ("Negative values");
                 }
        
                 for (size_t i = 0; i < length; i++)
                  {
                    this->notebook[page][row][col].c ='~';
                
                      if(e==Direction::Horizontal) 
                      {
                          col++;
                      }
                      else 
                      {
                          row++;
                      }
                  }
            }

            void Notebook::show(int page){

            if(page<0)
                 {
                     throw invalid_argument ("Negative values");
                 }
                //const int name=10;
                
                for (int i = 0; i < colLimit; i++) 
                {
                    for (int j = 0; j < colLimit; j++)
                     {
                       cout<<this->notebook[page][i][j].c;   
                     }

                cout << "\n";
            }
            
             } 

}   
