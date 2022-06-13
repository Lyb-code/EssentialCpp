#include <fstream>
#include <iostream>
using namespace std;

int* alloc_and_init(string file_name)
{
    ifstream infile(file_name.c_str());
    if (!infile) return 0;//打开失败

    int elem_cnt;
    infile >> elem_cnt;
    if (!infile) return 0;//读取失败，例如将文字读取为数字
    int* pi;
    try {
        pi=allocate_array(elem_cnt); //(1)
        int elem; int index=0;
        while(infile >>elem && index < elem_cnt)
            pi[ index++] = elem;
        sort_array(pi,elem_cnt);// (2) 
        register_data( pi);// (3)
    } 
    catch (const noMem &memFail) {
        cerr<<"alloc and init(); allocate_array failure!\n"
            << memFail.what()<< endl;
        return 0;
    } 
    catch (int &sortFail) {
        cerr << "alloc_and_init(): sort_array failure!\n"
            <<"thrown integer value:"<< sortFail << endl;
        return 0;
    }
    catch( string &registerFail ) {
        cerr <<"alloc_and init():register data failure!\n"
            <<"thrown string value:" << registerFail << endl;
        return 0;
    }
    return pi;// 如果没有任何异常被抛出，就会执行到这里

}
