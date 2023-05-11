/*************************************
 * book_list -- tạo cơ sở giá trị danh sách 
 *      sách cho chương trình PBL
 * 
 * PURPOSE: 
 *      1. tạo cơ sở giá trị cho chương trình PBL
 *      2. tạo cơ sở giá trị danh sách sách và 
 *          2 hàm cơ bản nhất của nó  
 *  
 * STATUS: code hoàn thành mục đích 
 * 
 * SOURCE: môn học PBL 
*/

// #include "setting.h"
#include "book.c"

const int MAX_BOOKS = 500; /* MAX NUMBER OF BOOK IN LIST */

struct book_list {
    int num_book; /* number of books */
    book* books; /* actual list */ 
};

typedef struct book_list book_list; 

/******************************************
 * book_list_template -- tạo giá trị mẫu cho 
 *      danh sách sách nhằm gán vào biến chứa
 *      giá trị danh sách sách 
 * 
 *  
*/
book_list book_list_template(int num_booksV, book* booksV) {
    book_list result; 

    result.num_book = num_booksV; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book)); 

    for (int i = 1; i <= num_booksV; ++i) {
        result.books[i -1] = booksV[i -1]; 
    }

    #ifdef DEBUG4
    {
        printf("-------------------BOOK LIST----------------\n"); 
        for (int i = 1; i <= result.num_book; ++i) {
            printf("%s", book_to_string(result.books[i -1])); 
        }
    }
    #endif

    return result; 
}

/****************************************
 * book_list_to_string -- thể hiện giá trị danh sách 
 *      sách 
 * 
*/
char* book_list_to_string(book_list book_listV) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    strcpy(result, "---------------------BOOK LIST-----------------\n"); 
    for (int i = 1; i <= book_listV.num_book; ++i) {
        strcat(result, book_to_string(book_listV.books[i -1])); 
    }

    #ifdef DEBUG4
        printf("%s", result); 
    #endif

    return result; 
}



#ifdef DEBUG4

int main(void) {
    book_list myShelf; 

    {
        book books[4]; 
        books[1 -1] = book_template("123a4", "Sherlock Holmes pt.1", "Conan Doyle", "Kim Dong", 2019, 3, 304, 5, 1); 
        books[2 -1] = book_template("123b5", "Sherlock Holmes pt.2", "Conan Doyle", "Tri Viet", 2019, 4, 314, 7, 1); 
        books[3 -1] = book_template("4313c9", "Sherlock Holmes pt.3", "Conan Doyle", "Kim Dong", 2017, 3, 302, 5, 1); 
        books[4 -1] = book_template("4313j4", "How to read a book", "Linda Elder", "HCM", 2019, 1, 75, 2, 2); 

        myShelf = book_list_template(4, books); 
    }

    book_list_to_string(myShelf); 
    
}

#endif 