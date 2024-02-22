/*
   Design a Book class with attributes such as title, author, and ISBN. Include methods that allow setting and getting these attributes. In the main function, create an instance of the Book class and demonstrate setting and retrieving its attributes. This task is designed to introduce the principles of OOP, encapsulation, and the use of classes and objects.
*/
#include <iostream>
class Book
{
	private:
		std::string title;
		std::string author;
		int ISBN;
	public:
		Book(std::string title, std::string author, int isbn) : title(title), author(author), ISBN(isbn) {}
		void set_title(std::string book_name)
		{
				title = book_name;
		}
		void set_author(std::string author_name)
		{
				author = author_name;
		}
		void set_ISBN(int num)
		{
				ISBN = num;
		}
		std::string get_title() 
		{
				return title;
		}
		std::string get_author()
		{
				return author;
		}
		int get_ISBN()
		{
				return ISBN;
		}
		
};

int main()
{
		std::string title;
		std::string author;
		int isbn;

		std::cout << "Input title of the book: ";
		std::getline(std::cin, title);

		std::cout << "Input the author's name: ";
		std::getline(std::cin, author);
		
		std::cout << "Input the ISBN: ";
		std::cin >> isbn;
		std::cout << std::endl;

		Book book1(title, author, isbn);

		Book book2("The picture of Dorian Gray", "Oscar, Wilde", 859643);
		
		std::cout << "The title of the first book is: " << book1.get_title() << std::endl; 
		std::cout << "The author of the first book is: " << book1.get_author() << std::endl; 
		std::cout << "The ISBN of the first book is: " << book1.get_ISBN() << std::endl;
		std::cout << std::endl;

		std::cout << "Changin the title of the book, enter a title: ";
		std::cin >> title;
		book1.set_title(title);
		std::cout << "Changing the ISBN of the book: ";
		std::cin >> isbn;
		book1.set_ISBN(isbn);
		std::cout << std::endl;
		
		std::cout << "The title of the first book is: " << book1.get_title() << std::endl; 
		std::cout << "The author of the first book is: " << book1.get_author() << std::endl; 
		std::cout << "The ISBN of the first book is: " << book1.get_ISBN() << std::endl;


}
