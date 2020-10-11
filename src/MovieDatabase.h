/*******************************************************************************

Project : CMP-5015Y - Programming 2, Assignment 2:
                      Offline Movie Database in C++ (OMDB).

File    : MovieDatabase.h

Date    : Sunday 05th April 2020

Author  : Martin Siddons

Desc.   : Declarations for the MovieDatabase Class, Function Prototypes and
            operator overloads. See comments on each definition
            for more information.

History : 05/04/2020 - Set up.
          08/04/2020 - Sorting functions written.
          10/04/2020 - Copy Assignment and destrctor declared.
          27/04/2020 - Change toString to work with shared_ptr.

*******************************************************************************/

#ifndef OMDB_MOVIEDATABASE_H
#define OMDB_MOVIEDATABASE_H

#include <vector>
#include <memory>

#include "Movie.h"

class MovieDatabase {
private:
    // The Database stores a list of Shared Pointers to Movie objects. This
    // allows us to clone the initial database and perform different operations
    // on it without affecting or making copies of the underlying Movie
    // objects, but the Movies themselves will be safely destroyed once there
    // are no databases pointing at them.
    std::vector<std::shared_ptr<Movie>> movies;

public:
    // Constructor Declaration:
    MovieDatabase();

    // Getter Declaration:
    inline std::vector<std::shared_ptr<Movie>>& getMovies();

    // >> operator (toMovie) Overload Declaration:
    // The istream >> operator is overloaded when used against a movie object.
    // Here, a Movie is passed into the function and is populated with data from
    // the istream. If that data matches the format expected, the function
    // overwrites the Movie object with the gathered information. If not, the
    // istream is cleared.
    friend inline std::istream &operator>>(std::istream &is, Movie &m);

    // File Reader Function Declaration:
    // This function takes a given filename and checks that it exists in the
    // operating directory (\\cmake-build-debug) and if so, reads the file and
    // uses the above operator to overload the given Movie object. This function
    // then creates a new shared pointer to that object and pushes it to the
    // movies list. This continues until all possible movies have been read
    // from file.
    void loadFromFile(const std::string& filename);

    // << operator (toString) Declaration:
    // This function overloads the ostream << operator when used against a
    // MovieDatabase object. Here, the database is passed in and the function
    // iterates through each shared pointer in the movies list and calls the
    // toString function of the movie it's pointing to (as defined in Movie.h).
    friend inline std::ostream &operator<<
            (std::ostream &os, const MovieDatabase &db);

    // Filter Function Declaration:
    // This function takes a given genre, finds all matching movies in the
    // MovieDatabase it is called on, and return a new MovieDatabase with a
    // list of pointers to those movies.
    MovieDatabase filterByGenre(const std::string& genre);
    // This function takes a given Cert enum, finds all matching movies in the
    // db it's called on and returns a new MovieDatabase of pointers to those
    // movies.
    MovieDatabase filterByCert(const Movie::Cert cert);


    // Sorting Function Declarations (using C++11 function objec&ts) for use
    // with std::sort. Some here are placeholders for future operations.
    // Sort by Title Alphabetically:
    struct SortByTitleAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByTitleDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};

    // Sort by Title Length:
    struct SortByTitleLengthAsc {bool operator()(const
            std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) const;};
    struct SortByTitleLengthDes {bool operator()(const
            std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) const;};

    // Sort by Year:
    struct SortByYearAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByYearDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};

    // Sort by Cert:
    struct SortByCertAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByCertDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};

    // Sort by Genre:
    struct SortByGenreAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByGenreDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};

    // Sort by Duration:
    struct SortByDurationAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByDurationDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};

    // Sort by Rating:
    struct SortByRatingAsc {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
    struct SortByRatingDes {bool operator()(const std::shared_ptr<Movie>& a,
            const std::shared_ptr<Movie>& b) const;};
};

// Getter Implementations:
std::vector<std::shared_ptr<Movie>>& MovieDatabase::getMovies() {
    return movies;
}

// << operator (toString) Implementation:
inline std::ostream &operator<<
    (std::ostream &os, const MovieDatabase &db){
    for (auto &moviePtr : db.movies){
        os << *moviePtr << std::endl;
    }
    return os;
}

#endif //OMDB_MOVIEDATABASE_H
