/************************************************
 * menu -- tạo ra các hàm thể hiện menu lựa chọn 
 *      cho người dùng tương tác 
 * 
 * PURPOSE: 
 *      1. Tạo ra hàm tạo menu cho chương trình PBL chính 
 *      2. tạo ra hàm menu chính 
 *      3. tạo ra hàm menu thông tin sách 
 *      4. tạo ra hàm menu quản lí trạng thái 
 *      5. tạo ra hàm menu tiện ích 
 * 
 * STATUS: code hoàn thành mục đích 
 * 
 * SOURCE: PBL lập trình 
 * 
*/
// #include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include "book_list.c"

/************************
 * print_main_menu -- in ra màn hình 
 *      menu chính với 4 sự lựa chọn 
 *      1. thông tin sách 
 *      2. quản lí 
 *      3. tiện ích 
 *      4. thoát 
 * 
*/
void print_main_menu(void) {
    system("cls"); 
    printf("----------------MAIN MENU----------------\n"); 
    printf("1. Book information sections\n"); 
    printf("2. Manage the book list\n"); 
    printf("3. Extensive function\n");
    printf("4. Exit\n");  
    printf("-------------------\nYour choice: "); 
}

/***************************************
 * print_infor_menu -- in ra thông tin sách 
 *      có trong danh sách sách và thoát ra 
 *      khi enter 1
*/
void print_infor_menu(book_list book_listV) {
    system("cls"); 
    printf("----------------INFORMATION MENU----------------\n");
    printf("%s", book_list_to_string(book_listV)); 
    printf("Back to MAIN MENU enter 1: "); 
}

/****************************************
 * print_manage_menu -- in ra màn hình menu quản lí 
 *      với 4 sự lựa chọn 
 *      1. cập nhập thông tin sách 
 *      2. thêm sách 
 *      3. xóa sách 
 *      4. thoát 
*/
void print_manage_menu(void) {
    system("cls"); 
    printf("---------------MANAGEMENT MENU------------------\n"); 
    printf("1. Update the book list\n"); 
    printf("2. Add the book by file\n"); 
    printf("3. Delete book information\n"); 
    printf("4. Back to MAIN MENU\n"); 
    printf("-----------------------------\nYour choice: "); 
}

/************************************
 * print_extension_menu -- in ra màn hình tiện ích 
 *      với 3 sự lưa chọn 
 *      1. tìm kiếm 
 *      2. lọc 
 *      3. thoát
*/
void print_extention_menu(void) {
    system("cls"); 
    printf("---------------EXTENSION MENU-------------------\n"); 
    printf("1. Search book\n");
    printf("2. Filter book list with publisher\n"); 
    printf("3. Back to the MAIN MENU\n"); 
    printf("-------------------------\nYour choice: "); 
}

/****************************************
 * print_update_menu -- in ra màn hình menu cập nhập sách 
 *      với phần hướng dẫn
 *      1. câp nhập 
 *      2. thoát 
*/
void print_update_menu(void) {
    system("cls"); 
    printf("-------------UPDATE MENU---------------\n");
    printf("First you need to download a file book_list_file.csv into PBL folder. Then choose update below\n");
    printf("1. Update\n");
    printf("2. Back to MANAGEMENT MENU\n");
    printf("--------------------------\nYour choice: ");  

}

/********************************************
 * print_add_menu -- in ra màn hình menu thêm sách 
 *      với phần hướng dẫn 
 *      1. thêm 
 *      2. thoát 
*/
void print_add_menu(void) {
    system("cls"); 
    printf("------------ADD MENU------------------\n");
    printf("First you need to download a file add_books_file.csv into PBL folder. Then choose add below\n");
    printf("1. Add\n");
    printf("2. Back to MANAGEMENT MENU\n");
    printf("--------------------------\nYour choice: ");
}

/***************************************************
 * print_delete_menu -- in ra màn hình thông tin danh sách sách 
 *      với 2 sự lựa chọn 
 *      1. chọn sách muốn xóa theo số hiệu của sách 
 *      2. thoát khi enter 0
*/
void print_delete_menu(book_list book_listV) {
    system("cls"); 
    printf("------------DELETE MENU-----------\n"); 
    printf("%s", book_list_to_string(book_listV));
    printf("1. Choose the book you want to delete by the number above it\n");
    printf("2. Enter 0 to back to MANAGEMENT MENU\n"); 
    printf("---------------------------------------\nYour choice: "); 
}

