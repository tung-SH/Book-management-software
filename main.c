/***********************************************
 * main -- chương trình PBL chính 
 * 
 * PURPOSE: 
 *      1. tạo chương trình quản lí thư viện 
 * 
 * STATUS: code hoàn thành mục đích 
 * 
 * SOURCE: PBL 
 * 
*/

#include "menu.c"

const char FILE_UPDATE_NAME[] = "book_list_file.csv";
const char FILE_ADD_NAME[] = "add_book_file.csv";

int choice; /* choice of user in program */
char keyword[100]; /* keyword for search books */
book_list library; /* the book list variable */

int main(void) {
    library = book_list_tempate_by_file(FILE_UPDATE_NAME); 

    while(1)
    {
        print_main_menu();
        scanf("%d", &choice); 
        if (choice == 1) {
            while(1)
            {
                print_infor_menu(library);
                scanf("%d", &choice); 
                if (choice == 1) {
                    break; 
                }
            } 

        } else if (choice == 2) {
            while(1) 
            {
                print_manage_menu(); 
                scanf("%d", &choice); 
                if (choice == 1) {
                    while(1)
                    {
                        print_update_menu(); 
                        scanf("%d", &choice); 
                        if (choice == 1) {
                            library = book_list_tempate_by_file(FILE_UPDATE_NAME); 
                        } else if (choice == 2) {
                            break; 
                        }
                    }
                } else if (choice == 2) {
                    while(1)
                    {
                        print_add_menu(); 
                        scanf("%d", &choice); 
                        if (choice == 1) {
                            library = add_book_to_list_by_file(library, FILE_ADD_NAME); 
                        } else if (choice == 2) {
                            break; 
                        }
                    }
                } else if (choice == 3) {
                    while(1)
                    {
                        print_delete_menu(library); 
                        scanf("%d", &choice); 
                        if (choice > 0) {
                            library = delete_book_from_list(library, choice);
                        } else if (choice == 0) {
                            break; 
                        }
                    }
                } else if (choice == 4) {
                    break; 
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
                        if (choice == 1) {
                            while(1)
                            {
                                print_keyword_menu();
                                char keyword[50];
                                scanf("%s", keyword);
                                printf("%s", book_list_to_string(search_book_by_author(library, keyword)));   
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
                                printf("%s", book_list_to_string(search_book_by_isbn(library, keyword)));   
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
                                printf("%s", book_list_to_string(search_book_by_name(library, keyword)));   
                                printf("Enter 1 to back to SEARCH MENU: ");
                                scanf("%d", &choice);
                                if (choice == 1) {
                                    break; 
                                }
                                    
                            } 
                        } else if (choice == 4) {
                            break; 
                        }
                    }
                } else if (choice == 2) {
                    while(1)
                    {
                        print_keyword_menu();
                        char keyword[50];
                        scanf("%s", keyword);
                        printf("%s", book_list_to_string(search_book_by_publisher(library, keyword)));   
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
        } else if (choice == 4) {
            break; 
        } 
    }

}