/*******************************************************************************

Project : CMP-5015Y - Programming 2, Assignment 2:
                      Offline Movie Database in C++ (OMDB).

File    : Movie.h

Date    : Sunday 05th April 2020

Author  : Martin Siddons

Desc.   : Declarations for the Movie Class, Enum for Cert variable and
            Function Declarations. See comments on each
            definition for more information.

History : 05/04/2020 - Set up, completed constructor, enums, getters.

*******************************************************************************/

#ifndef OMDB_MOVIE_H
#define OMDB_MOVIE_H

#include <string>
#include <iomanip>

class Movie {
public:
    // All expected certs held here, with a CERT_UNDEFINED value which can be
    // assigned to any object read in that doesn't match those listed.
    enum class Cert {
        APPROVED, G, M, N_A, NOT_RATED, PASSED, PG, PG_13, R,
        TV_14, UNRATED, X, CERT_UNDEFINED
    };

private:
    Cert cert;
    std::string title, genre;
    int year, duration{};
    double rating{};

public:
    // Constructor Declaration:
    Movie(std::string title, int year, const std::string& cert,
          std::string genre, int duration, double rating);

    // Getter Declarations:
    inline std::string getTitle() const;

    inline int getYear() const;

    inline Cert getCert() const;

    inline std::string getGenre() const;

    inline int getDuration() const;

    inline double getRating() const;

    // Operator Overload Declarations:
    // << operator (toString):
    friend inline std::ostream &operator<<(std::ostream &os, const Movie &m);
};

    // Getters Implementation
    inline std::string Movie::getTitle() const {return title;}

    inline int Movie::getYear() const {return year;}

    inline Movie::Cert Movie::getCert() const {return cert;}

    inline std::string Movie::getGenre() const {return genre;}

    inline int Movie::getDuration() const {return duration;}

    inline double Movie::getRating() const {return rating;}

    // toString Implementation (<< Overloading):
    inline std::ostream& operator<<(std::ostream &os, const Movie &m){
        // Convert the enum value back into a string:
        std::string certStr;
        switch(m.cert) {
            case Movie::Cert::APPROVED:
                certStr = "APPROVED";
                break;
            case Movie::Cert::G:
                certStr = "G";
                break;
            case Movie::Cert::M:
                certStr = "M";
                break;
            case Movie::Cert::N_A:
                certStr = "N/A";
                break;
            case Movie::Cert::NOT_RATED:
                certStr = "NOT RATED";
                break;
            case Movie::Cert::PASSED:
                certStr = "PASSED";
                break;
            case Movie::Cert::PG:
                certStr = "PG";
                break;
            case Movie::Cert::PG_13:
                certStr = "PG-13";
                break;
            case Movie::Cert::R:
                certStr = "R";
                break;
            case Movie::Cert::TV_14:
                certStr = "TV-14";
                break;
            case Movie::Cert::UNRATED:
                certStr = "UNRATED";
                break;
            case Movie::Cert::X:
                certStr = "X";
                break;
            default:
                certStr = "Cert Undefined";
        }
        return os << "\""    << m.title    << "\","   << m.year
                  << ",\""   << certStr    << "\",\"" << m.genre
                  << "\","   << m.duration << ","     << m.rating;
    }

#endif //OMDB_MOVIE_H
