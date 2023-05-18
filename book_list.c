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
#include <stdio.h>
#include "book.c"

const int MAX_BOOKS = 5000; /* MAX NUMBER OF BOOK IN LIST */


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
        char str[100]; 
        sprintf(str, "--------- %d ---------\n", i);
        strcat(result, str);
        strcat(result, book_to_string(book_listV.books[i -1])); 
    }

    #ifdef DEBUG4
        printf("%s", result); 
    #endif

    return result; 
}

/*******************************************************
 * book_list_template_by_file -- tạo ra 1 giá trị danh 
 *      sách sách dựa theo file nhập vào 
 * 
*/
book_list book_list_tempate_by_file(const char* file_name) {
    book_list result; 

    result.num_book = num_line_file(file_name) - 1; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book));

    for (int i = 1; i <= result.num_book; ++i) {
        result.books[i -1] = book_template_by_file_line(file_name, i + 1); 
    }

    

    #ifdef DEBUG3
        printf("book list from file %s is \n%s", file_name, book_list_to_string(result)); 
    #endif



    return result; 
}

/*********************************************
 * add_book_to_list_by_file -- thêm giá trị sách vào giá trị 
 *      danh sách sách bawngf file
 * 
*/
book_list add_book_to_list_by_file(book_list old_book_listV, const char* file_name) {
    book_list result; 

    result = old_book_listV; 

    int num_books_to_add = num_line_file(file_name) -1; 
    
    for (int i = 1; i <= num_books_to_add; ++i) {
        result.books[i + result.num_book -1] = book_template_by_file_line(file_name, i + 1);  
    }

    result.num_book = result.num_book + num_books_to_add; 


    #ifdef DEBUG3 
        if (sizeof(result.books) / sizeof(book) == sizeof(old_book_listV.books) / sizeof(book)) {
            printf("allocating the same\n");
        } else {
            printf("allocating not the same\n"); 
        }
    #endif

    #ifdef DEBUG3
        printf("%s", book_list_to_string(result)); 
    #endif

    return result;
}


/**************************************
 * delete_book_from_list -- xóa giá trị sách từ giá trị 
 *      danh sách sách 
 * 
*/
book_list delete_book_from_list(book_list old_book_listV, int order_of_book) {
    book_list result; 

    result = old_book_listV; 
    if (order_of_book < result.num_book) {
        for (int i = order_of_book; i <= result.num_book - 1; ++i) {
            result.books[i -1] = result.books[i + 1 -1];
        }
        result.num_book = result.num_book - 1; 
    } else if (order_of_book == result.num_book) {
        result.num_book = result.num_book - 1; 
    }

    #ifdef DEBUG3
        printf("%s", book_list_to_string(result)); 
    #endif

    return result; 
} 


/*****************************************
 * search_book_by_author -- tạo ra danh sách sách 
 *      có các sách có giá trị ban đầu giống với kí tự nhập vào
 * 
*/
book_list search_book_by_author(book_list book_listV, const char* author_name) {
    book_list result; 

    result.num_book = 0; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book));

    for (int i = 1; i <= book_listV.num_book; ++i) {
        if (memcmp(book_listV.books[i -1].author, author_name, 4) == 0) {
            result.num_book = result.num_book + 1; 
            result.books[result.num_book -1] = book_listV.books[i -1];
        }
    }

    #ifdef DEBUG3
        printf("Book list with search for author \"%s\"\n%s", author_name, book_list_to_string(result)); 
    #endif

    return result; 
}

/*****************************************
 * search_book_by_isbn -- tạo ra danh sách sách 
 *      có các sách có giá trị ban đầu giống với kí tự nhập vào
 * 
*/
book_list search_book_by_isbn(book_list book_listV, const char* isbnV) {
    book_list result; 

    result.num_book = 0; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book));

    for (int i = 1; i <= book_listV.num_book; ++i) {
        if (memcmp(book_listV.books[i -1].isbn, isbnV, 4) == 0) {
            result.num_book = result.num_book + 1; 
            result.books[result.num_book -1] = book_listV.books[i -1];
        }
    }

    #ifdef DEBUG3
        printf("Book list with search for isbn \"%s\"\n%s", isbnV, book_list_to_string(result)); 
    #endif

    return result; 
}

/*****************************************
 * search_book_by_name -- tạo ra danh sách sách 
 *      có các sách có giá trị ban đầu giống với kí tự nhập vào
 * 
*/
book_list search_book_by_name(book_list book_listV, const char* nameV) {
    book_list result; 

    result.num_book = 0; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book));

    for (int i = 1; i <= book_listV.num_book; ++i) {
        if (memcmp(book_listV.books[i -1].name, nameV, 4) == 0) {
            result.num_book = result.num_book + 1; 
            result.books[result.num_book -1] = book_listV.books[i -1];
        }
    }

    #ifdef DEBUG3
        printf("Book list with search for name \"%s\"\n%s", nameV, book_list_to_string(result)); 
    #endif

    return result; 
}

/*****************************************
 * search_book_by_publisher -- tạo ra danh sách sách 
 *      có các sách có giá trị ban đầu giống với kí tự nhập vào
 * 
*/
book_list search_book_by_publisher(book_list book_listV, const char* publisherV) {
    book_list result; 

    result.num_book = 0; 
    result.books = (book*)malloc(MAX_BOOKS * sizeof(book));

    for (int i = 1; i <= book_listV.num_book; ++i) {
        if (memcmp(book_listV.books[i -1].publisher, publisherV, 4) == 0) {
            result.num_book = result.num_book + 1; 
            result.books[result.num_book -1] = book_listV.books[i -1];
        }
    }

    #ifdef DEBUG3
        printf("Book list with search for publisher \"%s\"\n%s", publisherV, book_list_to_string(result)); 
    #endif

    return result; 
}

#ifdef DEBUG3

int main(void) {
    const char FILE_INPUT_NAME[] = "book_list_file.csv"; 
    const char FILE_ADD_NAME[] = "add_book_file.csv"; 
    book_list myShelf; 

    myShelf = book_list_tempate_by_file(FILE_INPUT_NAME); 
    
    // myShelf = delete_book_from_list(myShelf, 3); 

    search_book_by_publisher(myShelf, "Kim ");


}

#endif 
