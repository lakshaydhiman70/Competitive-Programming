using System;
using System.Collections.Generic;

namespace LLD_Relationships
{
    // ---------------- Association ----------------
    public class Author
    {
        public string Name { get; set; }

        public Author(string name)
        {
            Name = name;
        }
    }

    public class Book
    {
        public string Title { get; set; }
        public Author WrittenBy { get; set; }  // Association

        public Book(string title, Author author)
        {
            Title = title;
            WrittenBy = author;
        }
    }

    // ---------------- Aggregation ----------------
    public class Library
    {
        public string Name { get; set; }
        public List<Book> Books { get; set; }   // Aggregation

        public Library(string name)
        {
            Name = name;
            Books = new List<Book>();
        }

        public void AddBook(Book book)
        {
            Books.Add(book);
        }
    }

    // ---------------- Composition ----------------
    public class Shelf
    {
        public string ShelfCode { get; set; }

        public Shelf(string code)
        {
            ShelfCode = code;
        }
    }

    public class LibrarySection
    {
        public string SectionName { get; set; }
        public List<Shelf> Shelves { get; set; }  // Composition

        public LibrarySection(string sectionName)
        {
            SectionName = sectionName;
            Shelves = new List<Shelf>();
        }

        public void AddShelf(string code)
        {
            Shelves.Add(new Shelf(code)); // Strong ownership
        }
    }

    public class ComposedLibrary
    {
        public string Name { get; set; }
        public List<LibrarySection> Sections { get; set; }

        public ComposedLibrary(string name)
        {
            Name = name;
            Sections = new List<LibrarySection>();
        }

        public void AddSection(string sectionName)
        {
            Sections.Add(new LibrarySection(sectionName)); // Strong ownership
        }
    }

    // ---------------- Main Program ----------------
    class Program
    {
        static void Main(string[] args)
        {
            // ---------- Association Example ----------
            Author author1 = new Author("J.K. Rowling");
            Book book1 = new Book("Harry Potter", author1);

            Console.WriteLine($"Book: {book1.Title}, Author: {book1.WrittenBy.Name}");

            // ---------- Aggregation Example ----------
            Library cityLibrary = new Library("City Library");
            cityLibrary.AddBook(book1);  // Book created outside and added to library

            Console.WriteLine($"\n{cityLibrary.Name} contains books:");
            foreach (var b in cityLibrary.Books)
            {
                Console.WriteLine($"- {b.Title} by {b.WrittenBy.Name}");
            }

            // ---------- Composition Example ----------
            ComposedLibrary composedLibrary = new ComposedLibrary("National Library");
            composedLibrary.AddSection("Fiction");
            composedLibrary.AddSection("Science");

            // Add shelves inside "Fiction" section
            composedLibrary.Sections[0].AddShelf("FIC-101");
            composedLibrary.Sections[0].AddShelf("FIC-102");

            Console.WriteLine($"\n{composedLibrary.Name} has sections:");
            foreach (var section in composedLibrary.Sections)
            {
                Console.WriteLine($"Section: {section.SectionName}");
                foreach (var shelf in section.Shelves)
                {
                    Console.WriteLine($"  - Shelf: {shelf.ShelfCode}");
                }
            }
        }
    }
}
