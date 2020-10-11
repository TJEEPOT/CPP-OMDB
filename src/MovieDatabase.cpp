/*******************************************************************************

Project : CMP-5015Y - Programming 2, Assignment 2:
                      Offline Movie Database in C++ (OMDB).

File    : MovieDatabase.cpp

Date    : Sunday 05th April 2020

Author  : Martin Siddons

Desc.   : Functions for loading data from films.txt into a LinkedList of Movie
            objects and performing the tasks required via generic queries. See
            MovieDatabase.h for details on the MovieDatabase Class.

History : 05/04/2020 - Set up.
          10/04/2020 - toMovie and loadFromFile finalised.
          27/04/2020 - shared_ptr implementation.

*******************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

#include "MovieDatabase.h"

// Constructor Implementation:
MovieDatabase::MovieDatabase(){
    this->movies = std::vector<std::shared_ptr<Movie>>();
}

// >> Operator (toMovie) Overload Implementation:
inline std::istream &operator>>(std::istream &is, Movie &m){
    char c1, c2; // comma and quote mark
    std::string title, cert, genre;
    int year, duration;
    double rating;

    // As >> does not understand strings in general, we need to use getline.
    // Technically for the current data, Genre does not need a getline however
    // processing it using getline could save some headaches later if the format
    // of that field were to change.
    is >> c2; // ignore the first character (quote mark)
    std::getline(is, title, '\"' ); // get everything up to quote
    is >> c1 >> year >> c1 >> c2; // get the year and chars for comma and quote
    std::getline(is, cert, '\"'); // get the cert, drop quotes
    is >> c1 >> c2; // ignore the comma and quote
    std::getline(is, genre, '\"'); // get genre up to quote mark
    is >> c1 >> duration >> c1 >> rating; // get the last two, dropping commas

    if (c1 == ',' && c2 == '\"'){
        m = Movie(title, year, cert, genre, duration, rating);
    }else{
        is.clear(std::ios_base::failbit);
    }
    return is;
}

// File Reader Implementation:
void MovieDatabase::loadFromFile(const std::string &filename) {
    std::ifstream is(filename);

    if(is){
        Movie m("", 0, "","", 0,0);
        while(is >> m){
            auto sp = std::make_shared<Movie>(m);
            this->movies.push_back(sp);
        }
        is.close();
    }
    else{
        std::cerr << "Error: Unable to open input file " <<
        filename  << std::endl;
    }
}

// Filter Function Implementations:
MovieDatabase MovieDatabase::filterByGenre(const std::string& genre) {
    MovieDatabase db; // create a new MovieDatabase to store results in

    // Iterate through each smart pointer in the database, and for each movie,
    // if its genre contains the given genre string add it to the db above.
    for (const auto& mPtr : this->movies){
        Movie movie = *mPtr;
        if (movie.getGenre().find(genre) != std::string::npos){
            db.movies.push_back(mPtr);
        }
    }
    return db;
}

MovieDatabase MovieDatabase::filterByCert(const Movie::Cert cert) {
    MovieDatabase db; // storing search results here

    // As above, iterate through db and add matching entries to the new db.
    for (const auto& mPtr : this->movies){
        Movie movie = *mPtr;
        if (movie.getCert() == cert){
            db.movies.push_back(mPtr);
        }
    }
    return db;
}


// Sorting Function Implementations:
bool MovieDatabase::SortByYearAsc::operator()(const std::shared_ptr<Movie>& a,
        const std::shared_ptr<Movie>& b) const{
    return a->getYear() < b->getYear();
}

bool MovieDatabase::SortByDurationDes::operator()(const
        std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) const{
    return a->getDuration() > b->getDuration();
}

bool MovieDatabase::SortByYearDes::operator()(const
        std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) const{
    return a->getYear() > b->getYear();
}

bool MovieDatabase::SortByTitleLengthDes::operator()(const
        std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) const{
    return a->getTitle().size() > b->getTitle().size();
}

