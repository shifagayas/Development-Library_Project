#include <stdio.h>


#define max_books 5 // Maximum number of books that can be stored
#define title_len 50 // Maximum length for book titles
#define author_len 50 // Maximum length for author names

char books[max_books][title_len] = {"onebook", "twobook", "the power", "jungle book"};
char authors[max_books][author_len] = {"oneAuthor", "twoauthor", "kamal singh", "rahul singh"};

int available_books = 4;  // Number of available books

void display_default_books()
 {
    printf("Available Books:\n");
    printf("==================================================\n");
    printf("%s\t\t\t %s\n", "Title", "Author");
    printf("==================================================\n");
    for (int i = 0; i < available_books; i++) 
    {
        printf("%s \t\t %s\n", books[i], authors[i]);
    }
    printf("==================================================\n");
}

void search_by_title()
 {
    char search_title[title_len];
    int found = 0;

    printf("\nEnter a keyword to search by title (minimum 3 characters): ");
    fgets(search_title, title_len, stdin);

     for (int i = 0; i < title_len; i++)
     {
        if (search_title[i] == '\n')
         {
            search_title[i] = '\0';
            break;
        }
    }
    
    printf("\nSearch Results:\n");
    printf("==================================================\n");
    printf("%s\t\t %s\n", "Title", "Author");
    printf("==================================================\n");

     for (int i = 0; i < available_books; i++)
     {
        int match = 1;
        for (int j = 0; search_title[j] != '\0'; j++) 
        {
            if (books[i][j] == '\0' || search_title[j] != books[i][j])
             {
                match = 0;
                break;
            }
        }
        if (match)
         {
            printf("%s\t\t %s\n", books[i], authors[i]);
            found = 1;
        }
    }

    if (!found)
     {
        printf("No books found with title '%s'.\n", search_title);
    }
    printf("==================================================\n");
}

void search_by_author()
 {
    char search_author[author_len];
    int found = 0;

    printf("\nEnter a keyword to search by author (minimum 3 characters): ");
    fgets(search_author, author_len, stdin);
	
    for(int i = 0; i < author_len; i++)
   {
    if(search_author[i] == '\n')
	{
	 search_author[i] = '\0';
	 break;
    }
   }

    printf("\nSearch Results:\n");
    printf("==================================================\n");
    printf("%s\t\t %s\n", "Title", "Author");
    printf("==================================================\n");

   for(int i = 0; i <available_books; i++)
   {
     int match = 1;
    for (int j = 0; search_author[j] != '\0'; j++)
	{
	 if (books[i][j] == '\0' || search_author[j] != authors[i][j])
	 {
	   match = 0;
	   break;
	 }
    }
	if (match)
	{
	 printf("%s\t\t%s\n",books[i], authors[i]);
     found = 1;
    }
  }

    if (!found)
     {
        printf("No books found with author '%s'.\n", search_author);
    }
    printf("==================================================\n");
}

void choices()
 {
    printf("\nPlease enter your choice:\n");
    printf("2: Display Available Books\n");
    printf("5: Search Books by Title\n");
    printf("6: Search Books by Author\n");
    printf("0: Exit\n");
}

int main()
 {
    int choice;

    printf("\n\t************** Project 03 - Library Management System **************\n\n");

    while (1)
     {
        choices();
        printf("Please enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }
        getchar();  // Consume newline character left by scanf

        switch (choice)
         {
            case 2:
                display_default_books();
                break;
            case 5:
                search_by_title();
                break;
            case 6:
                search_by_author();
                break;
            case 0:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
