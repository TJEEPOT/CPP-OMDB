/*******************************************************************************

Project : CMP-5015Y - Programming 2, Assignment 2:
                      Offline Movie Database in C++ (OMDB).

File    : Movie.cpp

Date    : Sunday 05th April 2020

Author  : Martin Siddons

Desc.   : Functions for defining the Movie object which holds the necessary
            information for each Movie loaded by MovieDatabase.cpp. See Movie.h
            for details on the Movie Class.

History : 05/04/2020 - Set up, built constructor.

*******************************************************************************/

#include <iostream>

#include "Movie.h"

// Constructor Implementation:
Movie::Movie(std::string title, int year, const std::string& cert,
        std::string genre, int duration, double rating){
    // Assign Cert enum value from given string. I could probably do something
    // like convert the string to a hash and compare hashes which would be
    // more comparable to what Switch does, but it's likely not worth the time
    // it would take to implement.
    Movie::Cert certEnum;
    if (cert == "APPROVED")
        certEnum = Movie::Cert::APPROVED;
    else if (cert == "G")
        certEnum = Movie::Cert::G;
    else if (cert == "M")
        certEnum = Movie::Cert::M;
    else if (cert == "N/A")
        certEnum = Movie::Cert::N_A;
    else if (cert == "NOT RATED")
        certEnum = Movie::Cert::NOT_RATED;
    else if (cert == "PASSED")
        certEnum = Movie::Cert::PASSED;
    else if (cert == "PG")
        certEnum = Movie::Cert::PG;
    else if (cert == "PG-13")
        certEnum = Movie::Cert::PG_13;
    else if (cert == "R")
        certEnum = Movie::Cert::R;
    else if (cert == "TV-14")
        certEnum = Movie::Cert::TV_14;
    else if (cert == "UNRATED")
        certEnum =Movie::Cert::UNRATED;
    else if (cert == "X")
        certEnum = Movie::Cert::X;
    else certEnum = Movie::Cert::CERT_UNDEFINED;

    this->title = title;
    this->year = year;
    this->cert = certEnum;
    this->genre = genre;
    this->duration = duration;
    this->rating = rating;
}