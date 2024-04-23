// Library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

void Continue(void)
{
    cout << "\n\nДля продолжения нажмите любую клавишу...\n";
    _getch();
} // функция ожидания

//Создать структуру книги
typedef struct  // структура библиотеки
{
    string name; //название книги
    string author; // автор
    string publishing_house; //издательство
    string year; //год выпуска
    string genre; //жанр
    int number_of_pages; //количество страниц в книге
} Book;

void constructor(Book* books, const int Size)
{
    for (int i = 0; i < Size; i++)
    {
        books[i].name = "\0";
        books[i].author = "\0";        
        books[i].publishing_house = "\0";
        books[i].year = "\0";
        books[i].genre = "\0";
        books[i].number_of_pages = 0;
    }

} //функция-конструктор

void showBooks(Book* books, int index)
{
    for (int i = 0; i < index; i++)
    {
        cout << "\nКнига №" << i + 1 << "\n";
        cout << "Автор " << books[i].author << "\n";
        cout << "Название: " << books[i].name << "\n";
        cout << "Издательство: " << books[i].publishing_house << "\n";
        cout << "Год выпуска: " << books[i].year << "\n";
        cout << "Жанр: " << books[i].genre << "\n";
        cout << "Количество страниц: " << books[i].number_of_pages << "\n";
        cout << "_________________________________________________\n\n";
    }
}//функция вывода книг на экран

void editBook(Book* books, int i)
{
    int Button = 0;

    cout << "\nКнига №" << i << "\n";
    cout << "Автор " << books[i].author << "\n";
    cout << "Название: " << books[i].name << "\n";
    cout << "Издательство: " << books[i].publishing_house << "\n";
    cout << "Год выпуска: " << books[i].year << "\n";
    cout << "Жанр: " << books[i].genre << "\n";
    cout << "Количество страниц: " << books[i].number_of_pages << "\n";
    cout << "_________________________________________________\n\n";

    cout << "1. Редактировать автора книги\n";
    cout << "2. Редактировать название книги\n";
    cout << "3. Редактировать издательство\n";
    cout << "4. Редактировать год выпуска\n";
    cout << "5. Редактировать жанр\n";
    cout << "6. Редактировать количество страниц\n";
    cout << "Esp. Выход\n";

    Button = _getch(); // нажатие на экран
    cin.ignore();

    if (Button == 27)
        return;

    else if (Button == '1') { //редактировать автора

        cout << "Редактирование автора книги\n\n";
        cout << "Введите автора книги: ";        
        getline(cin, books[i].author);
    }

    else if (Button == '2') { //редактировать название

        cout << "Редактирование название книги\n\n";
        cout << "Введите название книги: ";
        getline(cin, books[i].name);
    }

    else if (Button == '3') { //редактировать издательство

        cout << "Редактирование издательство\n\n";
        cout << "Введите издательство: ";
        getline(cin, books[i].publishing_house);
    }

    else if (Button == '4') { //редактировать год выпуска

        cout << "Редактирование год выпуска\n\n";
        cout << "Введите год выпуска: ";
        cin >> books[i].year;
    }

    else if (Button == '5') { //редактировать жанр

        cout << "Редактирование жанра\n\n";
        cout << "Введите жанр: ";
        getline(cin, books[i].genre);
    }

    else if (Button == '6') { //редактировать количество страниц

        cout << "Редактирование количества страниц\n\n";
        cout << "Введите количество страниц: ";
        cin >> books[i].number_of_pages;
    }

}

void getBooks(Book* books, int& index)
{
    ifstream Read("books.txt");
    int i = 0;
    while (!Read.eof())
    {
        Read >> books[i].name >> books[i].author >> books[i].publishing_house >> books[i].year >> books[i].genre >> books[i].number_of_pages;
        index++;
        i++;
    }
    Read.close();
}



void searchAuthor(Book* books, int& index, string author)
{
    int temp = 0;
    for (int i = 0; i < index; i++)
    {
        if (books[i].author == author)
        {
            cout << "\nКнига №" << i + 1 << ":\n";
            cout << "Автор " << books[i].author << ":\n";
            cout << "Название: " << books[i].name << ":\n";
            temp++;
        }        
    }
    if (temp == 0) cout << "Книги автора " << author << " не найдены.";
} //функция поиска книги по автору

void searchName(Book* books, int& index, string name)
{
    int temp = 0;
    for (int i = 0; i < index; i++)
    {
        if (books[i].name == name)
        {
            cout << "\nКнига №" << i + 1 << ":\n";
            cout << "Автор " << books[i].author << ":\n";
            cout << "Название: " << books[i].name << ":\n";
            temp++;
        }        
    }
    if (temp == 0) cout << "Книги с названием \" " << name << " \" не найдены.";
} //функция поиска книги по названию

