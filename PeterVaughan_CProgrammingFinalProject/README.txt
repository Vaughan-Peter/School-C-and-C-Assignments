Go to the file where the code is. Change directory in the command line by using the following command:
cd [file name]

Then use the following command:
make

There should be no issues when it compiles. Then use the following command:
./book_management_system 


Then follow the prompts to add books with its needed info, delete books by info, search by info and list all books. When you are done, you may exit the program by using the last option.

Add books with its needed info such as book title (up to 255 characters because 1 is null), author (up to 99 characters because 1 is null), isbn number (up to 12 characters because 1 character is null). This will be stored in books.dat file.

Delete books by info will search for the book. Then it will copy all the other info over to a new file without the dleted book. Then renames new file to the old files name.

Search by info then displays book info unless there is no book by that exact info.

List all books. No input needed beyond selecting that option. It6 will ist all book info until it hits the end of the file.