/****************************************
 * print_search_menu -- in ra màn hình menu tìm kiếm 
 *      với 4 sự lựa chọn 
 *      1. tìm kiếm theo tác giả
 *      2. tìm kiếm theo mã sách 
 *      3. tìm kiếm theo tên sách 
 *      4. thoát 
 * 
*/
void print_search_menu(void) {
    system("cls"); 
    printf("-----------SEARCH MENU----------\n");
    printf("1. Search by author\n");
    printf("2. Search by isbn\n");
    printf("3. Search by book name\n"); 
    printf("4. Back to EXTENSION MENU\n");
    printf("--------------------------\nYour choice: ");

}

void print_keyword_menu(void) {
    system("cls");
    printf("Enter keyword at least 4 characters: ");
}


#ifdef DEBUG2

int main(void) {
    setup_debug_file(); 

    const char FILE_UPDATE_NAME[] = "book_list_file.csv"; 
    const char FILE_ADD_NAME[] = "add_book_file.csv";

    book_list myShelf; 
    

    int choice; 
    while(1) 
    {
        print_main_menu(); 
        scanf("%d", &choice);
        if (choice == 1) {
            while(1)
            {
                print_infor_menu(myShelf);
                scanf("%d", &choice); 
                if (choice == 1) {
                    break;
                }
            }
        } else if (choice == 4) {
            break;
        } else if (choice == 2) {
            while(1) {
                print_manage_menu(); 
                scanf("%d", &choice); 
                if (choice == 1) {
                    while(1) 
                    {
                        print_update_menu(); 
                        scanf("%d", &choice); 
                        if (choice == 1) {
                            myShelf = book_list_tempate_by_file(FILE_UPDATE_NAME);
                        } else if (choice == 2) {
                            break; 
                        }
                    }
                    
                } else if (choice == 4) {
                    break; 
                } else if (choice == 2) {
                    while(1)
                    {
                        print_add_menu(); 
                        scanf("%d", &choice);
                        if (choice == 2) {
                            break;
                        } else if (choice == 1) {
                            myShelf = add_book_to_list_by_file(myShelf, FILE_ADD_NAME); 
                        }
                    }
                } else if (choice == 3) {
                    while(1)
                    {
                        print_delete_menu(myShelf); 
                        scanf("%d", &choice); 
                        if (choice > 0) {
                            myShelf = delete_book_from_list(myShelf, choice); 
                        } else if (choice == 0) {
                            break; 
                        }
                    }
                }
            }
        } else if (choice == 3) {
            while(1)
            {
                print_extention_menu(); 
                scanf("%d", &choice); 
                if (choice == 1) {
                    while(1) 
                    {
                        print_search_menu(); 
                        scanf("%d", &choice);
                        if (choice == 4) {
                            break; 
                        } else if (choice == 1) {
                            while(1)
                            {
                                print_keyword_menu();
                                char keyword[50];
                                scanf("%s", keyword);
                                printf("%s", book_list_to_string(search_book_by_author(myShelf, keyword)));   
                                printf("Enter 1 to back to SEARCH MENU: ");
                                scanf("%d", &choice);
                                if (choice == 1) {
                                    break; 
                                }
                                 
                            }
                        } else if (choice == 2) {
                            while(1)
                            {
                                print_keyword_menu();
                                char keyword[50];
                                scanf("%s", keyword);
                                printf("%s", book_list_to_string(search_book_by_isbn(myShelf, keyword)));   
                                printf("Enter 1 to back to SEARCH MENU: ");
                                scanf("%d", &choice);
                                if (choice == 1) {
                                    break; 
                                }
                                 
                            }
                        } else if (choice == 3) {
                            while(1)
                            {
                                print_keyword_menu();
                                char keyword[50];
                                scanf("%s", keyword);
                                printf("%s", book_list_to_string(search_book_by_name(myShelf, keyword)));   
                                printf("Enter 1 to back to SEARCH MENU: ");
                                scanf("%d", &choice);
                                if (choice == 1) {
                                    break; 
                                }
                                 
                            }
                        }

                    }
                } else if (choice == 2) {
                    while(1)
                    {
                        print_keyword_menu();
                        char keyword[50];
                        scanf("%s", keyword);
                        printf("%s", book_list_to_string(search_book_by_publisher(myShelf, keyword)));   
                        printf("Enter 1 to back to SEARCH MENU: ");
                        scanf("%d", &choice);
                        if (choice == 1) {
                            break; 
                        }
                            
                    }            
                } else if (choice == 3) {
                    break; 
                }
            }
        }
    }

}   

#endif /* DEBUG */