void sortName(Book* books, int& index)
{
    
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (books[j].name > books[j + 1].name)
            {
                swap(books[j].author, books[j + 1].author);
                swap(books[j].name, books[j + 1].name);
                swap(books[j].publishing_house, books[j + 1].publishing_house);
                swap(books[j].year, books[j + 1].year);
                swap(books[j].genre, books[j + 1].genre);
                swap(books[j].number_of_pages, books[j + 1].number_of_pages);
            }
        }
    }
}//функция сортировки по имени

void sortAuthor(Book* books, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (books[j].author > books[j + 1].author)
            {
                swap(books[j].author, books[j + 1].author);
                swap(books[j].name, books[j + 1].name);
                swap(books[j].publishing_house, books[j + 1].publishing_house);
                swap(books[j].year, books[j + 1].year);
                swap(books[j].genre, books[j + 1].genre);
                swap(books[j].number_of_pages, books[j + 1].number_of_pages);
            }
        }
    }
}

void sortPublish(Book* books, int& index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - 1; j++)
        {
            if (books[j].publishing_house > books[j + 1].publishing_house)
            {
                swap(books[j].author, books[j + 1].author);
                swap(books[j].name, books[j + 1].name);
                swap(books[j].publishing_house, books[j + 1].publishing_house);
                swap(books[j].year, books[j + 1].year);
                swap(books[j].genre, books[j + 1].genre);
                swap(books[j].number_of_pages, books[j + 1].number_of_pages);
            }
        }
    }
}


//Создать массив из 10 книг +
// Реализовать наполнение "библиотеки". ++
// реализовать функции
// - редактировать книгу -
// - печать всех книг +
// - поиск по автору +
// - поиск книги по названию +
// - сортировка массива по названию книг +
// - сортировка массива по автору +
// - сортировка массива по издательству +
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
   
    int Button = 0;
    const int Size = 10; // количество книг
    int index = 0; //индекс последнего элемента структуры
    //Book Books[Size]; // массив объектов структуры
    string strName; //переманная (название книги) для передачи в функции
    string strAuthor; //переменная (автор) для передачи в функции

    Book* Books = new Book[Size]; // объявление динамического массива
    constructor(Books, Size);

    while (true)
    {
        system ("cls"); // очистка экрана
        cout << "1. Редактировать книгу\n";
        cout << "2. Печать всех книг\n";
        cout << "3. Поиск книги по автору\n";
        cout << "4. Поиск книги по названию\n";
        cout << "5. Сортировка массива по названию книг\n";
        cout << "6. Сортировка массива по автору\n";
        cout << "7. Сортировка массива по издательству\n";
        cout << "8. Считать из файла выходные параметры\n";
        cout << "Esc. Выход\n";

        Button = _getch(); // нажатие на экран

        if (Button == 27)
            break;

        else if (Button == 49)  { //редактирование книги

            system ("cls");
            cout << "Редактирование книги\n\n";
            cout << "Какую книгу будем редактировать? (введите номер книги): ";
            int number_of_book = 0;
            cin >> number_of_book;
            editBook(Books, number_of_book);

           Continue ();
        }

        else if (Button == 50)  { // печать всех книг на экран

            system ("cls");
            cout << "Печать всех книг на экран:\n\n";
            showBooks (Books, index);
            Continue ();
        }

        else if (Button == 56) { // чтение из файла

            system ("cls");
            cout << "\nДанные считаны из файла.\n";

            getBooks(Books, index);

            Continue ();
        }

        else if (Button == 51)  { //Поиск книги по автору

            system ("cls");
            cout << "Поиск книги по автору\n\n";
            cout << "Введите автора: ";
            getline(cin, strAuthor);
            searchAuthor (Books, index, strAuthor);

            Continue ();
        }

        else if (Button == 52)  { //Поиск книги по названию

            system ("cls");
            cout << "Поиск книги по названию\n\n";
            cout << "Введите название книги: ";
            getline(cin, strName);
            searchName (Books, index, strName);

            Continue ();
        }

        else if (Button == 53) { //Сортировка по названию книги

            system("cls");
            sortName(Books, index);

            Continue();
        }

        else if (Button == 54) { //Сортировка по автору

            system("cls");
            cout << "Сортировка библиотеки по автору\n\n";
            sortAuthor(Books, index);

            Continue();
        }

        else if (Button == 55) { //Сортировка по издательству

            system("cls");
            cout << "Сортировка библиотеки по издательству\n\n";
            sortPublish(Books, index);

            Continue();
        }

    }
    delete [] Books; // освобождение памяти
    cout << "\n";
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
