/*******************************************************************************

Project : CMP-5015Y - Programming 2, Assignment 2:
                      Off-line Movie Database in C++ (OMDB).

File    : main.cpp

Date    : Sunday 05th April 2020

Author  : Martin Siddons

Desc.   : Main function for calling MovieDatabase functions to complete tasks
            as outlined in the spec.

History : 05/04/2020 - Set up test harness.
          10/04/2020 - Added to test harness up to MovieDatabase toString.
          27/04/2020 - Completed Tasks 1 + 2.
          29/04/2020 - Completed Tasks 3-5.

*******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "MovieDatabase.h"

void test();

int main() {
//    test();
    // Task 1:
    // Read in the database from the file 'films.txt', using the relative path
    // “films.txt”, provided via BlackBoard.
    // I first create a master database to ensure all the movies are always held
    // in memory and give us something garenteed to be correct to copy from
    // for the other tasks below.
    MovieDatabase masterDB;
    masterDB.loadFromFile("films.txt");


    // Task 2:
    // Display the entire collection of movies, arranged in chronological
    // order. The movies must be displayed in the same format in which they
    // appear in films.txt.
    // Here I make a copy of the references in the master database that I
    // can then sort the list of pointers using the comparator detailed in
    // MovieDatabase and display the results. A shallow copy of masterDB is fine
    // since we only store a list of pointers inside it.
    {
        MovieDatabase chronoDB = masterDB;
        std::cout << "Sorting and displaying database by year:" << std::endl;
        std::sort(chronoDB.getMovies().begin(), chronoDB.getMovies().end(),
                  MovieDatabase::SortByYearAsc());
        std::cout << chronoDB << std::endl;
    }


    // Task 3:
    // Display the third longest Film-Noir.
    // Here we create a new DB from the result of searching masterDB for the
    // 'Film-Noir' genre. We then sort that new DB by reverse duration and
    // print out the third entry.
    {
        MovieDatabase noirDB = masterDB.filterByGenre("Film-Noir");
        std::sort(noirDB.getMovies().begin(), noirDB.getMovies().end(),
                  MovieDatabase::SortByDurationDes());
        Movie m = *noirDB.getMovies().at(2); // Get the third movie
        std::cout << "The third longest Film-Noir is " << m.getTitle() << "." <<
                  std::endl << std::endl;
    }


    // Task 4:
    // Display the eighth most recent UNRATED film.
    // Here we create another new db and populate it with the results of
    // searching masterDB for films listed with UNRATED as their cert. We then
    // sort this new db by year (newest first) and print out the eighth entry.
    {
        MovieDatabase unratedDB =
                masterDB.filterByCert(Movie::Cert::UNRATED);
        std::sort(unratedDB.getMovies().begin(), unratedDB.getMovies().end(),
                MovieDatabase::SortByYearDes());
        Movie m = *unratedDB.getMovies().at(7); // get the eighth movie.
        std::cout << "The eighth most recent UNRATED film is " <<
                m.getTitle() << "." << std::endl << std::endl;
    }


    // Task 5:
    // Display the film with the longest title.
    {
        MovieDatabase longestTitleDB = masterDB;
        std::sort(longestTitleDB.getMovies().begin(),
                longestTitleDB.getMovies().end(),
                MovieDatabase::SortByTitleLengthDes());
        Movie m = *longestTitleDB.getMovies().at(0); // get first movie.
        std::cout << "The film with the longest title is " << m.getTitle() <<
                "." << std::endl;
    }
    return EXIT_SUCCESS;
}

// Test harness.
void test() {
    // Create Movie object
    Movie m1("Indiana",1989,"PG-13","Action/Adventure/Fantasy",127,0);

    // Test Movie toString function
    std::cout << m1 << std::endl;

    // Test that loadFromFile doesn't load from non-existent file:
    MovieDatabase db1;
    db1.loadFromFile("notAFile.txt");

    // Test that loadFromFile opens the test data:
    db1.loadFromFile("test.txt");

    // Test MovieDatabase toString function:
    std::cout << std::endl << db1 << std::endl;

    // Test Copy Assignment by creating a copy of the current db:
    MovieDatabase db2 = db1;
    db1.loadFromFile("test.txt"); // load the data again into db1
    //  show pointers are correct by printing contents of both db1 and db2.
    std::cout << "Contents of db1: " << std::endl << db1 << std::endl;
    std::cout << "Contents of db2: " << std::endl << db2 << std::endl;
}

